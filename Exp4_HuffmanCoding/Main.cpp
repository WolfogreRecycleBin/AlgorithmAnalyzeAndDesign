#include <iostream>
#include <vector>
#include "Node.h"
using namespace std;

void ShowTree(Node<int>  *root)
{
	if (root == NULL)
		return;
	ShowTree(root->leftChild);
	cout << root->data << " ";
	ShowTree(root->rightChild);
}

void ShowHuffmanCode(Node<int>  *root, vector<int> &code)
{
	bool isLeef = true;
	if (root->leftChild != NULL)
	{
		isLeef = false;
		code.push_back(0);
		ShowHuffmanCode(root->leftChild, code);
		code.pop_back();
	}
	if (root->rightChild != NULL)
	{
		isLeef = false;
		code.push_back(1);
		ShowHuffmanCode(root->rightChild, code);
		code.pop_back();
	}
	if (isLeef)
	{
		cout << root->data << " ";
		for (auto it : code)
			cout << it;
		cout << endl;
	}
}

int main(void)
{
	
	Node<int>  **trees = new Node<int> *[100];
	int value[] = { 1, 2, 3, 4, 5, 6 };
	for (int i = 0; i < 6; ++i)
		trees[i] = new Node<int>(value[i]);
	for (int i = 1; i <= 5; ++i)
	{
		Node<int> *firstMin = NULL;
		Node<int> *secondMin = NULL;
		int firstMinIndex = -1;
		int secondMinIndex = -1;
		for (int index = 0; index < 6; ++index)
		{
			if (trees[index] != NULL)
			{
				if (secondMin == NULL ||  trees[index]->data < secondMin->data)
				{
					secondMin = trees[index];
					secondMinIndex = index;
				}
				if (firstMin == NULL || secondMin->data < firstMin->data)
				{
					Node<int> *temp = firstMin;
					int tempIndex = firstMinIndex;
					firstMin = secondMin;
					firstMinIndex = secondMinIndex;
					secondMin = temp;
					secondMinIndex = tempIndex;
				}
			}
		}
		if (firstMinIndex > secondMinIndex)
		{
			Node<int> *temp = firstMin;
			int tempIndex = firstMinIndex;
			firstMin = secondMin;
			firstMinIndex = secondMinIndex;
			secondMin = temp;
			secondMinIndex = tempIndex;
		}
		//cout << firstMin->data << " " << secondMin->data << endl;
		Node<int> *newNode = new Node<int>(firstMin->data + secondMin->data);
		newNode->leftChild = firstMin;
		newNode->rightChild = secondMin;
		trees[firstMinIndex] = newNode;
		trees[secondMinIndex] = NULL;
	}
	//for (int i = 0; i < 6; ++i)
	//{
	//	ShowTree(trees[i]);
	//	cout << endl;
	//}
	for (int i = 0; i < 6; ++i)
	{
		if (trees[i] != NULL)
		{
			vector<int> code;
			ShowHuffmanCode(trees[i], code);
			break;
		}
	}
	system("pause");
	return 0;
}


