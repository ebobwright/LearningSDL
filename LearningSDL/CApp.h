#ifndef _CAPP_H_
#define _CAPP_H_
 
class CApp 
{ 
protected:
	bool _running;
	
	EntitySystem* _entitySystem;

	void RegisterEventHandlers();
	void RegisterSystems();

	void TestCode();
	
	typedef void (CApp::*tyMessageHandler)(SDL_Event*);
	typedef std::map<Uint8, tyMessageHandler> tyMessageMap;
	typedef tyMessageMap::iterator tyMessageIterator;	
	tyMessageHandler GetMessageHandler(Uint8 message);
	tyMessageHandler RegisterMessageHandler(Uint8 message, tyMessageHandler handler);	
	tyMessageMap m_MsgHandlers;

	void Quit(SDL_Event* Event);

	bool OnInit();
	void OnEvent(SDL_Event* Event);
	void OnLoop(); 	
	void OnCleanup();

public:	
	int OnExecute(); 
};
 
#endif