// test linked queue class

#include <iostream.h>
#include <conio.h>
#include "lqueue.h"

void main(void)
	{
   LinkedQueue<int> Q;
   int x;

   try
   	{
   	Q.Add(1).Add(2).Add(3).Add(4);
	
	
	
	
	
	
	
	
	
	
	
      cout << "No queue add failed" << endl;
      }
   catch (NoMem)
      {
      cout << "A queue add failed" << endl;
      }
   cout << "Queue is now 1234" << endl;

   Q.Delete(x);
   cout << "Deleted " << x << endl;

   cout << Q.First() << " is at front" << endl;
   cout << Q.Last() << " is at end" << endl;

   try
   	{
      Q.Delete(x);
      cout << "Deleted " << x << endl;
	  
      Q.Delete(x);
      cout << "Deleted " << x << endl;
	  
      Q.Delete(x);
      cout << "Deleted " << x << endl;
      cout << "No queue delete failed " << endl;
	  
	  
	  
      }
   catch (OutOfBounds)
      {
      cout << "A delete has failed" << endl;
      }

   getch();
	}

/*
The Output:
-----------
No queue add failed
Queue is now 1234
Deleted 1
2 is at front
4 is at end
Deleted 2
Deleted 3
Deleted 4
No queue delete failed 
*/
