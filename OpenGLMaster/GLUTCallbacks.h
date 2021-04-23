#pragma once
class OpenGLMain;

namespace GLUTCallbacks //We use  namespace instead of a class since FreeGlut primarily supports the C library instead of c++, 
						//so we use namespaces, which are similar to classes , they allow us to encase quanities of data exlcusively to that namespace
{
	void Init(OpenGLMain* gl); //Initialise function with local parameter pointer called gl passed into it , this a part of our callback function

	void Display();
	
	void Timer(int preferredRefresh);
	void Keyboard(unsigned char key, int x, int y);
	void Keyboard_up(unsigned char key, int x, int y);
}
