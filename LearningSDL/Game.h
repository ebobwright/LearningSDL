#ifndef _Game_H_
#define _Game_H_
 
class Game 
{ 
protected:	
	bool _running;
		
	EntitySystem* _entitySystem;
	Keyboard* _keyBoard;

	void RegisterEventHandlers();
	void RegisterSystems();

	void TestCode();
	
	typedef void (Game::*tyMessageHandler)(SDL_Event*);
	typedef std::map<Uint8, tyMessageHandler> tyMessageMap;
	typedef tyMessageMap::iterator tyMessageIterator;	
	tyMessageHandler GetMessageHandler(Uint8 message);
	tyMessageHandler RegisterMessageHandler(Uint8 message, tyMessageHandler handler);	
	tyMessageMap m_MsgHandlers;

	void Quit(SDL_Event* Event);
	void KeyDown(SDL_Event* Event);
	void KeyUp(SDL_Event* Event);

	bool OnInit();
	void OnEvent(SDL_Event* Event);
	void OnLoop(); 	
	void OnCleanup();

public:	
	int OnExecute(); 

	Keyboard* GetKeyboard();
};
 
#endif