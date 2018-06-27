#pragma once
#include "Vector2.h"

#define NEIGHBOUR_COUNT 8
struct Node
{
	Vector2 m_v2Pos;

	Node* m_Neighbours[NEIGHBOUR_COUNT];
	Node* m_pPrev;

	int m_nFScore;
	int m_nGSCore;
	int m_nHScore;

	int m_nCost;
	bool m_bBlocked;
};

