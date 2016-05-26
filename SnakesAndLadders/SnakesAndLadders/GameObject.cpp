#include "GameObject.h"


GameObject::GameObject()
{
	//Empty
}

GameObject::~GameObject()
{
	//Empty
}

void GameObject::init(System::Drawing::Point top, System::Drawing::Point bottom, int topIndex, int bottomIndex,int PicSize){
	_locationTop = top;
	_locationBottom = bottom;
	_TopIndex = topIndex;
	_BottomIndex = bottomIndex;

	if (!_isCreated){
		_topPic = gcnew PictureBox();
		_topPic->Size = System::Drawing::Size(PicSize, PicSize);
		_topPic->SizeMode = PictureBoxSizeMode::StretchImage;
		_topPic->Image = gcnew System::Drawing::Bitmap(_topPath);

		_bottomPic = gcnew PictureBox();
		_bottomPic->Size = System::Drawing::Size(PicSize, PicSize);
		_bottomPic->SizeMode = PictureBoxSizeMode::StretchImage;
		_bottomPic->Image = gcnew System::Drawing::Bitmap(_bottomPath);
		_isCreated = true;
	}
}

void GameObject::init(System::Drawing::Point location, int index, int PicSize,int point){
	_locationTop = location;
	_TopIndex = index;
	if (!_isCreated){
		_topPic = gcnew PictureBox();
		_topPic->Size = System::Drawing::Size(PicSize, PicSize);
		_topPic->SizeMode = PictureBoxSizeMode::StretchImage;
		_topPic->Image = gcnew System::Drawing::Bitmap(_topPath);
		_point = point;
		_isCreated = true;
	}
}

PictureBox^ GameObject::drawTop(){
	//Make Sure if you wanna draw on the gameGrid, you need to remove the picturebox.
	_topPic->Location = _locationTop;

	return _topPic;
}

PictureBox^ GameObject::drawBottom(){
	//Make Sure if you wanna draw on the gameGrid, you need to remove the picturebox.
	_bottomPic->Location = _locationBottom;

	return _bottomPic;
}


void GameObject::VisibleTop(bool isVisible){
	if (isVisible){
		_topPic->Visible = true;
	}
	else{
		_topPic->Visible = false;
	}
}

void GameObject::VisibleBottom(bool isVisible){
	if (isVisible){
		_bottomPic->Visible = true;
	}
	else{
		_bottomPic->Visible = false;
	}
}


int GameObject::getTopIndex(){
	return _TopIndex;
}

int GameObject::getBottomIndex(){
	return _BottomIndex;
}

int GameObject::getPoint(){
	return _point;
}

System::Drawing::Point GameObject::getTopLocation(){
	return _locationTop;
}

System::Drawing::Point GameObject::getBottomLocation(){
	return _locationBottom;
}

void GameObject::setPoint(int point){
	_point = point;
}

void GameObject::deletePics(){
	delete _topPic;
	delete _bottomPic;
}