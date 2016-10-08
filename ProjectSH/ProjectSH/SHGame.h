#pragma once

class SHGame
{
public:
	virtual void Initialize() = 0;
	virtual void Finalize() = 0;

	virtual void OnFrame(float fDeltaTime) = 0;

	virtual void	OnMousePressed(int nKey) {};
	virtual void	OnMouseReleased(int nKey) {};
	virtual void	OnKeyPressed(int nKey) {};
	virtual void	OnKeyReleased(int nKey) {};
};