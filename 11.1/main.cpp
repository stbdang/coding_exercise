#include <iostream>

int mergeTwoArrays(int a[], int lenA, int b[], int lenB)
{
  // it's better to start from end since if start from left, we need to shift all elements as we insert.
  int cursor = lenA + lenB;

  while (lenA > 0 && lenB > 0) {
    // here we add elements from end to the end of A.
    if (a[lenA-1] > b[lenB-1]) {
      a[cursor-1] = a[lenA-1];
      lenA--;
    } else {
      a[cursor-1] = b[lenB-1];
      lenB--;
    }
    cursor--;
  }

  // At this point, we might have used all A or B
  // If we used up all A, we need to copy remaining B to the start of A.
  // If we have remaing A but used up all B, we don't need to do anything (verify)

  while ( lenB > 0) {
    a[cursor-1] = b[lenB-1];
    lenB--;
    cursor--;
  }

  return 0;
  
}

int main()
{
  int a[] = { 0, 2, 5, 6, 9, 11, 14, 25, 26, 34, 0, 0, 0, 0, 0};
  int b[] = { 10, 12, 21, 22, 35 };

  mergeTwoArrays(a, 10, b, 5);

  int i=0;
  for (i = 0; i < sizeof(a) / sizeof(int); i++) {
    std::cout << a[i] << std::endl;
  } 


  return 0;
}


