#pragma once
#include "Renderer2D.h"
#include <vector>
#include "Vector2.h"

struct Node;

#define GRID_X 25
#define GRID_Y 25
#define NODE_SIZE 22.0f


class Grid
{
public:
	Grid();
	~Grid();

	std::vector<Vector2> GetPath(Vector2 v2Start, Vector2 v2End, bool AStar);
	Node* GetNodeByPos(Vector2 v2Pos);

	void Draw(aie::Renderer2D* pRenderer);

	Node* m_Nodes[GRID_X][GRID_Y];
	std::vector<Node*> m__OpenList;

};

