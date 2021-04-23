#pragma once
#include "Structures.h"
#include "Texture2D.h"
class OldObjects
{
protected:
	ObjectMesh* old_mesh;
	Texture2D* old_texture;
public:
	OldObjects(ObjectMesh* mesh, Texture2D* texture);
	virtual ~OldObjects();

	virtual void Update();
	virtual void Draw();


};


