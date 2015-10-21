#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

template <class ElemType>
struct Node
{
	ElemType data;
	int inputOrder;
	Node<ElemType> *leftChild;
	Node<ElemType> *rightChild;
	string huffmanCode;
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
		while (treesCount > 1)
		{
			int minIndex = -1;
			for (int i = treesCount - 1;i >= 0; --i)
			{
				if (minIndex == -1 || trees[i]->data < trees[minIndex]->data)
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

			int last;
			for (last = treesCount - 1; last >= 0; --last)
			{
				if (trees[last]->data >= newNode->data)
					break;
			}

			for (int i = treesCount - 1; i > last; --i)
			{
				trees[i + 1] = trees[i];
			}
			
			trees[last + 1] = newNode;
			++treesCount;

		}
//-----------------------------------------------------------
		cout << "Case " << caseCount << endl;
		ShowHuffmanCode(trees[0]);
		cout << endl;
	}
	
	system("pause");
	return 0;
}


