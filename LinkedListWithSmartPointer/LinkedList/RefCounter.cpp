#include "RefCounter.h"


RefCounter::RefCounter()
{
}


RefCounter::~RefCounter()
{
}


int RefCounter::AddRef(){
	++counter;
	return counter;
}

int RefCounter::Release(){
	--counter;
	return counter;
}
