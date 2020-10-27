//BTNode.h
#include<iostream>
using namespace std;

template<class T>
struct BTNode//Binary Tree Node
{
	T data;
	BTNode* left, * right;
	BTNode(const T& item = T(), BTNode* lptr = NULL, BTNode* rptr = NULL) :
		data(item), left(lptr), right(rptr) {}
};

template<class T>
BTNode<T>* GetBTNode(const T& item, BTNode<T>* lp = NULL, BTNode<T>* rp = NULL)
{
	BTNode<T>* p;
	p = new BTNode<T>(item, lp, rp);
	if (p == NULL)
	{
		cout << "Memory allocation failure!" << endl;
		exit(1);
	}
	return(p);
}
