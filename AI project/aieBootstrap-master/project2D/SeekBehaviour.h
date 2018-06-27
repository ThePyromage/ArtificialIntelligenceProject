#pragma once
#include "BaseBehaviour.h"
class SeekBehaviour :
	public BaseBehaviour
{
public:
	SeekBehaviour();
	virtual ~SeekBehaviour();

	void Update(Agent* pAgent, float deltaTime);
};

