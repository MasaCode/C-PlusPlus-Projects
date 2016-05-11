#pragma once

#include <iostream>
#include "RefCounter.h"

template <class T>
class smart_pointer
{
public:
	explicit smart_pointer(T* other = nullptr);
	smart_pointer(smart_pointer<T>& other);

	~smart_pointer();
	
	T& operator*() const;
	T* operator->() const;
	
	smart_pointer<T>& operator=(const smart_pointer<T>& other);
	bool operator!=(const smart_pointer<T>& other) const ;
	bool operator==(const smart_pointer<T>& other) const;

private:

	void clear();

	RefCounter* _ref;
	T* _pointer;
};

///////////////// Destructor and Constructor //////////////////////////////////////////////////////////
template <class T>
smart_pointer<T>::smart_pointer(T* other) : _pointer(other), _ref(0)
{
	_ref = new RefCounter();
	_ref->AddRef();
}

template< class T>
smart_pointer<T>::smart_pointer(smart_pointer<T>& other) : _pointer(other._pointer), _ref(other._ref)
{
	_ref->AddRef();
}

template <class T>
smart_pointer<T>::~smart_pointer(){
	clear();
}

///////////////// Operator function //////////////////////////////////////////////////////////

template <class T>
T& smart_pointer<T>::operator*() const {
	return *_pointer;
}

template <class T>
T* smart_pointer<T>::operator->() const {
	return _pointer;
}

template <class T>
smart_pointer<T>& smart_pointer<T>::operator=(const smart_pointer<T>& other){
	if (this != &other){
		clear();
		_pointer = other._pointer;
		_ref = other._ref;
		_ref->AddRef();
	}

	return *this;
}

template <class T>
bool smart_pointer<T>::operator!=(const smart_pointer<T>& other) const  {
	return _pointer != other._pointer;
}

template <class T>
bool smart_pointer<T>::operator==(const smart_pointer<T>& other) const {
	return _pointer == other._pointer;
}

///////////////// Private function //////////////////////////////////////////////////////////

template <class T>
void smart_pointer<T>::clear(){
	if (_ref->Release() == 0){
		delete _pointer;
		delete _ref;
	}
}
