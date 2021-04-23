#include "OpenGLMain.h"

int main(int argc, char* argv[])
{
	OpenGLMain* game = new OpenGLMain(argc, argv); 
	
	//Class "OpenGLMain" is pointed to game , making game a pointer to the class mentioned, creating new instance of our new game.
	//Reason we pass "argc, argv" as parameters since our class contructor passes these said parameters too
	
	return 0; //Assumes a successful exit if our game exits
}

/*
Every program needs "main" source file
*/