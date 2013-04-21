#include <iostream>

void shiftStr(char* str, int start, int end, int shift)
{
  for (int i = end - 1; i >= start; i--) { // s=5 , len = 21, 
    str[i+shift] = str[i];
  }
}

void replaceSpaces(char* str, int* len)
{
  for (int i=0; i<*len; i++) {
    if (str[i] == ' ') //found the space   i=4
    {
      str[i] = '%';
      // shift the string back 2.
      shiftStr(str, i+1, *len, 2);
      str[i+1] = '2';
      str[i+2] = '0';
      *len = *len+2;
      i = i+2;
    }
  }
}

int main()
{
  char test[] = "This is a te st s tr ing hahaha meeeee                  ";
  int trueLength = 38;

  replaceSpaces(test, &trueLength);

  std::cout << test << std::endl;
  

}
