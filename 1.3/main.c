#include <stdio.h>
#include <string.h>

int isPermutation(char* str1, char* str2)
{
  int tally[sizeof(char)*256];

  memset(tally, 0, sizeof(tally));

  int i;
  for(i = 0; i<strlen(str1); i++) {
    tally[str1[i]]++;
  }

  for (i=0; i<strlen(str2); i++) {
    tally[str2[i]]--;
  }

  int sign =0;
  for (i=0; i<sizeof(char)*256; i++) {
    if(sign==0 && tally[i] != 0)
      sign = tally[i] > 0 ? 1 : -1;
    else if (sign * tally[i] < 0)
      return 0;
  }

  return 1;

}


int main()
{
  char test1[] = "hahahahammmeneenn";
  char test2[] = "hahamennn";

  printf("%s and %s are %s permutation of the other\n", test1, test2, (isPermutation(test1, test2) ? "a" : "not a" ) );

  return 0;
}
