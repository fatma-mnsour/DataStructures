// test extended chain operations

#include <iostream.h>
#include "echain.h"
#include <conio.h>

void main(void)
{
   Chain<int> L;
   L.Insert(0,2).Insert(1,6);
   cout << "List is " << L << endl;

   L.Append(8);
   cout << "After appending 8, list is " << L << endl;

   L.Erase();
   cout << "After erase, list is " << L << endl;

   L.Append(1).Append(2).Append(3).Append(4);
   cout << "List is " << L << endl;

   L.Zero();
   cout << "After zero, list is " << L << endl;

   getch();
}

/*
The output

List is 2  6
After appending 8, list is 2  6  8
After erase, list is
List is 1  2  3  4
After zero, list is
*/
