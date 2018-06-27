#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <vector>

class Agent;
class SeekBehaviour;
class Grid;

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;

	float m_cameraX, m_cameraY;
	float m_timer;

	Agent* m_pPlayer;
	SeekBehaviour* m_SeekBehaviour;
	Grid* m_pGrid;
};