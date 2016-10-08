#include "stdafx.h"
#include "SHGameInterface.h"
#include "SHGame1945.h"
#include "SHObjectManager.h"
#include "SHCollisionManager.h"

SHGame1945* SHGame1945::Get()
{
	return (SHGame1945 *)gGameInterface->GetGame();
}

void SHGame1945::Initialize()
{
	ObjectManager = new SHObjectManager;
	CollisionManager = new SHCollisionManager;
}
void SHGame1945::Finalize()
{
	delete CollisionManager;
	delete ObjectManager;
}

void SHGame1945::OnFrame(float fDeltaTime)
{
	ObjectManager->OnFrame(fDeltaTime);
	CollisionManager->OnFrame(fDeltaTime);
}