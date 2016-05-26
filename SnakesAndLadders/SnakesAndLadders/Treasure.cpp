#include "Treasure.h"


Treasure::Treasure()
{
	_isCreated = false;
}

Treasure::~Treasure()
{
	if (_isCreated){
		deletePics();
	}
}


void Treasure::setString(String^ path){
	_topPath = path;
}
