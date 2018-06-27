#pragma once
class Agent;

class BaseBehaviour
{
public:
	BaseBehaviour();
	virtual ~BaseBehaviour();

	virtual void Update(Agent* agent, float deltaTime) = 0;
};

