#ifndef __NODE_H__
#define __NODE_H__

// �����
template <class ElemType>
struct Node 
{
// ���ݳ�Ա:
	ElemType data;				// ������
	Node<ElemType> *leftChild;
	Node<ElemType> *rightChild;

// ���캯��:
	Node(ElemType newDate)
	{
		leftChild = rightChild = NULL;
		data = newDate;
	}
};

#endif
