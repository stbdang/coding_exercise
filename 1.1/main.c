#include <stdio.h>
#include <string.h>

int hasDuplicate(char* str)
{
  int hasChar[sizeof(char)*256]; //This should be ok since we know the size of char at the compile time
  memset(hasChar, 0, sizeof(hasChar));

  int i;
  for (i = 0; i < strlen(str); i++)
  {
    if (hasChar[(unsigned int)str[i]])
      return 1;
    hasChar[(unsigned int)str[i]] = 1;
  }  

  return 0;

}

int main()
{
  char test[] = "I havegirlfnd.";

  printf("The string has %s\n", (hasDuplicate(test) ? "duplicates" : "no duplicate")); 

  return 0;
}
