// binary tree traversal methods

#include <iostream.h>
#include <conio.h>

#include "btnode1.h"
#include "lqueue.h"
#include "xcept.h"

//------------------------------------------------------------------------------
// Visit node *t, just output data field.
template <class T>
void Visit(BinaryTreeNode<T> *t)
{
	cout << t->data << ' ';
}
//------------------------------------------------------------------------------
// Preorder traversal of *t.
template <class T>
void PreOrder(BinaryTreeNode<T> *t)
{
	if (t)
   	{
		Visit(t);                 // visit tree root
		PreOrder(t->LeftChild);   // do left subtree
		PreOrder(t->RightChild);  // do right subtree
	}
}
//------------------------------------------------------------------------------
// Inorder traversal of *t.
template <class T>
void InOrder(BinaryTreeNode<T> *t)
{
	if (t)
   	{
		InOrder(t->LeftChild);   // do left subtree
		Visit(t);                // visit tree root
		InOrder(t->RightChild);  // do right subtree
	}
}
//------------------------------------------------------------------------------
// Postorder traversal of *t.
template <class T>
void PostOrder(BinaryTreeNode<T> *t)
{
	if (t)
   	{
		PostOrder(t->LeftChild);   // do left subtree
		PostOrder(t->RightChild);  // do right subtree
		Visit(t);                  // visit tree root
	}
}
//------------------------------------------------------------------------------
// Level-order traversal of *t.
/*
Let t be the tree root.
while (t != NULL)
{
    visit t 
	put its children on a FIFO queue;
    if FIFO queue is empty, 
		set t = NULL;
    otherwise, 
		pop a node from the FIFO queue and 
		call it t;
}

*/
template <class T>
void LevelOrder(BinaryTreeNode<T> *t)
{
	LinkedQueue<BinaryTreeNode<T>*> Q;
	while (t)
   	{
		Visit(t);  // visit t

		// put t's children on queue
		if (t->LeftChild) Q.Add(t->LeftChild);
		if (t->RightChild) Q.Add(t->RightChild);

		// get next node to visit
		try {Q.Delete(t);}
		catch (OutOfBounds) {return;}
	}
}
//------------------------------------------------------------------------------
void main(void)
{
	// create a binary tree with root x
	//Notice that main is a friend to the class BinaryTreeNode

	BinaryTreeNode<int> x, y, z;

	x.data = 1;
	y.data = 2;
	z.data = 3;

	x.LeftChild = &y;
	x.RightChild = &z;

	// traverse x in all ways

	cout << "Inorder sequence is ";
	InOrder(&x);
	cout << endl;

	cout << "Preorder sequence is ";
	PreOrder(&x);
	cout << endl;

	cout << "Postorder sequence is ";
	PostOrder(&x);
	cout << endl;

	cout << "Levelorder sequence is ";
	LevelOrder(&x);
	cout << endl;

	getch();
}
//------------------------------------------------------------------------------
/*
Notice:
-------
x.data = 1 implies x is
	1
0		0

y.data = 2 implies y is
	2
0		0

z.data = 3 implies z is
	3
0		0

x.LeftChild = &y implies x is
			1
	2				0
0		0

x.RightChild = &z implies x is
			1
	2				3
0		0		0		0
*/
//------------------------------------------------------------------------------
/*
The Output:
-----------
Inorder sequence is 2 1 3 
Preorder sequence is 1 2 3 
Postorder sequence is 2 3 1 
Levelorder sequence is 1 2 3
*/
//------------------------------------------------------------------------------