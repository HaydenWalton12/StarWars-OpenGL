#pragma once
#include <Windows.h> //Required for OpenGL on Windows 

//Libaries
#include <gl/GL.h> //OpenGL 
#include <gl/GLU.h> //OpenGL Utilities 
#include "GL\freeglut.h" //freeglut library


#include "constants.h"
#include "Structures.h"
#include "MeshLoader.h"
#include "Obj_Loader.h"
#include "ScenarioObjects.h"
#include "Cube.h"
#include "XWing.h"
#include "DeathStar.h"
#include "TieFighter.h"
#include "StarDestroyer.h"
#include "HomeOne.h"
#include "Obj_Loader.h"

#include "GLUTCallbacks.h"
class OpenGLMain
{
public:
	//contructor
	OpenGLMain(int argc, char* argv[]);
	//destructor
	~OpenGLMain(void);

	void Display();//Displays Objects to Screen
	void update(); //update our methods to the screen

	void Keyboard(unsigned char key, int x, int y);//Input to move camera (As of biw)
	void keyboard_up(unsigned char key, int x, int y);
	void InitialiseObjects();//intialise objects on scene
	void InitialiseGL(int argc, char* argv[]);
	void NewCamera();
	
	void DrawString(const char* text, Vector3* position, Color* color);

private:
	Vector3 _position;
	Movement* motion = new Movement();
	ScenarioObjects* objects[20];
};

