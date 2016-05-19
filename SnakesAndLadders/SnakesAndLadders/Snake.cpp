#include "Snake.h"


Snake::Snake() : _isCollidedTop(false), _isCollidedBottom(false)
{
	_isCreated = false;
}

Snake::~Snake(){
	if (_isCreated){
		deletePics();
	}
}

void Snake::setString(String^ top, String^ bottom){
	_topPath = top;
	_bottomPath = bottom;
}

/*
System::Drawing::Point Snake::update(System::Drawing::Point player, System::Drawing::Point other){
	System::Drawing::Point temp = player;
	if (player == _locationBottom || player == _locationTop){
		if (player == _locationTop && !_isCollidedTop){
			temp = _locationBottom;
			_isCollidedTop = true;
			_topPic->Enabled = false;
		}
		else if(player == _locationBottom && !_isCollidedBottom){
			_isCollidedBottom = true;
			_bottomPic->Enabled = false;
		}
	}
	else{
		if (_isCollidedTop && other != _locationTop){
			_topPic->Enabled = true;
			_isCollidedTop = false;
		}
		if(_isCollidedBottom && other != _locationBottom){
			_bottomPic->Enabled = true;
			_isCollidedBottom = false;
		}
	}

	return temp;
}
*/
