// file binary.h

#ifndef BinaryTree_
#define BinaryTree_

#include<iostream.h>
#include "lqueue.h"
#include "btnode2.h"
#include "xcept.h"

template<class T>
class BinaryTree
{
	public:
		BinaryTree() {root = 0;};
		BinaryTree(BinaryTreeNode<T> *u)
		{root = u;}
		~BinaryTree(){};

		bool IsEmpty() const
			{return ((root) ? false : true);}
		bool Root(T& x) const;

		void MakeTree(const T& element, BinaryTree<T>& left, BinaryTree<T>& right);
		void BreakTree(T& element, BinaryTree<T>& left, BinaryTree<T>& right);

		void PreOrder(void(*Visit)(BinaryTreeNode<T> *u));
		void InOrder(void(*Visit)(BinaryTreeNode<T> *u));
		void PostOrder(void(*Visit)(BinaryTreeNode<T> *u));
		void LevelOrder(void(*Visit)(BinaryTreeNode<T> *u));

	private:
		BinaryTreeNode<T> *root;  // pointer to root
};

template<class T>
bool BinaryTree<T>::Root(T& x) const
{
// Return root data in x. Return false if no root.
	if (root)
	{
		x = root->data;
		return true;
	}
	else
		return false;  // no root
}

template<class T>
void BinaryTree<T>::MakeTree(const T& element, BinaryTree<T>& left, BinaryTree<T>& right)
{
   // Combine left, right, and element to make new tree.
	// left, right, and this must be different trees.
   // create combined tree
   root = new BinaryTreeNode<T> (element, left.root, right.root);

   // deny access from trees left and right
   left.root = right.root = 0;
}

template<class T>
void BinaryTree<T>::BreakTree(T& element, BinaryTree<T>& left, BinaryTree<T>& right)
{
	// left, right, and this must be different trees.

	if (!root) throw BadInput(); // check if empty. Tree empty

	// break the tree
	element = root->data;
	left.root = root->LeftChild;
	right.root = root->RightChild;

	delete root;
	root = 0;
}

template<class T>
void BinaryTree<T>::PreOrder(void(*Visit)(BinaryTreeNode<T> *u))
{
	// Preorder traversal.
	if (root)
	{
		Visit(root);
		((BinaryTree)(root->LeftChild)).PreOrder(Visit); // Type casting from BinaryTreeNode to BinaryTree using the second constructor
		((BinaryTree)(root->RightChild)).PreOrder(Visit); // Type casting from BinaryTreeNode to BinaryTree using the second constructor
	}
}

template <class T>
void BinaryTree<T>::InOrder(void(*Visit)(BinaryTreeNode<T> *u))
{
	// Inorder traversal.
	if (root)
	{
		((BinaryTree)(root->LeftChild)).InOrder(Visit); // Type casting from BinaryTreeNode to BinaryTree using the second constructor
		Visit(root);
		((BinaryTree)(root->RightChild)).InOrder(Visit); // Type casting from BinaryTreeNode to BinaryTree using the second constructor
	}
}

template <class T>
void BinaryTree<T>::PostOrder(void(*Visit)(BinaryTreeNode<T> *u))
{
	// Postorder traversal.
	if (root)
	{
		((BinaryTree)(root->LeftChild)).PostOrder(Visit); // Type casting from BinaryTreeNode to BinaryTree using the second constructor
		((BinaryTree)(root->RightChild)).PostOrder(Visit); // Type casting from BinaryTreeNode to BinaryTree using the second constructor
		Visit(root);
	}
}

template <class T>
void BinaryTree<T>::LevelOrder(void(*Visit)(BinaryTreeNode<T> *u))
{
	// Level-order traversal.
	LinkedQueue<BinaryTreeNode<T>*> Q;
	BinaryTreeNode<T> *t;
	t = root;
	while (t)
	{
		Visit(t);
		if (t->LeftChild) Q.Add(t->LeftChild);
		if (t->RightChild) Q.Add(t->RightChild);
		try {Q.Delete(t);}
		catch (OutOfBounds) {return;}
	}
}

#endif