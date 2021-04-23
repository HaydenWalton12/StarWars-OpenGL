#include "Obj_Loader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector> 
#include <string>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable:4996)//Disables fopen error
using namespace std;

namespace ObjectLoader
{

	Mesh* Load(const char* path)
	{
		ifstream inFile;
		inFile.open(path);

		if (!inFile.good())
		{
			cout << "Cant open file " << endl;
			return nullptr;
		}

		string row;
		string v, face;

		Mesh* mesh = new Mesh();
		mesh->IndexCount = 0; //calling
		while (!inFile.eof())
		{
			getline(inFile, row);

			inFile >> v;
			if (v == "v")//This allows us to convert string to char "*" 
			{
				Vertex vertex;

				inFile >> vertex.x >> vertex.y >> vertex.z;
				mesh->Vertices.push_back(vertex); //pudh_back "vector"
			}

			else if (v == "vt")
			{
				TexCoord UV;
				inFile >> UV.u >> UV.v;
				mesh->TextureCoords.push_back(UV);
			}
			else if (v == "vn")
			{
				//inFile >> x >> y >> z;

			}
			if (v == "f")
			{
				mesh->IndexCount += 3;//Couting for our face, 3 vertices in a face.
				for (int i = 0; i < 3; i++)
				{
					inFile >> face;

					for (int i = 0; i < face.length(); i++)
					{
						if (face[i] == '/')//Seeks for slashes and if true it replaces with space, this will repeat frequently needed since data 
						{
							face[i] = ' ';
						}
					}
					int exp = 1;
					stringstream f(face);
					GLshort w, q;
					f >> w >> q;
					mesh->Indices_vertices.push_back(w - 1);
					mesh->Indices_uvCoords.push_back(q - 1);
				}

			}

		}
		return mesh;
	}
}


