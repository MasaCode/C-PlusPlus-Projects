#include "Ladder.h"


Ladder::Ladder() : _isCollidedTop(false), _isCollidedBottom(false)
{
	_isCreated = false;
	_topPath = "Pics/ladderTop.png";
	_bottomPath = "Pics/ladderBottom.png";
}

Ladder::~Ladder(){
	if (_isCreated){
		deletePics();
	}

}

/*
System::Drawing::Point Ladder::update(System::Drawing::Point player, System::Drawing::Point other){
	System::Drawing::Point temp = player;
	if (player == _locationBottom || player == _locationTop){
		if (player == _locationTop && !_isCollidedTop){
			_isCollidedTop = true;
			_topPic->Enabled = false;
		}
		else if (player == _locationBottom && !_isCollidedBottom){
			temp = _locationTop;
			_isCollidedBottom = true;
			_bottomPic->Enabled = false;
		}
	}
	else{
		if (_isCollidedTop && other != _locationTop){
			_topPic->Enabled = true;
			_isCollidedTop = false;
		}
		if (_isCollidedBottom && other != _locationBottom){
			_bottomPic->Enabled = true;
			_isCollidedBottom = false;
		}
	}

	return temp;
}

*/