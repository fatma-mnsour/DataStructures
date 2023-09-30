// generate infix from expression tree
//page 287 last paragraph and page 388 first paragraph

#include <iostream.h>
#include <conio.h>

template <class type>
class BinaryTreeNode
{
	friend void Infix(BinaryTreeNode<type>*);
	friend void main(void);

	private:
		type data;
		BinaryTreeNode *LeftChild, *RightChild;
};

// Output infix form of expression.
template <class T>
void Infix(BinaryTreeNode<T> *t)
{
	if (t)
   	{
		cout << '(';
		Infix(t->LeftChild);  // left operand
		cout << t->data;      // operator
		Infix(t->RightChild); // right operand
		cout << ')';
	}
}

void main(void)
{
	BinaryTreeNode<int> x,y,z;

	x.data = 1; y.data = 2; z.data = 3;
	x.LeftChild = &y; x.RightChild = &z;
	y.LeftChild = y.RightChild = z.LeftChild = z.RightChild = 0;

	Infix(&x);

	getch();
}

/*
The Output:
-----------
((2)1(3))
*/