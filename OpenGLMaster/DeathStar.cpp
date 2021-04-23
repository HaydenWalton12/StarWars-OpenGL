#include "DeathStar.h"
#include <iostream>
#include <fstream>


DeathStar::DeathStar(Mesh* mesh, float x, float y, float z) : ScenarioObjects(mesh)
{
	_rotation = 0.0f;

	_position.x = x;
	_position.y = y;
	_position.z = z;
}

DeathStar::~DeathStar()
{
}

void DeathStar::Draw()
{
	/*Loads and draws object*/

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, &_mesh->Vertices);
	glNormalPointer(GL_FLOAT, 0, &_mesh->Normals);
	glTexCoordPointer(2, GL_FLOAT, 0, &_mesh->TextureCoords);
	glPushMatrix();
	glTranslatef(_position.x, _position.y, _position.z);
	glRotatef(_rotation, 1.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < _mesh->IndexCount; i++)
	{

		glVertex3fv(&_mesh->Vertices[_mesh->Indices_vertices[i]].x);


	}
	glEnd();
	glPopMatrix();

	glDisableClientState(GL_VERTEX_ARRAY);



}

void DeathStar::Update()
{

}

