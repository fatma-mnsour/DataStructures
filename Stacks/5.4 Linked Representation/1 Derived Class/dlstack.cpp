// test derived linked stack

#include <iostream.h>
#include <conio.h>

#include "dlstack.h"

void main(void)
	{
   int x;
   LinkedStack<int> S;

	//Niether add nor delete catch the exception that mieght be thrown by Insert or LinearList<T>::Delete

   try
   	{
      S.Add(1).Add(2).Add(3).Add(4);
      }
   catch (NoMem)
   	{
      cout << "Could not complete additions" << endl;
      }

   cout << "Stack should be 1234" << endl;
   cout << "Stack top is " << S.Top() << endl;

   try
   	{
      S.Delete(x);
      cout << "Deleted " << x << endl;
      S.Delete(x);
      cout << "Deleted " << x << endl;
      S.Delete(x);
      cout << "Deleted " << x << endl;
      S.Delete(x);
      cout << "Deleted " << x << endl;
      }
   catch (OutOfBounds)
   	{
      cout << "Last delete failed " << endl;
      }

   getch();
}

/*
The Output:
-----------
Stack should be 1234
Stack top is 4
Deleted 4
Deleted 3
Deleted 2
Deleted 1
*/
