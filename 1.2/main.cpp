#include <iostream>
#include <string.h>

// Excercise 1.2 - Reverse a char array
// 1. Can't we swap from first and the last until we propagate to the middle?

void reverseChar(char* str)
{
  int len = strlen(str); // get the length

  for (int i=0; i < len/2; i++) {
    //swap ith and (len - i - 1) th characters
    char temp = str[i];
    str[i] = str[len-i-1];
    str[len-i-1] = temp;
  }


  // e,g if str = "ABCD" -> len = 4 so it will swap 0,3 and 1,2
  // str = "ABCDE" -> len = 5 swap 0,4 and 1,3
}


int main()
{
  char test[] = "This is a test string for excercise 1.2";

  std::cout << "Input : " << test << std::endl;

  reverseChar(test);

  std::cout << "Output : " << test << std::endl;

  return 0;

}
