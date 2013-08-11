#pragma once
class Keyboard
{
public:
	Keyboard(void);	

	void SetKey(SDLKey key, bool state);
	bool GetKey(SDLKey key);

protected:
	bool _keyState[323];
};
