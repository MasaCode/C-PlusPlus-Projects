#pragma once
class RefCounter
{
public:
	RefCounter();
	~RefCounter();

	int AddRef();
	int Release();

private:
	int counter;
};

