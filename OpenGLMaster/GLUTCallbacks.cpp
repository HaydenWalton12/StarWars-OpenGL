// Includes
#include "GLUTCallbacks.h"
#include "OpenGLMain.h"

/*
	This callback function is used to pass an argumented to other code, from this, we are expected to "call-back" this argument in a certain amount of time
	We achieve this within c++ via the use of namespaces and function pointers.

	If a function or a referenced of a function is passed into another function , as a argument to call back the function, this is a callback function

*/

// Namespace implementation
namespace GLUTCallbacks
{
	namespace
	{
		//Initialise to a null pointer before we do anything
		OpenGLMain* openGLMain = nullptr; //This points OpenGLMainClass to name openGLMain, and sets it equal to null (This intialises pointer)
	}
	void Init(OpenGLMain* gl)
	{
		openGLMain = gl; 
	}

	void Display()
	{
		if (openGLMain != nullptr)
		{
			openGLMain->Display();
		}
	}
	void Timer(int preferredRefresh)
	{	
		 glutPostRedisplay();
		int updateTime = glutGet(GLUT_ELAPSED_TIME);
		glutWarpPointer(WIDTH / 2, HEIGHT / 2);
		openGLMain->update(); //since openGLMain is equal to the class OpenGLMain "We can see this via the void Init Function that assigns our namespace variable to this" , we can see that we have called the function 
		//From our update GlMain class as an argument , from this, to call this back ,we will need to pass into our main OpenGlMain source file our timer function, to call the update function. creating the loop
		updateTime = glutGet(GLUT_ELAPSED_TIME) - updateTime;
		
		glutTimerFunc(preferredRefresh - updateTime, GLUTCallbacks::Timer, preferredRefresh);
	
		/*
		To keep a stable 60fps, this method ensures that by subtrating the elapsed time by current time, that if our time is negative, it will restart the timer to 16ms, creating stable fps
		*/
	}
	void Keyboard(unsigned char key, int x, int y)
	{
		openGLMain->Keyboard(key, x, y); //This is the callback function for passing keyboard as an argument, this will then be called back into our OpenGLMaster Source file iwhtin the contructor to instialise and to allow keyboard function to ilterate
	}
	void Keyboard_up(unsigned char key, int x, int y)
	{
		openGLMain->keyboard_up(key, x, y);
	
	}
}
