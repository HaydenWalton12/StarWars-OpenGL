#pragma once
#include <Windows.h> //Required for OpenGL on windows
#include <gl/GL.h> //OpenGL
#include <gl/GLU.h> //OpenGL Utilities
#include "GL\freeglut.h" //freeglut library
#include "GLUTCallbacks.h"
#include <vector>
//This header file will be used to define all structures within our program.

struct Vector3
{
	float x, y, z;//Used for our camera definitions and rotation (So far)

};

struct Color
{
	GLfloat r, g, b; //Used for colour lists
};

struct Vertex
{
	GLfloat	x, y, z;//Used for vertex lists
};
struct Normal
{
 long float x, y, z;
};
struct TexCoord
{
	GLfloat u, v;
};
struct Movement
{
	bool Forward;
	bool Backwards;
	bool Left;
	bool Right;
	bool Up;
	bool Down;
};
struct Mesh
{
	std::vector <Vertex> Vertices;
	std::vector <GLushort> Indices;
	std::vector <TexCoord> TextureCoords;
	std::vector <Normal> Normals;

	int VertexCount, ColorCount, TexCoordCount, IndexCount, NormalCount;

	std::vector <GLushort> Indices_vertices;
	std::vector <GLushort> Indices_uvCoords;
	std::vector <GLushort> Indices_normals;
};


//THis structure "mesh" as seen creates structure pointers as seen above, we have done this since  mesh is a collation of these objects which all compose the polygonal object, currently we rely on using each of the independent structs
//TO use them for creation, however until now we havent collated them via the use of a mesh struct.We will have to alter the code to ensure that our object creations are done via the use of the mesh struct.