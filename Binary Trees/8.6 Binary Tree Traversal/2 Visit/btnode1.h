#ifndef BinaryTreeNode_
#define BinaryTreeNode_

template <class T> class BinaryTree;

template <class T>
class BinaryTreeNode
{
	friend void Visit(BinaryTreeNode<T> *);

	friend void InOrder(BinaryTreeNode<T> *);
	friend void PreOrder(BinaryTreeNode<T> *);
	friend void PostOrder(BinaryTreeNode<T> *);
	friend void LevelOrder(BinaryTreeNode<T> *);
   
	friend void main(void);

	public:
		BinaryTreeNode()
			{LeftChild = RightChild = 0;}
		BinaryTreeNode(const T& d)
			{data = d; LeftChild = RightChild = 0;}
		BinaryTreeNode(const T& d, BinaryTreeNode *l, BinaryTreeNode *r)
			{data = d; LeftChild = l; RightChild = r;}

   private:
		T data;
		BinaryTreeNode<T> *LeftChild, *RightChild;   // left subtree and right subtree
};

#endif