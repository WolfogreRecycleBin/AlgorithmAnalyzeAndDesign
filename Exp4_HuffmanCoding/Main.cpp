#include <iostream>
#include "Node.h"
using namespace std;

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
		Node<int> *newNode = new Node<int>(firstMin->data + secondMin->data);
		newNode->leftChild = firstMin;
		newNode->rightChild = secondMin;
		trees[firstMinIndex] = newNode;
		trees[secondMinIndex] = NULL;
	}
	
	system("pause");
	return 0;
}


