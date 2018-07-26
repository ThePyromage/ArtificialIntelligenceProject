#include "SeekBehaviour.h"
#include <Input.h>
#include "Vector2.h"
#include "Agent.h"


SeekBehaviour::SeekBehaviour() : BaseBehaviour()
{
}


SeekBehaviour::~SeekBehaviour()
{
}

eBehaviourResult SeekBehaviour::Update(GameObject * pAgent, float deltaTime)
{
	aie::Input* pInput = aie::Input::getInstance();
	Vector2 v2MousePos;

	v2MousePos.x = (float)pInput->getMouseX();
	v2MousePos.y = (float)pInput->getMouseY();
	
	Vector2 v2Dir = v2MousePos - pAgent->GetPosition();
	v2Dir.normalise();
	v2Dir = v2Dir * pAgent->GetMaxSpeed();


	Vector2 v2Force = v2Dir - pAgent->GetVelocity();

	pAgent->SetVelocity(pAgent->GetVelocity() + v2Force * deltaTime);

	return eBehaviourResult::SUCCESS;
}
