#include "stdafx.h"
#include "SHObjectManager.h"

void SHObjectManager::OnFrame(float fDeltaTime)
{
	for (auto Itr : m_pObjectMap)
	{
		auto pObject = Itr.second;
		if (pObject)
		{
			pObject->OnFrame(fDeltaTime);
		}
	}

	for (auto pDeleteObject : m_pDeleteObjectList)
	{
		delete pDeleteObject;
		pDeleteObject = nullptr;
	}
	m_pDeleteObjectList.clear();
}

SHBaseObject* SHObjectManager::FindObject(int nGameId)
{
	return m_pObjectMap[nGameId];
}

void SHObjectManager::DestructObject(int nGameId)
{
	SHBaseObject* pObject = m_pObjectMap[nGameId];
	if (pObject != nullptr)
	{
		m_pObjectMap.erase(nGameId);
		m_pDeleteObjectList.push_back(pObject);
	}
}