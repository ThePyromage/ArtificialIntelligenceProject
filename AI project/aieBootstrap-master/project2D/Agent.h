#pragma once
#include "GameObject.h"
#include <vector>
#include "BaseBehaviour.h"

class Grid;

class Agent :
	public GameObject
{
public:
	Agent(aie::Texture* pTexture, Vector2 v2pos, float fRotRadian, Grid* grid);
	virtual ~Agent();

	virtual void Update(float deltaTime);
	virtual void Draw(aie::Renderer2D* m_2dRenderer);

	Vector2 GetVelocity();
	void SetVelocity(Vector2 v2Velocity);
	float GetMaxSpeed();

	void AddBehaviour(BaseBehaviour* pBehaviour);

protected:
	Vector2 m_v2Velocity;
	float m_fMaxSpeed;
	Grid* m_pGrid;

	std::vector<Vector2> m_path;

	std::vector<BaseBehaviour*> m_BehaviourList;

};

