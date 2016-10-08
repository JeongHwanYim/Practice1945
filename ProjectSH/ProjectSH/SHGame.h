#pragma once

class SHGame
{
public:
	virtual void OnFrame(float fDeltaTime) = 0;

	virtual void OnMousePressed(float fDeltaTime) {}
	virtual void OnMouseReleased(float fDeltaTime) {}
	virtual void OnKeyPressed(float fDeltaTime) {}
	virtual void OnKeyReleased(float fDeltaTime) {}
};