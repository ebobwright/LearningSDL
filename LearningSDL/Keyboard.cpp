#include "consolidated.h"


Keyboard::Keyboard(void)
{
	for(int i = 0; i < 323; i++)
		_keyState[i] = false;
}

void Keyboard::SetKey(SDLKey key, bool state)
{	
	_keyState[key] = state;
}

bool Keyboard::GetKey(SDLKey key)
{
	return _keyState[key];
}

