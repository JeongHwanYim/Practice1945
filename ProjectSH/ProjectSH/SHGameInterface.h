#pragma once

#include <vector>
#include <map>

class SHGame;

class SHGameInterface
{
public:
	void		Initialize();
	void		Finalize();

	SHGame*		GetGame() { return m_pGame; }

	void		Run();

	void		OnMouseMoved(int xPos, int yPos);
	void		OnMousePressed(int nKey);
	void		OnMouseReleased(int nKey);
	void		OnKeyPressed(int nKey);
	void		OnKeyReleased(int nKey);

	bool		IsMousePressed(int nKey) { return m_MouseMap[nKey]; }
	bool		IsKeyPressed(int nKey) { return m_KeyMap[nKey]; }
	int			GetMouseX() { return m_XPos; }
	int			GetMouseY() { return m_YPos; }

private:
	void		KeyHandle();

private:
	SHGame*		m_pGame;
	ULONGLONG	m_nPrev;

	FLOAT		m_fTargetDeltaTime;

	int			m_XPos, m_YPos;
	std::map< int, bool > m_MouseMap;
	std::map< int, bool > m_KeyMap;
	std::vector< int > m_BindKey;
};

extern SHGameInterface* gGameInterface;