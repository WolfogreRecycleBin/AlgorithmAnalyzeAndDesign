#ifndef __NODE_H__
#define __NODE_H__

// 结点类
template <class ElemType>
struct Node 
{
// 数据成员:
	ElemType data;				// 数据域
	Node<ElemType> *leftChild;
	Node<ElemType> *rightChild;

// 构造函数:
	Node(ElemType newDate)
	{
		leftChild = rightChild = NULL;
		data = newDate;
	}
};

#endif
