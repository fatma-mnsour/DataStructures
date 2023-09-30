// header file lstack.h
#ifndef LinkedStack_
#define LinkedStack_

#include "chain.h"
#include "xcept.h"

template<class T>
class LinkedStack : private Chain<T>
	{
	public:
   	bool IsEmpty() const {return Chain<T>::IsEmpty();}
   	bool IsFull() const;
   	T Top() const
      	{
         if (IsEmpty()) throw OutOfBounds();
       	T x;
         Find(1, x); return x;
         }
   	LinkedStack<T>& Add(const T& x) {Insert(0,x); return *this;}
   	LinkedStack<T>& Delete(T& x) {Chain<T>::Delete(1,x); return *this;}
	};

/*
The implementation of ISFull is inelgant because the only way to know
whether or not we can add an element to a stack is to see whether enough
space exists to create a node of type ChainNode. This check is done by
invoking the new operator on the type ChainNode and then deleteing the
created node as we do not intend to use it.
*/
template<class T>
bool LinkedStack<T>::IsFull() const
	{
   //Is stack full?
   try
   	{
      ChainNode<T> *p = new ChainNode<T>;
      delete p;
      return false;
      }
   catch (NoMem) {return true;}
	}

#endif;
