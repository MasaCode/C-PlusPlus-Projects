#ifndef StoneGame_H
#define StoneGame_H
class StoneGame{
private:
	char GameGrid[256];
	int NextPlace;


public:
	StoneGame();
	void CreateStones(int NumberOfStones);
	void Print();
	bool Move(int RowOfFrom, int ColumnOfFrom, int RowOfTo, int ColumnOfTo);
	bool CheckPlacement(int Place, int Next);
	bool IsContinue();
	int CountScore();
};


#endif /*StoneGame_H*/