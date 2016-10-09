#include "stdafx.h"
#include "SHGame1945.h"
#include "SHBaseObject.h"
#include "SHObjectManager.h"

Point2D SHBaseObject::GetWorldPosition()
{
	Point2D Pos = GetLocalPosition();
	
	SHBaseObject* pOwner = SHGame1945::Get()->ObjectManager->FindObject(GetOwnerId());
	if (pOwner)
	{
		SH::Translation(Pos, Vector2D(), pOwner->GetWorldPosition());
	}
	
	return Pos;
}

Vector2D SHBaseObject::GetWorldVector()
{
	Vector2D Vec = GetLocalVector();

	SHBaseObject* pOwner = SHGame1945::Get()->ObjectManager->FindObject(GetOwnerId());
	if (pOwner)
	{
		SH::Rotation(Point2D(), Vec, pOwner->GetWorldVector());
	}

	return Vec;
}


void SHBaseObject::SetWorldPosition(Point2D Pos)
{
	Point2D LocalPos = Pos;

	SHBaseObject* pOwner = SHGame1945::Get()->ObjectManager->FindObject(GetOwnerId());
	if (pOwner)
	{
		SH::Translation(LocalPos, Vector2D(), -pOwner->GetWorldPosition());
	}

	SetLocalPosition(LocalPos);
}

void SHBaseObject::SetWorldVector(Vector2D Vec)
{
	Vector2D LocalVec = Vec;

	SHBaseObject* pOwner = SHGame1945::Get()->ObjectManager->FindObject(GetOwnerId());
	if (pOwner)
	{
		SH::Rotation(Point2D(), LocalVec, -pOwner->GetWorldVector());
	}

	SetLocalVector(LocalVec);
}