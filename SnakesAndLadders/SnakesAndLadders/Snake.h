#pragma once
#include "GameObject.h"
ref class Snake : public GameObject
{
public:
	Snake();
	~Snake();

	void setString(String^ top, String^ bottom) override;
	

	
private:
	bool _isCollidedTop;
	bool _isCollidedBottom;
};

