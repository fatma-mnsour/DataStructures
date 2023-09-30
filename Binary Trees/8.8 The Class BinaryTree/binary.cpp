// test binary tree class

#include <iostream.h>
/*
The code constructs a four-node binary tree and then perorms a 
preorder traversal to detremine the number of nodes in the tree.
*/

#include <conio.h>
#include "binary.h"

// globals
int count = 0;


template<class T>
void ct(BinaryTreeNode<T> *t)
	{count++;}

void main(void)
{
	BinaryTree<int> a,x,y,z;

	y.MakeTree(1,a,a);
	z.MakeTree(2,a,a);
	x.MakeTree(3,y,z);
	y.MakeTree(4,x,a);

	y.PreOrder(ct);
	cout << "Using PreOrder; Count of nodes is " << count << endl;

	count=0;
	y.InOrder(ct);
	cout << "Using InOrder; Count of nodes is " << count << endl;

	count=0;
	y.PostOrder(ct);
	cout << "Using PostOrder; Count of nodes is " << count << endl;

	count=0;
	y.LevelOrder(ct);
	cout << "Using LevelOrder; Count of nodes is " << count << endl;

	getch();
}

/*
Notice:
-------
y.MakeTree(1,a,a) implies y is
	1
0		0

z.MakeTree(2,a,a) implies z is
	2
0		0

x.MakeTree(3,y,z) implies x is
				3
	  1				  2
0			0		0			0

y.MakeTree(4,x,a) implies y is
									4
				3									0
	  1				  2
0			0		0			0

*/

/*
The Output:
-----------
Using PreOrder; Count of nodes is 4
Using InOrder; Count of nodes is 4
Using PostOrder; Count of nodes is 4
Using LevelOrder; Count of nodes is 4
*/
