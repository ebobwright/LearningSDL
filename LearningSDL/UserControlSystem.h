#pragma once
class UserControlSystem : public BaseSystem
{
protected:
	Keyboard* _keyBoard;

public:
	void Initialize();
	void Update();
	void Kill();	
};

