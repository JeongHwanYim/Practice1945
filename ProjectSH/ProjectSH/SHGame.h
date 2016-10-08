#pragma once

class SHGame
{
public:
	virtual void Initialize() = 0;
	virtual void Finalize() = 0;

	virtual void OnFrame(float fDeltaTime) = 0;

	void		OnMousePressed(int nKey) {};
	void		OnMouseReleased(int nKey) {};
	void		OnKeyPressed(int nKey) {};
	void		OnKeyReleased(int nKey) {};
};