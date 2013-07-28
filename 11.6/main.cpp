#include <iostream>
/* 11.6 Find an element in an M x N 2D array, sorted in rows and columns

  This is an essentially the same problem as finding an element in an 1D array. 

  Let's use an example (5x3 array)
  
  0  1  2  3  4
  5  6  7  8  9
  10 11 12 13 14  -> very simple but this 2D array is "valid". But this example might not reveal some corner cases.

  Let's have an interleaved one

  0  2  4  6  8
  1  3  5  7  9
  10 11 12 13 14


  Let's say we need to find an elem "3"
  Seems we can't really use "box" approach. Maybe "start of each row" -> not gonna work.

  BUT, we can use exclude box approach, we know since it's sorted any elem E1 (at (x1, y1) where x1>=x & y1>=y) is >= than E(x,y)
  

  HINT : First and Last (min and max)

*/


int main()
{

  return 0;
}
