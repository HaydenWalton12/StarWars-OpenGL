#pragma once
#include <Windows.h>
//Library declarations
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"

#include "Structures.h"
#include "MeshLoader.h"
#include "OldObjects.h"
#include "GLUTCallbacks.h"


class Cube : public OldObjects
{
private:
	GLfloat _rotation;
	Vector3 _position;
public:
	Cube(ObjectMesh* mesh, Texture2D* texture, float x, float y, float z);
	~Cube();

	void Draw();
	void Update();
	
};
