#pragma once

#include <map>
#include <vector>
#include "SHBaseObject.h"

class SHObjectManager
{
public:
	void	OnFrame(float fDeltaTime);

	template<typename T, typename... Args>
	T* ConstructObject(Args&&... args);
	SHBaseObject* FindObject(int nGameId);
	void DestructObject(int nGameId);

private:
	std::map< int, SHBaseObject* > m_pObjectMap;
	std::vector< SHBaseObject* > m_pDeleteObjectList;
};

/////////////////////////////////////////////////////

template<typename T, typename... Args>
inline T* SHObjectManager::ConstructObject(Args&&... args)
{
	T* pObject = new T(args...);
	m_pObjectMap.insert(std::make_pair(pObject->GetGameId(), pObject));

	return pObject;
}
// 강화
// 필살기류