#pragma once
#include "Structures.h"
#include "Texture2D.h"
class ScenarioObjects
{
protected:
	Mesh* _mesh;
public:
	ScenarioObjects(Mesh* mesh);
	virtual ~ScenarioObjects();

	virtual void Update();
	virtual void Draw();


};

