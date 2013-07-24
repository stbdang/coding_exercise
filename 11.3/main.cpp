#include <iostream>

// if it contains a rotation, it will have larger end than start
int findRotation(int array[], int start, int end)
{
  if ( start >= end )
    return start;
  
  int mid = (start+end)/2;

  if (array[mid] < array[start]) {
    if ( mid - start <= 1 ){
      return mid;
    }
    return findRotation(array, start, mid);
  } else if ( array[mid] > array[end] ) {
    if ( end-mid <= 1) {
     return end;
    }
    return findRotation(array, mid, end);
  }
  
  return 0;
}

int binarySearch(int array[], int start, int end, int value)
{
  if ( start >= end )
  { 
    if (array[start] == value)
      return start;
    return -1;
  }
  int mid = (start+end)/2;

  if ( array[mid] == value)
    return mid;
  else if (array[mid] > value)
    return binarySearch(array, start, mid - 1, value);
  else if (array[mid] < value)
    return binarySearch(array, mid + 1, end, value);

}

int main()
{
  int array[10] = {5, 6, 7, 8, 9, 10, 1, 2, 3, 4};
  int val = 2;

  int rot = findRotation(array, 0, 9);
  std::cout << "Rotation amount : " << rot << std::endl;

  int ans;

  ans = binarySearch(array, 0, rot - 1, val);

  if ( ans < 0 )
    ans = binarySearch(array, rot, 9, val);

  std::cout << "Index of " << val << " : " << ans <<std::endl;

  return 0;
}
