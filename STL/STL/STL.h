#include <iostream>
#include <vector>
#include <list>
#include <deque>

class STL{
private:

public:
	STL(){}
	template<class T>
	void PrintVector(const std::vector< T > &value);
	template<class T>
	void PrintList(const std::list< T > &value);
	template<class T>
	void PrintDeque(const std::deque< T > &value);
};