#ifndef __NODE_H__
#define __NODE_H__
#include <string>
// �����
template <class ElemType>
struct Node 
{
// ���ݳ�Ա:
	ElemType data;				// ������
	int inputOrder;
	Node<ElemType> *leftChild;
	Node<ElemType> *rightChild;
	std::string huffmanCode;
// ���캯��:
	Node(ElemType newDate, int newInputOrder)
	{
		leftChild = rightChild = NULL;
		data = newDate;
		inputOrder = newInputOrder;
	}
};

#endif
