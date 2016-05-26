#pragma once
#include "GameObject.h"
ref class Treasure : public GameObject
{
public:
	Treasure();
	~Treasure();

	void setString(String^ path) override;
};

