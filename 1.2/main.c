#include <stdio.h>
#include <string.h>

int reverse(char* str)
{
  int i;
  int len = strlen(str);

  for (i=0; i < len/2; i++)
  {
    char temp = str[i];
    str[i] = str[len - i -1];
    str[len-i -1] = temp;
  }

  return 0;
}

int main()
{
  char test[] = "This string will be reversed";

  printf("Original string : %s\n", test);
  reverse(test);
  printf("Reversed string : %s\n", test);

  return 0;


}
