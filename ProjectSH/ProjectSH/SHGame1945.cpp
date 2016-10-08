#include "stdafx.h"
#include "SHGameInterface.h"
#include "SHGame1945.h"
#include "SHObjectManager.h"
#include "SHCollisionManager.h"
#include "SHProjectile.h"

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
	InvalidateRect(gGameInterface->GetHWND(), NULL, FALSE);

	HDC = GetDC(gGameInterface->GetHWND());
	RECT crt;
	GetClientRect(gGameInterface->GetHWND(), &crt);
	Rectangle(HDC,crt.left, crt.top, crt.right, crt.bottom);

	ObjectManager->OnFrame(fDeltaTime);
	CollisionManager->OnFrame(fDeltaTime);

	ReleaseDC(gGameInterface->GetHWND(), HDC);
}

void SHGame1945::OnMousePressed(int nKey)
{
	if (nKey == MK_LBUTTON)
	{
		SHProjectile* pObject = ObjectManager->ConstructObject<SHProjectile>();
		pObject->SetPosition(Point2D(400, 300));
		pObject->SetVector(Vector2D(1, 0));
		pObject->SetAccel(Vector2D(-1, 5), 3.0f);
	}
}