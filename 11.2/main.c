#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(char* a, char* b)
{
  unsigned valA=0, valB=0;

  int i;
  for(i=0; i < strlen(a); i++)
  {
    valA += (unsigned)a[i];
  }

  for(i=0; i < strlen(b); i++)
  {
    valB += (unsigned)b[i];
  }

  return valA < valB;
}

int merge( char* strings[], int start, int mid, int end)
{
  char** temp = (char**)malloc(sizeof(char*) * (end-start+1));
  
  int i;
  for (i = 0; i < end-start+1; i++) {
    temp[i] = strings[start+i];
  }

  i = 0;
  int j = mid-start;
  int count = 0;

  while ( (i < mid - start) && (j <= end - start))
  {
    if (compare(temp[i], temp[j])) {
      strings[count+start] = temp[i];
      i++;
    } else { // we swap contents in i with j, then move i forward
      strings[count+start] = temp[j];
      j++;
    }
    count++;
  }

  while ( i < mid-start) {
    strings[start+count] = temp[i];
    i++;
    count++;
  }

  free(temp);

}

int mergeSort(char* strings[], int startInd, int endInd)
{
  if ( startInd >= endInd )
    return 0;

  int mid = (startInd + endInd)/2;

  mergeSort(strings, startInd, mid); 
  mergeSort(strings, mid + 1, endInd);
  merge(strings, startInd, mid+1, endInd); 

}

int main()
{
  char* strings[10];
  int i;

  for (i = 0; i < 10; i++)
  {
    strings[i] = (char*)malloc(10);
    memset(strings[i], 0, 10);
  } 

  strcpy(strings[0], "abcd");
  strcpy(strings[1],"abcd11");
  strcpy(strings[2], "ab2");
  strcpy(strings[3], "afdf");
  strcpy(strings[4], "ssdsgs");
  strcpy(strings[5], "3trhtr");
  strcpy(strings[6], "danel");
  strcpy(strings[7], "bdca");
  strcpy(strings[8], "2ba");
  strcpy(strings[9], "dddkkk");


  for (i=0; i<10; i++)
  {
    printf("%s\n", strings[i]);
  }


  mergeSort(strings, 0, 9);
  printf("Now sorted!!! \n");

  for (i=0; i<10; i++)
  {
    printf("%s\n", strings[i]);
  }

  return 0;
}
