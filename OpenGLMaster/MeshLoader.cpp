#include "MeshLoader.h"
#include <iostream>
#include <fstream>

using namespace std;
/*
namespace MeshLoader
{
	//Prototype
	void LoadVertices(ifstream& inFile, Mesh& mesh);
	void LoadIndices(ifstream& inFile, Mesh& mesh);
	void LoadTexture(ifstream& inFile, Mesh& mesh);
	void LoadVertices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.VertexCount;

		if (mesh.VertexCount > 0)
		{
			mesh.Vertices = new Vertex[mesh.VertexCount];

			for (int i = 0; i < mesh.VertexCount; i++)
			{
				inFile >> mesh.Vertices[i].x;
				inFile >> mesh.Vertices[i].y;
				inFile >> mesh.Vertices[i].z;
			}
		}
	}
	void LoadTexture(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.TexCoordCount;
		if (mesh.TexCoordCount > 0)
		{
			mesh.TextureCoords = new TexCoord[mesh.TexCoordCount];
			for (int i = 0; i < mesh.TexCoordCount; i++)
			{
				inFile >> mesh.TextureCoords[i].u;
				inFile >> mesh.TextureCoords[i].v;
			}
		}
	}
	void LoadIndices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.IndexCount;
		if (mesh.IndexCount > 0)
		{
			mesh.Indices = new GLushort[mesh.IndexCount];
			for (int i = 0; i < mesh.IndexCount; i++)
			{
				inFile >> mesh.Indices[i];
	
			}
		}
	}

	Mesh* MeshLoader::Load(char* path)
	{
		Mesh* mesh = new Mesh();

		ifstream inFile;

		inFile.open(path);

		if (!inFile.good())  
		{
			cerr  << "Can't open texture file " << path << endl;
			return nullptr;
		}
		LoadVertices(inFile, *mesh);
		LoadTexture(inFile, *mesh);
		LoadIndices(inFile, *mesh);
		inFile.close();


		return mesh;
	}

}
*/