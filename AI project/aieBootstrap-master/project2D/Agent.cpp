#include "Agent.h"
#include "Grid.h"
#include "FiniteStateMachine.h"
#include "FleeState.h"
#include "SeekState.h"
#include <Input.h>
#include <iostream>


Agent::Agent(aie::Texture* pTexture, Vector2 v2pos, float fRotRadian, Grid* grid) : GameObject(pTexture, v2pos, fRotRadian)
{
	m_fMaxSpeed = 1000.0f;
	m_pGrid = grid;
	m_path = grid->GetPath(Vector2(200, 200), Vector2(400, 400), true);
	m_pStateMachine = new FiniteStateMachine;
	m_pFleeState = new FleeState;
	m_pSeekState = new SeekState;
	m_pStateMachine->addState(m_pFleeState);
	m_pStateMachine->addState(m_pSeekState);
}


Agent::~Agent()
{
	delete m_pStateMachine;
	delete m_pFleeState;
	delete m_pSeekState;
}

void Agent::Update(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();
	m_pStateMachine->Update(this, deltaTime);

	int mouseX = input->getMouseX();
	int mouseY = input->getMouseY();

	Vector2 mousePos;
	mousePos.x = (float)mouseX;
	mousePos.y = (float)mouseY;

	if (input->isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_LEFT))
	{
		m_path = m_pGrid->GetPath(this->GetPosition(), mousePos, true);
		std::cout << "Mouse X: " << mousePos.x << ", Mouse Y: " << mousePos.y << std::endl;
	}

	if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		m_pStateMachine->setCurrentState(m_pSeekState);
	}

	if (input->isKeyDown(aie::INPUT_KEY_F))
	{
		m_pStateMachine->setCurrentState(m_pFleeState);
	}

	if (input->isKeyDown(aie::INPUT_KEY_N))
	{
		m_pStateMachine->setCurrentState(nullptr);
	}

	if (input->isKeyDown(aie::INPUT_KEY_BACKSPACE))
	{
		m_v2Velocity.x = 0.0f;
		m_v2Velocity.y = 0.0f;
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