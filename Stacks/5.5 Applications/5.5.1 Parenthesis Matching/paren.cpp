// match parentheses

#include <iostream.h>
#include <string.h>//strlen
#include <stdio.h>
#include <conio.h>

#include "stack.h"

const int MaxLength = 100; // max expression length

// Parenthesis matching.
void PrintMatchedPairs(char *expr)
	{
   Stack<int> s(MaxLength);
   int j, length = strlen(expr);

   // scan expression expr for ( and )
   for (int i = 1; i <= length; i++)
   	{
      if (expr[i - 1] == '(')
      	s.Add(i);
      else if (expr[i - 1] == ')')
   		try
         	{
            s.Delete(j);  // unstack match
            cout << j << ' ' << i << endl;
            }
			catch (OutOfBounds)
         	{
            cout << "No match for right parenthesis" << " at " << i << endl;
            }
      }

   // remaining ( in stack are unmatched
   while (!s.IsEmpty())
   	{
      s.Delete(j);
      cout << "No match for left parenthesis at " << j << endl;
      }
	}

void main(void)
{
   char expr[MaxLength];
   cout << "Type an expression of length at most " << MaxLength << endl;
   cin.getline(expr, MaxLength);

   cout <<"The pairs of matching parentheses in" << endl;
   puts(expr);
   cout <<"are :" << endl;
   PrintMatchedPairs(expr);

   getch();
}

/*
The Input:
----------
(d+(a+b)*c*(d+e)-f))(()

The Output:
-----------
Type an expression of length at most 100
The pairs of matching parentheses in
(d+(a+b)*c*(d+e)-f))(()
are
4 8
12 16
1 19
No match for right parenthesis at 20
22 23
No match for left parenthesis at 21
*/
