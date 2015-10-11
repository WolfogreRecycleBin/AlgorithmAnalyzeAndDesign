#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>//for sort()
#include <functional>//for greater<int>()
#include "Node.h"
using namespace std;

void CalHuffmanCode(Node<int>  *root)
{
	if (root->leftChild != NULL)
	{
		root->leftChild->huffmanCode = root->huffmanCode + "0";
		CalHuffmanCode(root->leftChild);
	}
	if (root->rightChild != NULL)
	{
		root->rightChild->huffmanCode = root->huffmanCode + "1";
		CalHuffmanCode(root->rightChild);
	}
}

void ShowHuffmanCode(Node<int> *root)
{
	CalHuffmanCode(root);
	queue<Node<int> *> nodeQueue;
	nodeQueue.push(root);
	while (!nodeQueue.empty())
	{
		Node<int> * node = nodeQueue.front();
		nodeQueue.pop();
		bool isLeef = true;
		if (node->leftChild != NULL)
		{
			isLeef = false;
			nodeQueue.push(node->leftChild);
		}
		if (node->rightChild != NULL)
		{
			isLeef = false;
			nodeQueue.push(node->rightChild);
		}
		if (isLeef)
		{
			cout << node->data << " " << node->huffmanCode << endl;
		}
	}
}

bool Greater(Node<int>* a, Node<int>* b)
{
	return a->data > b->data;
}

int main(void)
{
	int caseNum;
	cin >> caseNum;
	int caseCount = 0;
	while (++caseCount <= caseNum)
	{
		vector<Node<int>*> trees;
		int valueCount;
		cin >> valueCount;
		while (--valueCount >= 0)
		{
			int value;
			cin >> value;
			trees.push_back(new Node<int>(value));
		}
		
		sort(trees.begin(), trees.end(), Greater);

		while (trees.size() > 1)
		{
			Node<int>* rightTree = trees.back();
			trees.pop_back();
			Node<int>* leftTree = trees.back();
			trees.pop_back();
			Node<int> *newNode = new Node<int>(leftTree->data + rightTree->data);
			newNode->leftChild = leftTree;
			newNode->rightChild = rightTree;
			vector<Node<int>*>::iterator it;
			for (it = trees.begin(); it != trees.end(); ++it)
				if ((*it)->data < newNode->data)
					break;
			trees.insert(it, newNode);
		}

		cout << "Case " << caseCount << endl;
		ShowHuffmanCode(trees.back());
		cout << endl;
	}
	
	
	system("pause");
	return 0;
}


