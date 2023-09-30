// file cnode.h

#ifndef ChainNode_
#define ChainNode_

template <class T> class Chain;

template <class T>
class ChainNode
	{
   friend Chain<T>;
   
   private:
      T data;
      ChainNode<T> *link;
	};

#endif
