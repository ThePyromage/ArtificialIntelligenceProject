#pragma once
#include "BaseBehaviour.h"
class SeekBehaviour :
	public BaseBehaviour
{
public:
	SeekBehaviour();
	virtual ~SeekBehaviour();

	eBehaviourResult Update(GameObject* pAgent, float deltaTime);
};

