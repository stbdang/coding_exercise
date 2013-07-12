#include <iostream>
#include <string.h>

int getBit(int A[], int i, int j)
{
  std::cout << i << "th elem is " << A[i] << std::endl;
  return (A[i] & (1 << j)) ? 1 : 0;
}

int findMissingInteger(int A[], int N)
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

  // We know how many 1s at bit 0 needs to be present (N / 2 = 4)

  // count number of 1s, we wiil find 3 -> bit 0 is 1

  // We know we have all of number which ends with 0, we can caculate how many ones in bit 1 for those number (N / 4 = 2)

  // We also know how many ...... Isn't this too complicated?

  // Try the first loop
  
  int missingNum = 0;

  int cursor = 0;
 
  int notInterested[N];

  memset(notInterested, 0, sizeof(notInterested));

  std::cout << "Upper boundary : " << N << std::endl;

  while (N >> cursor) {
  
    std::cout << "Looking at bit " << cursor << std::endl;
    int numOnes;

    if (cursor == 0)
      numOnes = (N) / 2;
    else {// general case
      int chunk = (2 << cursor);
      numOnes = (N) / chunk;
      int rem = (N) % chunk;
      if ( rem >= (missingNum | (1 << cursor)))
        numOnes ++; 
    }

    std::cout << "Number of ones should be " << numOnes << std::endl;
    int count = 0;

    for (int i = 0; i < N; i++)
    {
      if (!notInterested[i]) {
        if (getBit(A, i, cursor))
          count++;
      }
    }

    std::cout << "Ones counted " << count << std::endl;
    missingNum |= (numOnes - count) << cursor;

    for (int i = 0; i < N; i++)
    {
      if (!notInterested[i]) {
        if (getBit(A,i,cursor) != (numOnes - count))
          notInterested[i] = 1;
      }
    }
    cursor++;
  }

  return missingNum;

}

int main()
{
  int N = 100;
  int omit = 34;

  int A[N];
  int ind = 0;

  for (int i=0; i<N+1; i ++ ) {
    if (i != omit) {
      A[ind] = i;
      ind++;
    }  
  }


  std::cout << "Missing num is " << findMissingInteger(A, N) << std::endl;

  return 0;
}
