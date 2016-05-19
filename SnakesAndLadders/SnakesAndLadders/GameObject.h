#pragma once

#include <random>
#include <ctime>


using namespace System;
using namespace System::Windows::Forms;

ref class GameObject
{
public:
	GameObject();
	virtual ~GameObject();
	

	void init(System::Drawing::Point top, System::Drawing::Point bottom, int topIndex, int bottomIndex, int PicSize);
	PictureBox^ drawTop();
	PictureBox^ drawBottom();
	void VisibleTop(bool isVisible);
	void VisibleBottom(bool isVisible);


	//getters
	int getTopIndex();
	int getBottomIndex();
	System::Drawing::Point getTopLocation();
	System::Drawing::Point getBottomLocation();

protected:

	void deletePics();

protected:
	System::Drawing::Point _locationTop;
	System::Drawing::Point _locationBottom;
	int _TopIndex = 0;
	int _BottomIndex = 0;
	PictureBox^ _topPic;
	PictureBox^ _bottomPic;

	System::String^ _topPath; 
	System::String^ _bottomPath;
	bool _isCreated; // Maybe initialize in constructor
};

