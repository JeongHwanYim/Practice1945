#pragma once

#include "SHGame.h"

class SHObjectManager;
class SHCollisionManager;

class SHGame1945 : public SHGame
{
public:
	void Initialize();
	void Finalize();

	virtual void OnFrame(float fDeltaTime);

	static SHGame1945* Get();
public:
	SHObjectManager*	ObjectManager;
	SHCollisionManager* CollisionManager;
};