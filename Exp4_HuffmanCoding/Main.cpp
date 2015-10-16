#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>//for sort()
#include <functional>//for greater<int>()
//#include "Node.h"
using namespace std;


template <class ElemType>
struct Node
{
	// 数据成员:
	ElemType data;				// 数据域
	int inputOrder;
	Node<ElemType> *leftChild;
	Node<ElemType> *rightChild;
	std::string huffmanCode;
	// 构造函数:
	Node(ElemType newDate, int newInputOrder)
	{
		leftChild = rightChild = NULL;
		data = newDate;
		inputOrder = newInputOrder;
	}
};

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
	struct
	{
		int data;
		string huffmanCodes;
	} outputHuffmanCodes[1000];
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
			outputHuffmanCodes[node->inputOrder].data = node->data;
			outputHuffmanCodes[node->inputOrder].huffmanCodes = node->huffmanCode;
		}
	}
	for (int i = 1; i < 1000; ++i)
	{
		if (outputHuffmanCodes[i].huffmanCodes.length() == 0)
			break;
		cout << outputHuffmanCodes[i].data << " " << outputHuffmanCodes[i].huffmanCodes << endl;
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
		Node<int>* trees[1000];
		int treesCount = 0;
		int valueNum;
		int valueCount = 0;
		cin >> valueNum;
		while (++valueCount <= valueNum)
		{
			int value;
			cin >> value;
			trees[treesCount++] = new Node<int>(value, valueCount);
		}
//-----------------------------------------------------------
		//sort(trees.begin(), trees.end(), Greater);

		//while (trees.size() > 1)
		//{
		//	Node<int>* rightTree = trees.back();
		//	trees.pop_back();
		//	Node<int>* leftTree = trees.back();
		//	trees.pop_back();
		//	Node<int> *newNode = new Node<int>(leftTree->data + rightTree->data, -1);
		//	newNode->leftChild = leftTree;
		//	newNode->rightChild = rightTree;
		//	vector<Node<int>*>::iterator it;
		//	for (it = trees.begin(); it != trees.end(); ++it)
		//		if ((*it)->data < newNode->data)
		//			break;
		//	trees.insert(it, newNode);
		//}
		while (treesCount > 1)
		{
			int minIndex = -1;
			for (int i = treesCount - 1;i >= 0; --i)
			{
				if (minIndex == -1 || trees[i]->data < trees[minIndex]->data);
					minIndex = i;
			}
			if (minIndex != treesCount - 1)
			{
				Node<int>* temp = trees[minIndex];
				for (int i = minIndex; i < treesCount - 1; ++i)
					trees[i] = trees[i + 1];
				trees[treesCount - 1] = temp;
			}
			
			int minSecondIndex = -1;
			for (int i = treesCount - 1 - 1; i >= 0; --i)
			{
				if (minSecondIndex == -1 || trees[i]->data < trees[minSecondIndex]->data)
					minSecondIndex = i;
			}
			if (minSecondIndex != treesCount - 1 - 1)
			{
				Node<int>* temp = trees[minSecondIndex];
				for (int i = minSecondIndex; i < treesCount - 1 - 1; ++i)
					trees[i] = trees[i + 1];
				trees[treesCount - 1 - 1] = temp;
			}
			Node<int> *newNode = new Node<int>(trees[treesCount - 1 - 1]->data + trees[treesCount - 1]->data, -1);
			newNode->leftChild = trees[treesCount - 1 - 1];
			newNode->rightChild = trees[treesCount - 1];
			treesCount -= 2;
			
		}
//-----------------------------------------------------------
		cout << "Case " << caseCount << endl;
		ShowHuffmanCode();
		cout << endl;
	}
	
	
	system("pause");
	return 0;
}


