#pragma once
#include <Windows.h>
//Library declarations
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"

#include "Structures.h"
#include "MeshLoader.h"
#include "ScenarioObjects.h"
#include "GLUTCallbacks.h"


class StarDestroyer : public ScenarioObjects
{
private:
	GLfloat _rotation;
	Vector3 _position;
public:
	StarDestroyer(Mesh* mesh, float x, float y, float z);
	~StarDestroyer();

	void Draw();
	void Update();

};
