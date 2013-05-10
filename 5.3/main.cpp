#include <iostream>

int findNumberOfOnes(int val)
{
  int retval = 0;
  for (int i =0 ; i < sizeof(int)*8; i++)
  {
    int mask = 1 << i;

    retval += ((val & mask) ? 1 : 0);

  }
  return retval;
}

int findNext(int val, int direction)
{
  int count = findNumberOfOnes(val);
  int runningCount = 0;  

  do {
    if (direction)
      val++;
    else
      val--;

    runningCount = findNumberOfOnes(val);
  } while (runningCount != count && val > 0);

  return val;
}
/*
   e.g. 1111010110000

   To maintain the same number of ones and zeros, if zero is flipped, one needs to be fliped too.
   If we flip 1 one and 1 zero, the number will increase only when one is on the left side of zero.
   
   Because we need to flip 1 one to zero, we need to make sure zero to one flip happens at the left of one to zero.

   To minimize the number increase, zero to one should happen at the rightmost 0 after ones.

   111101 1 110000 <- need to have only one one in this segment. (minimum is when 1 is at the rightmost side);
   
   1. Find where 1 starts <- i
   2. Find where 0 starts (after 1 ended) <- we swap here. <- j
   3. Push the 1s to the rightmost side.  (number of 1s = j-i-1) -> right shift by i

  
*/
int findNextBetter(int val)
{
  int c = val;
  int retval = val;
  int i = 0;
  int j = 0;

  while(!(c&1)) {
    c = c>>1;
    i++;
  }

  std::cout << i << std::endl;
  while(c&1) {
    c = c >> 1;
    j++;
  }
  std::cout << j << std::endl;

  retval += (1<<i) + (1 << (j-i-1)) - 1; 

  return retval;
}

/*

1110011 -> 1101110 

  j i

need to do zero to one on the right of one to zero.
*/

int findPrevBetter(int val)
{
//find when 0 starts
  int c = val;
  int i = 0;
  int j = 0;

  while (c&1) {
    c = c>>1;
    i++;
  }

  while (!(c&1)) {
    c = c >> 1;
    j++;
  }

  val -= (1 << (j+i)) + (1<<i) - 1;
  std::cout << val << std::endl;
  val += ((1 << (i+1)) - 1) << (j-1);
  return val;
  
  
}


int main()
{
  int num = 123;

  std::cout << "Number of ones in " << num << " is " << findNumberOfOnes(num) << std::endl;
  
  std::cout << "Next higher num is " << findNext(num, 1) << std::endl;
  std::cout << "Next higher num is " << findNextBetter(num) << std::endl;
  std::cout << "Next lower num is " << findNext(num, 0) << std::endl;
  std::cout << "Next lower num is " << findPrevBetter(num) << std::endl;

  return 0;

}
