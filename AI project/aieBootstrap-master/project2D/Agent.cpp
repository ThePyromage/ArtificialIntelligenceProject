#include "Agent.h"



Agent::Agent(aie::Texture* pTexture, Vector2 v2pos, float fRotRadian) : GameObject(pTexture, v2pos, fRotRadian)
{
	m_fMaxSpeed = 500.0f;
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
	m_2dRenderer->drawSpriteTransformed3x3(m_Sprite, (float*)m_GlobalTransform);
}

Vector2 Agent::GetVelocity()
{
	return m_v2Velocity;
}

void Agent::SetVelocity(Vector2 v2Velocity)
{
	m_v2Velocity = v2Velocity;
}

float Agent::GetMaxSpeed()
{
	return m_fMaxSpeed;
}

void Agent::AddBehaviour(BaseBehaviour * pBehaviour)
{
	m_BehaviourList.push_back(pBehaviour);
}
