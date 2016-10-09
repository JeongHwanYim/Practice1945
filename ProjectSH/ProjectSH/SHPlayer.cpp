#include "stdafx.h"
#include "SHPlayer.h"
#include "SHGame1945.h"

void SHPlayer::OnFrame(float fDeltaTime)
{
	{
		Point2D Pos = GetWorldPosition();
		const double M_PI = _STD acos(-1);

		XFORM xform = { 0.0f, };
		xform.eDx = Pos.X;
		xform.eDy = Pos.Y;
		xform.eM11 = 1;
		xform.eM12 = 0;
		xform.eM21 = 0;
		xform.eM22 = 1;

		SetWorldTransform(SHGame1945::Get()->HDC, &xform);

		Rectangle(SHGame1945::Get()->HDC, -50, -30, +50, +30);
	}

	{
		Point2D Pos = GetWorldPosition();
		const double M_PI = _STD acos(-1);

		int nMouseX = gGameInterface->GetMouseX();
		int nMouseY = gGameInterface->GetMouseY();

		if (Pos.X == nMouseX && Pos.Y == nMouseY)
		{
		}
		else
		{
			float distX = nMouseX - Pos.X;
			float distY = nMouseY - Pos.Y;

			SH::Normalize2D(distX, distY);

			float theta = acos(distX);

			XFORM xform = { 0.0f, };
			xform.eDx = Pos.X;
			xform.eDy = Pos.Y;

			xform.eM11 = distX;
			xform.eM12 = distY;
			xform.eM21 = -distY;
			xform.eM22 = distX;

			SetWorldTransform(SHGame1945::Get()->HDC, &xform);

			Rectangle(SHGame1945::Get()->HDC, 0, -10, +80, +10);
		}
	}
}
