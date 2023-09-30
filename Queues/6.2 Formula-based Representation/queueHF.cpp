// test formula based queue class

#include <iostream.h>
#include <conio.h>
#include "queue.h"

void main(void)
{
   Queue<int> Q(3);
   int x;
   
   try
   	{
   	  Q.Add(1);
      cout<< "Queue Length after adding 1: " << Q.Length() << endl;
      Q.Add(2);
      cout<< "Queue Length after adding 2: " << Q.Length() << endl;
      Q.Add(3);
      cout<< "Queue Length after adding 3: " << Q.Length() << endl;
      Q.Add(4);
      cout << "No queue add failed" << endl;
      cout<< "Queue Length after tring adding 4: " << Q.Length() << endl;
      }
   catch (NoMem)
      {
      cout << "A queue add failed" << endl;
      }
   cout << "Queue is now 123" << endl;

   Q.Delete(x);
   cout << "Deleted " << x << endl;
   cout<< "Queue Length after deleting: " << Q.Length() << endl;

   cout << Q.First() << " is at front" << endl;
   cout << Q.Last() << " is at end" << endl;

   try
   	{
      Q.Delete(x);
      cout << "Deleted " << x << endl;
      cout<< "Queue Length after deleting: " << Q.Length() << endl;
      Q.Delete(x);
      cout << "Deleted " << x << endl;
      cout<< "Queue Length after deleting: " << Q.Length() << endl;

      Q.Add(4).Add(5);
      cout<< "Queue Length after adding 4 and 5: " << Q.Length() << endl;

      Q.Delete(x);
      cout << "Deleted " << x << endl;
      cout<< "Queue Length after deleting: " << Q.Length() << endl;

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
Queue Length after adding 1: 1
Queue Length after adding 2: 2
Queue Length after adding 3: 3
A queue add failed
Queue is now 123
Deleted 1
Queue Length after deleting: 2
2 is at front
3 is at end
Deleted 2
Queue Length after deleting: 1
Deleted 3
Queue Length after deleting: 0
Queue Length after adding 4 and 5: 2
Deleted 4
Queue Length after deleting: 1
No queue delete failed
*/
