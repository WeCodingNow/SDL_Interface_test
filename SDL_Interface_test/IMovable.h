#pragma once

class IMovable
{
protected:
	int offX, offY;
public:
	virtual void RememberOffset(int mouseX, int mouseY) = 0;
	virtual void Move(int mouseX, int mouseY) = 0;
};