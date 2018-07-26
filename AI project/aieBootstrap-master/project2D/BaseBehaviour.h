#pragma once

enum eBehaviourResult
{
	SUCCESS,
	FAILURE,
	RUNNING
};

class GameObject;

class BaseBehaviour
{
public:
	BaseBehaviour();
	virtual ~BaseBehaviour();

	virtual eBehaviourResult Update(GameObject* agent, float deltaTime) = 0;
};

