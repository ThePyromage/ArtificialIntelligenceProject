#pragma once
#include "Agent.h"

class Enemy :
	public Agent
{
public:
	Enemy(aie::Texture* pTexture, Vector2 v2pos, float fRotRadian);
	~Enemy();
};

