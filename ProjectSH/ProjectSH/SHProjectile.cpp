#include "stdafx.h"
#include "SHProjectile.h"
#include "SHGame1945.h"

void SHProjectile::OnFrame(float fDeltaTime)
{
	if (m_fAdjTime >= 0.0f)
	{
		Vector2D Vec = GetVector();

		float fAdjX = m_Accel.X * fDeltaTime;
		float fAdjY = m_Accel.Y * fDeltaTime;

		m_fAdjTime -= fDeltaTime;

		Vec.X += fAdjX;
		Vec.Y += fAdjY;

		m_fSpeed += SH::Normalize2D(Vec.X, Vec.Y);

		SetVector(Vec);
	}

	{
		Point2D Pos = GetPosition();
		Vector2D Vec = GetVector();

		Pos.X += (int)(Vec.X * m_fSpeed);
		Pos.Y += (int)(Vec.Y * m_fSpeed);

		SetPosition(Pos);
	}

	{
		Point2D Pos = GetPosition();
		Ellipse(SHGame1945::Get()->HDC, Pos.X - 10, Pos.Y - 10, Pos.X + 10, Pos.Y + 30);
	}
}