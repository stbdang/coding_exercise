#include <stdio.h>



int fitMe(int N, int M, int i, int j)
{
  M = M << i;
  //Make mask
  int mask =(~0 << (j+1)) | ((1 << i) - 1);
  printf("Mask : %x\n", mask);

  return (N & mask) | M;

}

int main()
{
  int N = 0b10000000000;
  int M = 0b10011;
  int i = 2;
  int j = 6;

  int answer = fitMe(N, M, i, j);

  printf("Answer : %x\n",  answer);


  return 0;
}

