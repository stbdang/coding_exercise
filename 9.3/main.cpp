#include <iostream>


// Find an index where A[i] == i in a sorted array. 
// why do we need recursion in this case? Just for practice? hmm.....
// It seems the question wants an algorithm better than O(n) -> O(log(n)). 
// Use BST since it's sorted..
int findMagicIndex(int array[], int start, int end)
{
  int index = (start + end) / 2;

  if (start >= end)
    return -1; //not found

  if (array[index] == index)
    return index;

  if (array[index] > index) // need to look at the left side
    return findMagicIndex(array, start, index -1);
  else
    return findMagicIndex(array, index + 1, end);
    
}

/* e.g.
  index 0  1  2  3  4  5  6  7  8  9
  val  -8 -6 -2  0  2  5  8 10 22 77

*/

int main() 
{

  int array[10] = {-8, -6, -2, 0, 2, 5, 5, 10, 22, 77};

  std::cout << "Magic index is " << findMagicIndex(array, 0, 9) << std::endl;

  return 0;
}
