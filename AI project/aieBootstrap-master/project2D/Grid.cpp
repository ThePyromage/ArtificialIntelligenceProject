#include "Grid.h"
#include "Node.h"
#include <stdlib.h>

#define GRID_SPACING 2.0f
#define OFFSET_X 100.0f
#define OFFSET_Y 100.0f
#define GSCORE_COST 1

void Swap(Node* xp, Node* yp)
{
	Node* temp = xp;
	xp = yp;
	yp = temp;
}

void BubbleSort(std::vector<Node*> list)
{
	bool swapped;
	for (int i = 0; i < list.size() - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < list.size() - i - 1; j++)
		{
			if (list[j]->m_nFScore > list[j + 1]->m_nFScore)
			{
				Swap(list[j], list[j + 1]);
				swapped = true;
			}
		}
		if (!swapped)
		{
			break;
		}
	}
}

Grid::Grid()
{
	for (int x = 0; x < GRID_X; ++x)
	{
		for (int y = 0; y < GRID_Y; ++y)
		{
			m_Nodes[x][y] = new Node();
			m_Nodes[x][y]->m_v2Pos.x = OFFSET_X + NODE_SIZE * x;
			m_Nodes[x][y]->m_v2Pos.y = OFFSET_Y + NODE_SIZE * y;
		}
	}

	for (int x = 0; x < GRID_X; ++x)
	{
		for (int y = 0; y < GRID_Y; ++y)
		{
			m_Nodes[x][y]->m_Neighbours[0] = nullptr;
			m_Nodes[x][y]->m_Neighbours[1] = nullptr;
			m_Nodes[x][y]->m_Neighbours[2] = nullptr;
			m_Nodes[x][y]->m_Neighbours[3] = nullptr;
			m_Nodes[x][y]->m_Neighbours[4] = nullptr;
			m_Nodes[x][y]->m_Neighbours[5] = nullptr;
			m_Nodes[x][y]->m_Neighbours[6] = nullptr;
			m_Nodes[x][y]->m_Neighbours[7] = nullptr;

			if (y < GRID_Y - 1)
				m_Nodes[x][y]->m_Neighbours[0] = m_Nodes[x][y + 1];

			if (y < GRID_Y - 1 && x < GRID_X - 1)
				m_Nodes[x][y]->m_Neighbours[1] = m_Nodes[x + 1][y + 1];
			
			if (x < GRID_X - 1)
				m_Nodes[x][y]->m_Neighbours[2] = m_Nodes[x + 1][y];

			if (y > 0 && x < GRID_X - 1)
				m_Nodes[x][y]->m_Neighbours[3] = m_Nodes[x + 1][y - 1];
			
			if (y > 0)
				m_Nodes[x][y]->m_Neighbours[4] = m_Nodes[x][y - 1];

			if (y > 0 && x > 0)
				m_Nodes[x][y]->m_Neighbours[5] = m_Nodes[x - 1][y - 1];
			
			if (x > 0)
				m_Nodes[x][y]->m_Neighbours[6] = m_Nodes[x - 1][y];

			if (y < GRID_Y - 1 && x > 0)
				m_Nodes[x][y]->m_Neighbours[7] = m_Nodes[x - 1][y + 1];
		}
	}

	for (int i = 0; i < 100; ++i)
	{
		int x = rand() % GRID_X;
		int y = rand() % GRID_Y;
		m_Nodes[x][y]->m_bBlocked = true;
	}
}


Grid::~Grid()
{
	for (int x = 0; x < GRID_X; ++x)
	{
		for (int y = 0; y < GRID_Y; ++y)
		{
			delete m_Nodes[x][y];
		}
	}
}

std::vector<Vector2> Grid::GetPath(Vector2 v2Start, Vector2 v2End, bool AStar)
{
	std::vector<Node*> openList;
	std::vector<Node*> closedList;
	Node* startNode = GetNodeByPos(v2Start);
	Node* endNode = GetNodeByPos(v2End);
	std::vector<Vector2> path;

	if (startNode != nullptr && endNode != nullptr && !startNode->m_bBlocked && !endNode->m_bBlocked)
	{
		Node* currentNode;
		startNode->m_pPrev = nullptr;
		openList.push_back(startNode);
		while (!openList.empty())
		{
			BubbleSort(openList);
			currentNode = openList.front();

			if (currentNode == endNode)
			{
				break;
			}

			openList.erase(openList.begin());
			closedList.push_back(currentNode);

			for (int i = 0; i < NEIGHBOUR_COUNT; i++)
			{
				if (currentNode->m_Neighbours[i] != nullptr)
				{
					if (!currentNode->m_Neighbours[i]->m_bBlocked)
					{
						if (std::find(closedList.begin(), closedList.end(), currentNode->m_Neighbours[i]) == closedList.end())
						{
							if (std::find(openList.begin(), openList.end(), currentNode->m_Neighbours[i]) == openList.end())
							{
								openList.push_back(currentNode->m_Neighbours[i]);
								currentNode->m_Neighbours[i]->m_nGScore = currentNode->m_nGScore + GSCORE_COST;
								currentNode->m_Neighbours[i]->m_pPrev = currentNode;
							}
							else
							{
								if (currentNode->m_Neighbours[i]->m_nGScore > (currentNode->m_nGScore + GSCORE_COST))
								{
									currentNode->m_Neighbours[i]->m_nGScore = currentNode->m_nGScore + GSCORE_COST;
									currentNode->m_Neighbours[i]->m_pPrev = currentNode;
								}
							}
						}
					}
				}
			}
		}

		currentNode = endNode;
		while (currentNode != nullptr)
		{
			path.push_back(currentNode->m_v2Pos);
			currentNode = currentNode->m_pPrev;
		}
		printf("valid path\n");
		return path;
	}
	else
	{
		printf("invalid path\n");
		return path;
	}
}

Node* Grid::GetNodeByPos(Vector2 v2Pos)
{
	int xPos = (int)((v2Pos.x - OFFSET_X) / (NODE_SIZE + GRID_SPACING));
	int yPos = (int)((v2Pos.y - OFFSET_Y) / (NODE_SIZE + GRID_SPACING));

	if (xPos >= 0 && yPos >= 0 && xPos < GRID_X && yPos < GRID_Y)
	{
		Node* result;
		result = m_Nodes[xPos][yPos];

		return result;
	}
	else
	{
		return nullptr;
	}
}

void Grid::Draw(aie::Renderer2D * pRenderer)
{
	for (int x = 0; x < GRID_X; ++x)
	{
		for (int y = 0; y < GRID_Y; ++y)
		{
			if(!m_Nodes[x][y]->m_bBlocked)
				pRenderer->drawBox(m_Nodes[x][y]->m_v2Pos.x, m_Nodes[x][y]->m_v2Pos.y, NODE_SIZE - GRID_SPACING, NODE_SIZE - GRID_SPACING);
		}
	}
}
