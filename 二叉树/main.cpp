#include<iostream>
#include"BTNode.h"
#include<queue>
#include<stack>
using namespace std;

//层次遍历
template<class T>
void Level(const BTNode<T>* t)
{
	if (t == NULL)
		return;
	queue<const BTNode<T>*>Q;
	Q.push(t);
	while (!Q.empty())
	{
		t = Q.front();
		Q.pop();
		cout << t->data;
		if (t->left)
			Q.push(t->left);
		if (t->right)
			Q.push(t->right);
	}
}

//前序遍历递归算法
template<class T>
void Preorder(const BTNode<T>* t)
{
	if (t == NULL)
		return;
	cout << t->data;
	if (t->left)
		Preorder(t->left);
	if (t->right)
		Preorder(t->right);
}

//前序遍历非递归算法
template<class T>
void SimPreorder(const BTNode<T>* t)
{
	if (!t)
		return;
	stack<const BTNode<T>*> S;
	while (t || !S.empty())
		if (t)
		{
			cout << t->data;
			if (t->right)
				S.push(t->right);
			t = t->left;
		}
		else
		{
			t = S.top();
			S.pop();
		}
}

//中序遍历递归算法
template<class T>
void Inorder(const BTNode<T>* t)
{
	if (!t)
		return;
	if (t->left)
		Inorder(t->left);
	cout << t->data;
	if (t->right)
		Inorder(t->right);
}

//中序遍历非递归算法
template<class T>
void SimInorder(const BTNode<T>* t)
{
	if (!t)
		return;
	stack<const BTNode<T>*> S;
	while(t||!S.empty())
		if (t)
		{
			S.push(t);
			t = t->left;
		}
		else
		{
			t = S.top();
			S.pop();
			cout << t->data;
			t = t->right;
		}
}

//后续遍历递归算法
template<class T>
void Postorder(const BTNode<T>* t)
{
	if (!t)
		return;
	if (t->left)
		Postorder(t->left);
	if (t->right)
		Postorder(t->right);
	cout << t->data;
}

//后续遍历非递归算法
template<class T>
void SimPostorder(const BTNode<T>* t)
{
	if (!t)
		return;
	int tag;
	stack<const BTNode<T>*> S;
	stack<int> tagS;
	const BTNode<T>* temp;
	while(t||!S.empty())
		if (t)
		{
			S.push(t);
			tagS.push(1);
			t = t->left;
		}
		else
		{
			temp = S.top();
			S.pop();
			tag = tagS.top();
			tagS.pop();
			if (tag == 1)
			{
				S.push(temp);
				tagS.push(2);
				t = temp->right;
			}
			else
				cout << temp->data;
		}
}

int main()
{
	BTNode<char>* nullp = NULL;
	BTNode<char>* fp = GetBTNode('F');
	BTNode<char>* dp = GetBTNode('D', fp);
	BTNode<char>* bp = GetBTNode('B', nullp, dp);
	BTNode<char>* ep = GetBTNode('E');
	BTNode<char>* cp = GetBTNode('C', nullp, ep);
	BTNode<char>* ap = GetBTNode('A', bp, cp);
	Level(ap);
	cout << endl;
	Preorder(ap);
	cout << endl;
	SimPreorder(ap);
	cout << endl;
	Inorder(ap);
	cout << endl;
	SimInorder(ap);
	cout << endl;
	Postorder(ap);
	cout << endl;
	SimPostorder(ap);
	cout << endl;
	return(0);
}
