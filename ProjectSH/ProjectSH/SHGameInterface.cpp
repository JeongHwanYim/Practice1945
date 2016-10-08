#include "stdafx.h"
#include "SHGameInterface.h"
#include "SHGame.h"

#include "SHGame1945.h"

SHGameInterface* gGameInterface = new SHGameInterface;
const int TARGET_FRAME = 60;

void SHGameInterface::Initialize()
{
	m_XPos = 0, m_YPos = 0;
	m_nPrev = GetTickCount64();
	m_fTargetDeltaTime = 1000 / TARGET_FRAME;

	m_BindKey = {
		VK_LEFT,
		VK_UP,
		VK_RIGHT,
		VK_DOWN,
	};

	m_pGame = new SHGame1945;
}

void SHGameInterface::Finalize()
{
	delete m_pGame;
	m_pGame = nullptr;
}

void SHGameInterface::Run()
{
	KeyHandle();

	ULONGLONG nCur = GetTickCount64();

	float fElapsedTime = (nCur - m_nPrev) / 1000;
	if ( fElapsedTime >= m_fTargetDeltaTime)
	{
		m_pGame->OnFrame(fElapsedTime);

		m_nPrev = nCur;
	}
}

void SHGameInterface::OnMouseMoved(int xPos, int yPos)
{
	m_XPos = xPos;
	m_YPos = yPos;
}

void SHGameInterface::OnMousePressed(int nKey)
{
	m_MouseMap[nKey] = true;

	m_pGame->OnMousePressed(nKey);
}

void SHGameInterface::OnMouseReleased(int nKey)
{
	m_MouseMap[nKey] = false;

	m_pGame->OnMouseReleased(nKey);
}

void SHGameInterface::OnKeyPressed(int nKey)
{
	m_KeyMap[nKey] = true;

	m_pGame->OnKeyPressed(nKey);
}

void SHGameInterface::OnKeyReleased(int nKey)
{
	m_KeyMap[nKey] = false;

	m_pGame->OnKeyReleased(nKey);
}

void SHGameInterface::KeyHandle()
{
	for (auto key : m_BindKey)
	{
		const SHORT CHANGE_STATE_MASK = 0x0001;
		const SHORT PRESSED_STATE_MASK = 0x8000;
		SHORT nKeyState = GetAsyncKeyState(key);

		if ((nKeyState & PRESSED_STATE_MASK) != 0)
		{
			if (IsKeyPressed(key) == false)
			{
				OnKeyPressed(key);
			}
		}
		else
		{
			if (IsKeyPressed(key) == true)
			{
				OnKeyReleased(key);
			}
		}
	}
}