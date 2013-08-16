#pragma once
class UserControlSystem : public BaseSystem
{
protected:	
	Keyboard* _keyboard;
	Mouse* _mouse;

	EntitySystem* _entitySystem;

public:
	void Initialize();
	void Update(std::set<Entity*> controllable);
	void Kill();	

	void SetKeyboard(Keyboard* keyboard);
	void SetMouse(Mouse* mouse);
};

