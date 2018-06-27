#include "GameObject.h"



GameObject::GameObject(aie::Texture* pTexture, Vector2 v2pos, float fRotRadian)
{
	m_Sprite = pTexture;
	SetPosition(v2pos);
	SetRotation(fRotRadian);
	m_parent = nullptr;
}


GameObject::~GameObject()
{
}

void GameObject::Update(float deltaTime)
{
}

void GameObject::Draw(aie::Renderer2D * m_2dRenderer)
{
}

void GameObject::updateGlobalTransform()
{
	if (m_parent != nullptr)
		m_GlobalTransform = m_parent->m_GlobalTransform * m_LocalTransform;
	else
		m_GlobalTransform = m_LocalTransform;
}

void GameObject::SetPosition(Vector2 v2Pos)
{
	m_LocalTransform.m[6] = v2Pos.x;
	m_LocalTransform.m[7] = v2Pos.y;
}

Vector2 GameObject::GetPosition()
{
	Vector2 result;

	result.x = m_LocalTransform.m[6];
	result.y = m_LocalTransform.m[7];

	return result;
}

void GameObject::SetRotation(float fRotRadian)
{
	m_fRotation = fRotRadian;
	m_LocalTransform.setRotateZ(fRotRadian);
}

float GameObject::GetRotation()
{
	return m_fRotation;
}
