#pragma once
#include "GameObject.h"
ref class Ladder : public GameObject
{
public:
	Ladder();
	~Ladder();

	

private:
	bool _isCollidedTop;
	bool _isCollidedBottom;
};

