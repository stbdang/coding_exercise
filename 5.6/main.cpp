#include <iostream>

int findMissingInteger(int A[])
{
  // Only accessing individual bit of A[i] is allowed : try to find an O(n) algorithm
  // Adding all values to find the missing on is O(n log(n)) - not good enough!
  // If A was sorted, it becomes too easy (last bit always alternates)
  // Let's try to find a pattern here. Start with a simple example (of say 0 to 4?)

  // 000 001 010 011 100 <- we will use this example for now.
  // bit operations of each numbers might reveal something...XOR?

  // I don't think there's any point operating on bits that are not at the same location. (bit 1 of first and bit 2 of second doesn't seem to give us anything) 
  // Let's try to XOR everything
  // bit 0 -> 0
  // bit 1 -> 0
  // bit 2 -> 1
  // ....does it make any sense?...

  // Try something simpler
  // 0 to 2
  // 00 01 10 
  // 0 -> 1
  // 1 -> 1

  // Hmmm?
  // 00 01 10 11
  // 0 -> 0
  // 1 -> 0

  // Try missing
  // 00 10 11 (01 missing)
  // 0 -> 1
  // 1 -> 0
  // 01 XOR with 11 -> 10...wtf.
  // WTF

  // But
  // 00 01 (10 missing)
  // 01 -> XOR with 10 -> 10...?

  // inconclusive...meh

  // Let's think logically about this
  // if the number is from 0 to N, if we XOR each bits, it counts how many ones (am I right?) in each bits
  // we can find the XOR of each bits immediately because we know how many ones we have from 0 to N.
  // e.g. bit 0 -> (N / 2)%2 ...etc
  // If we XOR the whole array, we can use it to find the missing value, but this isn't good enough since it's still O(n log(n))
  
  // is there any way we can use constant-pass instead of log(n) pass? how? (unless we have a hard bound on N)

  // Found it! we can start from bit 0 and prune out what we don't need.. It means we need a table to track what we need/don't need

  // lets use example 0-7 
  // 000 001 010 011 100 101 110 111 -> say 011 is missing (3)

  // we know ans must be (if all exists) 000


  // bit 0 -> 1 (we now know the missing number has bit 0 set "xx1")
  // we can discard all numbers that ends with 0 because it doesn't matter.

  // going thru numbers that ends with 1, we find how many ones in bit 1 -> 1
  // again, we know

  

  int *notInterested = new int [sizeof(A)];

  int N = sizeof(A) + 1;
  int ans = 0;
  int shift = 0;

  while (N){
    N >> 1;
    ans |= (N % 2) dd<< shift;
    shift++;
  }

  N = sizeof(A);

  for (int j = 0; j < shift; j++) {

    int result = 0;
    for (int i = 0; i < N; i++)
    {
      if ( !notInterested[i] ) {
        result ^= getBit(A, i, j);

      }
    }
  }
}

int main()
{

  return 0;
}
