#include "stdafx.h"
#include "SHGameInterface.h"
#include "SHGame.h"

#include "SHGame1945.h"

SHGameInterface* gGameInterface = new SHGameInterface;

void SHGameInterface::Initialize()
{
	m_XPos = 0, m_YPos = 0;

	QueryPerformanceFrequency(&m_Freq);
	QueryPerformanceCounter(&m_Prev);
	m_fTargetDeltaTime = 1.0f / TARGET_FRAME;

	m_BindKey = {
		VK_LEFT,
		VK_UP,
		VK_RIGHT,
		VK_DOWN,
	};

	m_pGame = new SHGame1945;
	m_pGame->Initialize();
}

void SHGameInterface::Finalize()
{
	m_pGame->Finalize();
	delete m_pGame;
	m_pGame = nullptr;
}

void SHGameInterface::Run()
{
	KeyHandle();

	LARGE_INTEGER Cur;
	QueryPerformanceCounter(&Cur);

	float fElapsedTime = (float)((double)(Cur.QuadPart - m_Prev.QuadPart) / m_Freq.QuadPart);
	if ( fElapsedTime >= m_fTargetDeltaTime)
	{
		m_pGame->OnFrame(fElapsedTime);

		m_Prev = Cur;
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
	for (auto& key : m_BindKey)
	{
		const USHORT CHANGE_STATE_MASK = 0x0001;
		const USHORT PRESSED_STATE_MASK = 0x8000;
		USHORT nKeyState = GetAsyncKeyState(key);

		if ((nKeyState & PRESSED_STATE_MASK) != 0)
		{
			if (IsKeyPressed(key) == false)
			{
				OnKeyPressed(key);
			}
		}
		else
		{
			if( IsKeyPressed(key) == true )
			{
				OnKeyReleased(key);
			}
		}
	}
}