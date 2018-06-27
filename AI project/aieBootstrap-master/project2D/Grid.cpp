#include "Grid.h"
#include "Node.h"
#include <stdlib.h>

#define GRID_SPACING 2.0f
#define OFFSET_X 100.0f
#define OFFSET_Y 100.0f

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
	return std::vector<Vector2>();
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
