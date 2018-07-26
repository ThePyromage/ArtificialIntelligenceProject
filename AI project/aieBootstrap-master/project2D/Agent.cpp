#include "Agent.h"
#include "Grid.h"



Agent::Agent(aie::Texture* pTexture, Vector2 v2pos, float fRotRadian, Grid* grid) : GameObject(pTexture, v2pos, fRotRadian)
{
	m_fMaxSpeed = 1000.0f;
	m_pGrid = grid;
	m_path = grid->GetPath(Vector2(200, 200), Vector2(400, 400), true);
}


Agent::~Agent()
{
}

void Agent::Update(float deltaTime)
{
	for (int i = 0; i < m_BehaviourList.size(); ++i)
	{
		m_BehaviourList[i]->Update(this, deltaTime);
	}

	Vector2 v2Pos = GetPosition();
	v2Pos = v2Pos + m_v2Velocity * deltaTime;
	SetPosition(v2Pos);

	this->updateGlobalTransform();
}

void Agent::Draw(aie::Renderer2D * m_2dRenderer)
{
	for (int i = 0; i < m_path.size(); ++i)
	{
		m_2dRenderer->setRenderColour(1, 0, 0, 1);
		m_2dRenderer->drawCircle(m_path[i].x, m_path[i].y, NODE_SIZE/2);
		m_2dRenderer->setRenderColour(1, 1, 1, 1);
	}
	m_2dRenderer->drawSpriteTransformed3x3(m_Sprite, (float*)m_GlobalTransform);
}



void Agent::AddBehaviour(BaseBehaviour * pBehaviour)
{
	m_BehaviourList.push_back(pBehaviour);
}
