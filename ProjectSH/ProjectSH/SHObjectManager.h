#pragma once

#include <map>
#include <vector>
#include "SHBaseObject.h"

class SHObjectManager
{
public:
	void	OnFrame(float fDeltaTime);

	template<typename T>
	SHBaseObject* ConstructObject();
	SHBaseObject* FindObject(int nGameId);
	void DestructObject(int nGameId);

private:
	std::map< int, SHBaseObject* > m_pObjectMap;
	std::vector< SHBaseObject* > m_pDeleteObjectList;
};

/////////////////////////////////////////////////////

template<typename T>
SHBaseObject* SHObjectManager::ConstructObject()
{
	SHBaseObject* pObject = new T;
	m_pObjectMap.insert(std::make_pair(pObject->GetGameId(), pObject));

	return pObject;
}

// ��ȭ
// �ʻ���