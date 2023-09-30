// railroad car rearrangement using queues

#include <iostream.h>
#include <conio.h>
#include "lqueue.h"

//------------------------------------------------------------------------------------------------------------
// Move from hold to output and update minH and minQ.
void Output(int& minH, int& minQ, LinkedQueue<int> H[], int k, int n)
	{
   // delete smallest car minH from queue minQ
   int c;  // car index
   H[minQ].Delete(c);
   cout << "Move car " << minH << " from holding track " << minQ << " to output" << endl;

   // find new minH and minQ by checking front of all queues
   minH = n + 2; //at first make the minH which holds the smallest car in a track to be the maximum car index.
   for (int i = 1; i <= k; i++)
      if ( (!H[i].IsEmpty()) && (H[i].First() < minH) )
      	{
         minH = H[i].First();
         minQ = i;
         }
	}
//------------------------------------------------------------------------------------------------------------
// Add car c to a holding track.
// Return false if no feasible holding track.
// Throw NoMem exception if no queue space.
// Return true otherwise.
bool Hold(int c, int& minH, int &minQ,	LinkedQueue<int> H[], int k)
	{
   // find best holding track for car c
   // initialize
   int BestTrack = 0,  // best track so far
       BestLast = 0,   // last car in BestTrack
       x;              // a car index

   // scan holding tracks to find the best track to put the car number c
   for (int i = 1; i <= k; i++)
      if (!H[i].IsEmpty())
      	{
         // track i not empty
         x = H[i].Last();
         if (c > x && x > BestLast)
         	{
            // track i has bigger car at end
   	    	BestLast = x;
            BestTrack = i;
            }
         }
      else
      	// track i empty
         if (!BestTrack) BestTrack = i;
      
   if (!BestTrack) return false; // no track available
   
   // add c to best track
   H[BestTrack].Add(c);
   cout << "Move car " << c << " from input " << "to holding track " << BestTrack << endl;

   // update minH and minQ if needed
   if (c < minH)
   	{
      minH = c;
      minQ = BestTrack;
      }

   return true;
	}
//------------------------------------------------------------------------------------------------------------
// k track rearrangement of car order p[1:n].
// Return true if successful, false if impossible.
// Throw NoMem exception if inadequate space.
bool Railroad(int p[], int n, int k)
	{
   // create queues for holding tracks
   LinkedQueue<int> *H;
   H = new LinkedQueue<int> [k];
   k--; // keep track k open for direct moves???????????????

   int NowOut = 1;   // next car to output
   int minH = n+1;   // smallest car in a track
   int minQ;         // track with car minH

   // rearrange cars
   // start from the begining car in the input queue
   for (int i = 1; i <= n; i++)
      if (p[i] == NowOut)
      	{
         // This car in the one to be output
         cout << "Move car " << p[i] << " from input to output" << endl;
         NowOut++; // now we need car number NewOut

         // chack the holding tracks to output cars from it
         while (minH == NowOut)
         	{
            Output(minH, minQ, H, k, n);
   	    	NowOut++; // now we need car number NewOut
            }
         }
      else
      	// put car p[i] in a holding track and update minH and minQ
      	{
         if (!Hold(p[i], minH, minQ, H, k)) return false;
         }

   return true;
	}
//------------------------------------------------------------------------------------------------------------
void main(void)
	{
   // int p[10] = {0, 5, 8, 1, 7, 4, 2, 9, 6, 3};
   int p[10] = {0, 3, 6, 9, 2, 4, 7, 1, 8, 5};
   cout << "Input permutation is 0369247185" << endl;
   Railroad(p,9,3);
   getch();
	}
//------------------------------------------------------------------------------------------------------------
/*
The Output:
-----------
Input permutation is 0369247185
Move car 3 from input to holding track 1
Move car 6 from input to holding track 1
Move car 9 from input to holding track 1
Move car 2 from input to holding track 2
Move car 4 from input to holding track 2
Move car 7 from input to holding track 2
Move car 1 from input to output
Move car 2 from holding track 2 to output
Move car 3 from holding track 1 to output
Move car 4 from holding track 2 to output
Move car 8 from input to holding track 2
Move car 5 from input to output
Move car 6 from holding track 1 to output
Move car 7 from holding track 2 to output
Move car 8 from holding track 2 to output
Move car 9 from holding track 1 to output
*/
