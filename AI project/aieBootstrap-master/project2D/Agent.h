#pragma once
#include "GameObject.h"
#include <vector>

class FiniteStateMachine;

class Grid;

class FleeState;
class SeekState;

class Agent :
	public GameObject
{
public:
	Agent(aie::Texture* pTexture, Vector2 v2pos, float fRotRadian, Grid* grid);
	virtual ~Agent();

	virtual void Update(float deltaTime);
	virtual void Draw(aie::Renderer2D* m_2dRenderer);

protected:
	FleeState * m_pFleeState;
	SeekState* m_pSeekState;
	FiniteStateMachine * m_pStateMachine;
	Grid* m_pGrid;

	std::vector<Vector2> m_path;
};

