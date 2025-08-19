#pragma once
class InputHandler
{
public:
	static InputHandler* Instance();
	void update();
	void clean();
private:
	InputHandler();
	~InputHandler() {}
	static InputHandler* instance;
} ;
typedef InputHandler TheInputHandler;

