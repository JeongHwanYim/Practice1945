#pragma once

#include "SHBaseObject.h"

class SHPlayer : public SHBaseObject
{
public:
	SHPlayer() :
		SHBaseObject(), m_fSpeed(0)
	{

	}

	virtual ~SHPlayer() {}

	virtual void OnFrame(float fDeltaTime);

	void SetSpeed(float fSpeed) { m_fSpeed = fSpeed; }
private:
	float		m_fSpeed;
};