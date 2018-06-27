#include "Vector2.h"
#include "Matrix3.h"
#include "Renderer2D.h"
#include "Texture.h"

#pragma once
class GameObject
{
public:
	GameObject(aie::Texture* pTexture, Vector2 v2pos, float fRotRadian);
	virtual ~GameObject();

	virtual void Update(float deltaTime);
	virtual void Draw(aie::Renderer2D* m_2dRenderer);

	virtual void updateGlobalTransform();

	void SetPosition(Vector2 v2Pos);
	Vector2 GetPosition();

	void SetRotation(float fRotRadian);
	float GetRotation();

protected:
	Matrix3 m_LocalTransform;
	Matrix3 m_GlobalTransform;
	float m_fRotation;

	GameObject* m_parent;

	aie::Texture* m_Sprite;
};

