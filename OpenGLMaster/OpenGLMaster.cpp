// OpenGLMaster.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "OpenGLMain.h"
#include <stdio.h> 
#include <math.h>

void passive_motion(int, int);
float YAW = 0.0f, PITCH = 0.0f;
float Camera_X = 0.0, Camera_Y = 0.0f, Camera_Z = 0.0;

OpenGLMain::OpenGLMain(int argc, char* argv[])
{
	InitialiseGL(argc, argv);
	InitialiseObjects();
	glutMainLoop();
}
OpenGLMain::~OpenGLMain(void)
{
}

void OpenGLMain::InitialiseObjects()
{

	//Calls Objects to load
	Mesh* xwing = ObjectLoader::Load((char*)"Models/XWing.obj");
	Mesh* tie_fighter = ObjectLoader::Load((char*)"Models/TieFighter.obj");
	Mesh* death_star = ObjectLoader::Load((char*)"Models/DeathStar.obj");
	Mesh* home_one = ObjectLoader::Load((char*)"Models/HomeOne.obj");
	Mesh* star_destroyer = ObjectLoader::Load((char*)"Models/StarDestroyer.obj");

	//Draws and stores Objects in array
	for (int i = 0; i < 1; i++)
	{
		objects[i] = new XWing(xwing, -2.5, -3, -2);
	}
	for (int i = 1; i < 2; i++)
	{
		objects[i] = new XWing(xwing, -3.25, -1, -2.5);
	}
	for (int i = 2; i < 3; i++)
	{
		objects[i] = new TieFighter(tie_fighter, 1, 1, 1);
	}
	for (int i = 3; i < 4; i++)
	{
		objects[i] = new TieFighter(tie_fighter, -3, -5, -4);
	}
	for (int i = 4; i < 5; i++)
	{
		objects[i] = new DeathStar(death_star, -1, -1, -1);
	}
	for (int i = 5; i < 6; i++)
	{
		objects[i] = new HomeOne(home_one, -2, 1, -2);
	}
	for (int i = 6; i < 7; i++)
	{
		objects[i] = new StarDestroyer(star_destroyer, -15, -3, -2);
	}
	for (int i = 7; i < 8; i++)
	{
		objects[i] = new StarDestroyer(star_destroyer, -10, -5, -3);
	}
	for (int i = 8; i < 9; i++)
	{
		objects[i] = new StarDestroyer(star_destroyer, -5, -3, -2);
	}
	for (int i = 9; i < 10; i++)
	{
		objects[i] = new TieFighter(tie_fighter, -5, 3.5, -2);
	}
	for (int i = 10; i < 11; i++)
	{
		objects[i] = new TieFighter(tie_fighter, -6, 3.8, -2.5);
	}
	for (int i = 11; i < 12; i++)
	{
		objects[i] = new XWing(xwing, 6, 3.8, -2.8);
	}
	
}

void OpenGLMain::InitialiseGL(int argc, char* argv[])
{
	/*Initialises GL Functions*/

	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	
	glutInitDisplayMode(GLUT_DOUBLE); 
	glutInitWindowSize(WIDTH, HEIGHT);	
	glutInitWindowPosition(100, 100);
	glutCreateWindow("StarWars OpenGL Project");
	

	glutPassiveMotionFunc(passive_motion);//Allows our mouse to update viewing via moving it, we pass in our passive motion function as seen below
	glutSetCursor(GLUT_CURSOR_NONE);//Hides Cursor in game world
	

	//Call Backs (Enables GL Functions)
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutKeyboardUpFunc(GLUTCallbacks::Keyboard_up);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutDisplayFunc(GLUTCallbacks::Display);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 0, 1000);	
	
	//Cursor
	glutWarpPointer(WIDTH/2,HEIGHT/2);//Sets the cursor position dead cemtre, by halfing our constants to place cursor in middle.
	glutSetCursor(GLUT_CURSOR_NONE);//Hides Cursor in game world
	
	//ViewPort Settings
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK); 
	
}

void passive_motion(int x, int y)
{
	//This function updates the pitch/yaw which will change our viewing position, 
	int _x, _y; //Create two local variables to store the coordinartes
	_x = (WIDTH / 2) - x;//If mouse moves right it will be negative, if left its positive
	_y = (HEIGHT / 2) - y;
	//This is used to update the angles to project view to the screen, this is done via 

	//Yaw & Pitch Calculations, We divide our pitch and yaw to control to sensitive of our mouse input
	YAW+= (float)_x / 20;
	PITCH += (float)_y / 20;
}

void OpenGLMain::NewCamera()
{
	//Trigometry is used to calculate movement along the axis, we will use these to assign to keys, so when key is ressed depending on the condition of 
	//which created here, a position on the camera will change

	if (motion->Forward)
	{
		Camera_X += cos((YAW + 90) * TO_RADIANS) / 5.0; 
		Camera_Z -= sin((YAW + 90) * TO_RADIANS) / 5.0;
	}
	if (motion->Backwards)
	{
		Camera_X += cos((YAW + 90 + 180) * TO_RADIANS) / 5.0;
		Camera_Z -= sin((YAW + 90 + 180) * TO_RADIANS) / 5.0;
	}
	if (motion->Left)
	{
		Camera_X += cos((YAW + 90 + 90) * TO_RADIANS) / 5.0;
		Camera_Z -= sin((YAW + 90 + 90) * TO_RADIANS) / 5.0;
	}
	if (motion->Right)
	{
		Camera_X += cos((YAW + 90 - 90) * TO_RADIANS) / 5.0;
		Camera_Z -= sin((YAW + 90 - 90) * TO_RADIANS) / 5.0;
	}

	//Assigns Our
	if (motion->Up)
	{
		Camera_Y += cos((YAW + 90 - 90) * TO_RADIANS) / 5.0;
	}
	if (motion->Down)
	{
		Camera_Y -= cos((YAW + 90 - 90) * TO_RADIANS) / 5.0; 
	}

	glRotatef(-PITCH, 1.0, 0.0, 0.0);
	glRotatef(-YAW, 0.0, 1.0, 0.0);
	glTranslatef(-Camera_X, -Camera_Y , -Camera_Z);  
}


void OpenGLMain::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);
	glPushMatrix();
	NewCamera();
	
	Vector3 v = { 0.0f, 0.0f, 0.0f };
	Color c = { 0.0f, 1.0f, 0.0f };
	DrawString("Controls:W(Forward)A(Left)S(Backwards)D(RIGHT)Q(UP)E(DOWN)R(MOVE SCENE) ", &v, &c);

	for (int i = 0; i < 12; i++)
	{
		objects[i]->Draw();
	}
	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}
void OpenGLMain::update()
{

}
void OpenGLMain::DrawString(const char* text, Vector3* position, Color* color)
{
	glPushMatrix();
	glTranslatef(position->x, position->y, position->z);
	glRasterPos2f(0.0f, 0.0f);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)text);
	glPopMatrix();
}
void OpenGLMain::Keyboard(unsigned char key, int x, int y)
{

	switch (key)
	{
	case 'w'://-Z Axis
		motion->Forward = true;
		break;

	case 's'://+Z Axis
		motion->Backwards = true;
		break;

	case 'a'://-X Axis
		motion->Left = true;
		break;	

	case 'd'://+X Axis
		motion->Right = true;
		break;

	case 'q'://+Y Axis
		motion->Up = true;
		break;

	case 'e'://-Y Axis
		motion->Down = true;
		break;
	case 'r':
		glLoadIdentity();

			for (int i = 0; i < 12; i++)
			{
				objects[i]->Update();
			}
		glutPostRedisplay();
		break;
	case 'l'://Ends Program
		std::cout << "Goodbye" << std::endl;
			exit(0);
		
	default:
		break;
	}

	
	
}

void OpenGLMain::keyboard_up(unsigned char key, int x, int y)
{
	//Derives from "keyboard" function, if key is up , return motion as false
	switch (key)
	{
	case 'w':
		motion->Forward = false; //Halts Movement 
		break;
	case 's':
		motion->Backwards = false;//Halts Movement 
		break;
	case 'a':
		motion->Left = false;//Halts Movement 
		break;
	case 'd':
		motion->Right = false;//Halts Movement 
	case 'q':
		motion->Up = false;//Halts Movement 
		break;
	case 'r'://Stops Objects Movement
		break;
	case 'e':
		motion->Down = false;//Halts Movement 
		break;
	default:
		break;
	}
}



