#ifndef TREENODE_H
#define TREENODE_H

#include <string>
using std::string;

class Tree;

class TreeNode{
	
	friend class Tree;

public:
	TreeNode(int &lot, string &make, string &model, int &price) :_LotNumber(lot), _Make(make), _Model(model), _Price(price),right(0),left(0),middle(0){}
	~TreeNode(){ delete middle, right, left; }

	int LotNumber(){ return _LotNumber; }
	string Make(){ return _Make; }
	string Model(){ return _Model; }
	int Price(){ return _Price; }


private:
	int _LotNumber;
	string _Make;
	string _Model;
	int _Price;

	TreeNode *right;
	TreeNode *left;
	TreeNode *middle;
};


#endif