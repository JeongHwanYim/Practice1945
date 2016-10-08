#pragma once

#include "SHPrimitive.h"

class SHBaseObject
{
public:
	SHBaseObject()
		: m_nGameId(GeneratedGameId())
	{
	}

	virtual ~SHBaseObject()
	{
	}

	virtual void OnFrame(float fDeltaTime) {};

	int GetGameId() { return m_nGameId; }
	Point2D GetPosition() { return m_Pos; }
	Vector2D GetVector() { return m_Vec; }
private:
	static int GeneratedGameId()
	{
		static int nGeneratedGameId = 1010;
		++nGeneratedGameId;
		return nGeneratedGameId;
	}
private:
	int m_nGameId;
	Point2D m_Pos;
	Vector2D m_Vec;
};