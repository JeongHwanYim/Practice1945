#include "stdafx.h"
#include "SHGameInterface.h"
#include "SHGame1945.h"
#include "SHObjectManager.h"
#include "SHCollisionManager.h"
#include "SHProjectile.h"
#include "SHPlayer.h"

SHGame1945* SHGame1945::Get()
{
	return (SHGame1945 *)gGameInterface->GetGame();
}

void SHGame1945::Initialize()
{
	ObjectManager = new SHObjectManager;
	CollisionManager = new SHCollisionManager;

	SHPlayer* pObject = ObjectManager->ConstructObject<SHPlayer>();
	pObject->SetLocalPosition(Point2D(200, 200));
	pObject->SetLocalVector(Vector2D(1, 0));
	pObject->SetSpeed(0);
	PlayerId = pObject->GetGameId();
}
void SHGame1945::Finalize()
{
	delete CollisionManager;
	delete ObjectManager;
}

void SHGame1945::OnFrame(float fDeltaTime)
{
	HDC = GetDC(gGameInterface->GetHWND());
	RECT crt;
	GetClientRect(gGameInterface->GetHWND(), &crt);
	Rectangle(HDC,crt.left, crt.top, crt.right, crt.bottom);
	SetGraphicsMode(HDC, GM_ADVANCED);

	ObjectManager->OnFrame(fDeltaTime);
	CollisionManager->OnFrame(fDeltaTime);

	XFORM xform = { 0.0f };
	xform.eDx = 0;
	xform.eDy = 0;
	xform.eM11 = (float)cos(0);
	xform.eM12 = (float)sin(0);
	xform.eM21 = (float)-sin(0);
	xform.eM22 = (float)cos(0);

	SetWorldTransform(SHGame1945::Get()->HDC, &xform);
	TCHAR PrintFrame[256];
	float Frames = 1.0f / fDeltaTime;
	swprintf_s(PrintFrame, TEXT("%2.0f"), Frames);
	TextOut(HDC, 0, 0, PrintFrame, wcslen(PrintFrame));

	ReleaseDC(gGameInterface->GetHWND(), HDC);
}

void SHGame1945::OnMousePressed(int nKey)
{
	if (nKey == MK_LBUTTON)
	{
		SHPlayer* pPlayer = (SHPlayer *)ObjectManager->FindObject(PlayerId);
		Point2D Pos = pPlayer->GetWorldPosition();
		
		int nMouseX = gGameInterface->GetMouseX();
		int nMouseY = gGameInterface->GetMouseY();
		
		float distX = nMouseX - Pos.X;
		float distY = nMouseY - Pos.Y;

		SH::Normalize2D(distX, distY);

		float theta = acos(distX);
		
		float fX = Pos.X + (distX * 80);
		float fY = Pos.Y + (distY * 80);

		pPlayer->SetWorldVector(Vector2D(distX, distY));

		SHProjectile* pObject = ObjectManager->ConstructObject<SHProjectile>(PlayerId);
		pObject->SetWorldPosition(Point2D(fX, fY));
		pObject->SetLocalVector(Vector2D(distX, distY));
//		pObject->SetAccel(Vector2D(1000, 1000), 10.0f);
		pObject->SetSpeed(200);
	}
}

void SHGame1945::OnKeyPressed(int nKey)
{
	if (nKey == VK_UP)
	{
		SHBaseObject* pObject = ObjectManager->FindObject(PlayerId);
		if (pObject)
		{
			Point2D Pos = pObject->GetWorldPosition();
			Pos.Y -= 10;
			pObject->SetWorldPosition(Pos);
		}
	}
	if (nKey == VK_DOWN)
	{
		SHBaseObject* pObject = ObjectManager->FindObject(PlayerId);
		if (pObject)
		{
			Point2D Pos = pObject->GetWorldPosition();
			Pos.Y += 10;
			pObject->SetWorldPosition(Pos);
		}
	}
	if (nKey == VK_LEFT)
	{
		SHBaseObject* pObject = ObjectManager->FindObject(PlayerId);
		if (pObject)
		{
			Point2D Pos = pObject->GetWorldPosition();
			Pos.X -= 10;
			pObject->SetWorldPosition(Pos);
		}
	}
	if (nKey == VK_RIGHT)
	{
		SHBaseObject* pObject = ObjectManager->FindObject(PlayerId);
		if (pObject)
		{
			Point2D Pos = pObject->GetWorldPosition();
			Pos.X += 10;
			pObject->SetWorldPosition(Pos);
		}
	}
}