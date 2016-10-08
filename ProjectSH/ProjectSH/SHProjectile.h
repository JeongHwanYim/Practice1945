#pragma once

#include "SHBaseObject.h"

class SHProjectile : public SHBaseObject
{
public:
	SHProjectile() :
		SHBaseObject(), m_fSpeed(0), m_fAdjTime(0)
	{

	}

	virtual ~SHProjectile() {}

	virtual void OnFrame(float fDeltaTime);

	void SetAccel(Vector2D TotalAccel, float fAdjTime)
	{
		Vector2D Accel(TotalAccel.X / fAdjTime, TotalAccel.Y / fAdjTime);
		m_Accel = Accel;
		m_fAdjTime = fAdjTime;
	}

private:
	Vector2D	m_Accel;
	float		m_fAdjTime;

	float		m_fSpeed;
};