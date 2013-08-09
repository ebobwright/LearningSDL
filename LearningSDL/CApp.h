#ifndef _CAPP_H_
#define _CAPP_H_
 
class CApp 
{ 
protected:
	bool _running;
	
	EntitySystem* _entitySystem;

public:
	CApp();
	int OnExecute(); 
	bool OnInit();
	void OnEvent(SDL_Event* Event);
	void OnLoop(); 	
	void OnCleanup();
};
 
#endif