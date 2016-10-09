#pragma once

#include "SHBaseObject.h"

class SHProjectile : public SHBaseObject
{
public:
	SHProjectile(int nShooterId) :
		SHBaseObject(), m_fSpeed(0), m_fAdjTime(0), m_nShooterId(nShooterId)
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
	void SetSpeed(float fSpeed) { m_fSpeed = fSpeed; }
private:
	Vector2D	m_Accel;
	float		m_fAdjTime;

	float		m_fSpeed;

	int			m_nShooterId;
};