#pragma once

#include <iostream>
#include <exception>

template <class T>
class smart_pointer{
public:
	smart_pointer(T* other = 0);
	smart_pointer(smart_pointer<T>& other);
	~smart_pointer();

	T& operator*();
	T* operator->();

	smart_pointer<T>& operator=(T* other);
	smart_pointer<T>& operator=(smart_pointer<T>& other);

	void Print(); //debug

private:
	void release();

	T* _pointer;
	std::size_t* _ref;
};


template <class T>
smart_pointer<T>::smart_pointer(T* other) : _pointer(other), _ref(new std::size_t(1))
{
	std::cout << "Default constructor" << std::endl; //debug
}

template <class T>
smart_pointer<T>::smart_pointer(smart_pointer<T>& other) : _pointer(other._pointer), _ref(other._ref)
{
	++*ref;
	std::cout << "Copy constructor" << std::endl; //debug
}

template <class T>
smart_pointer<T>::~smart_pointer(){
	release();
	std::cout << "Default Destructor" << std::endl; //debug
}

//implementing operator overload function form here

template <class T>
T& smart_pointer<T>::operator*(){
	return *_pointer;
}

template <class T>
T* smart_pointer<T>::operator->(){
	return _pointer;
}

template <class T>
smart_pointer<T>& smart_pointer<T>::operator=(T* other){

	if (_pointer == other)
		return *this;

	_pointer = other;
	*_ref = 1;

	return *this;
}

template <class T>
smart_pointer<T>& smart_pointer<T>::operator=(smart_pointer<T>& other){

	if (this == &other)
		return *this;

	release();
	_pointer = other._pointer;
	_ref = other._ref;
	++*_ref;

	return *this;

}


//implementing private function

template <class T>
void smart_pointer<T>::release(){
	if (!--*_ref){
		delete _ref;
		delete _pointer;
		std::cout << "Deleting the pointer." << std::endl; //debug
	}
}


//To debug
template <class T>
void smart_pointer<T>::Print(){
	std::cout << "Reference counter " << (int)*_ref << std::endl;
}