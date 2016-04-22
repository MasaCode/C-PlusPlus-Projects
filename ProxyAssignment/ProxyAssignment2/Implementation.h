#ifndef Implementation_H
#define Implementation_H

#include <vector>
#include <string>
#include <map>

typedef std::multimap<int, std::string, std::less<int>> idMap;

class Implementation{
private:
	idMap id;
	std::vector<int> balance;
	std::vector<int> limit;
	std::vector<std::string> accountNumber;

	void ReadData();
public:
	Implementation();
	~Implementation(){};
	int GetId(std::string name);
	int GetBalance(int id);
	int GetLimit(int id);
	std::string GetaccountNumber(int id);
	int Namecheck(std::string name);
};



#endif