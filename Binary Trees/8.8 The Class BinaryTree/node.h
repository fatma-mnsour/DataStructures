#ifndef Node_
#define Node_

template <class T> class BinaryTreeNode;

template <class T>
class Node
{
	friend BinaryTreeNode<T>;
	private:
		T data;
		Node<T> *link;
};

#endif