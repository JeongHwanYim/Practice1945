#pragma once

#include "SHPrimitive.h"

class SHBaseObject
{
public:
	SHBaseObject()
		: m_nGameId(GeneratedGameId())
		, m_nOwnerId(-1)
	{}

	SHBaseObject(int _nOwnerId)
		: m_nGameId(GeneratedGameId())
		, m_nOwnerId(_nOwnerId)
	{}

	virtual ~SHBaseObject() {}

	virtual void OnFrame(float fDeltaTime) {};

	int GetGameId() { return m_nGameId; }
	Point2D GetLocalPosition() { return m_Pos; }
	Vector2D GetLocalVector() { return m_Vec; }

	Point2D GetWorldPosition();
	Vector2D GetWorldVector();

	void SetLocalPosition(Point2D Pos) { m_Pos = Pos; }
	void SetLocalVector(Vector2D Vec) { m_Vec = Vec; }

	void SetWorldPosition(Point2D Pos);
	void SetWorldVector(Vector2D Vec);

	int	GetOwnerId() { return m_nOwnerId; }
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

	int m_nOwnerId;
};