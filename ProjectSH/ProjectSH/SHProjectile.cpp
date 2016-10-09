#include "stdafx.h"
#include "SHProjectile.h"
#include "SHGame1945.h"
#include <cmath>

void SHProjectile::OnFrame(float fDeltaTime)
{
	if (m_fAdjTime > 0.0f)
	{
		Vector2D Vec = GetLocalVector();

		float fAdjX = m_Accel.X * fDeltaTime;
		float fAdjY = m_Accel.Y * fDeltaTime;

		m_fAdjTime -= fDeltaTime;

		Vec.X += fAdjX;
		Vec.Y += fAdjY;

		m_fSpeed += SH::Normalize2D(fAdjX, fAdjY);
		SH::Normalize2D(Vec.X, Vec.Y);

		SetLocalVector(Vec);
	}

	{
		Point2D Pos = GetWorldPosition();
		Vector2D Vec = GetWorldVector();

		Pos.X += (Vec.X * m_fSpeed * fDeltaTime);
		Pos.Y += (Vec.Y * m_fSpeed * fDeltaTime);

		SetWorldPosition(Pos);
	}
	
	{
		Point2D Pos = GetWorldPosition();
		const double M_PI = _STD acos(-1);
		XFORM xform = { 0.0f, };
		xform.eDx = Pos.X;
		xform.eDy = Pos.Y;
		xform.eM11 = (float)cos(0);
		xform.eM12 = (float)sin(0);
		xform.eM21 = (float)-sin(0);
		xform.eM22 = (float)cos(0);

		SetWorldTransform(SHGame1945::Get()->HDC, &xform);

		Ellipse(SHGame1945::Get()->HDC, -10, -10, +10, +10);
	}
}