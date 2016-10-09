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

	virtual void OnMousePressed(int nKey);
	virtual void OnKeyPressed(int nKey);
public:
	SHObjectManager*	ObjectManager;
	SHCollisionManager* CollisionManager;
	HDC					HDC;

	INT					PlayerId;
};