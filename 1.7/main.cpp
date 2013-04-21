#include <iostream>
#include <list>

void bam(int **array, const int col, const int row)
{
  int *zeroX = new int[col];
  int *zeroY = new int[row];

  for (int i=0; i<col; i++) {
    for (int j=0; j<row; j++) {
      if (array[i][j] == 0) { // 0 found 
        zeroX[i] = 1;
        zeroY[j] = 1;
      }
    }
  }

  for (int i=0; i<col; i++) {
    for (int j=0; j<row; j++) {
      if ((zeroX[i] == 1) || (zeroY[j] == 1)) {
        array[i][j] = 0;
      }
    }
  }
  delete zeroX;
  delete zeroY;
}

int main()
{
  int **array;
  const int M = 7;
  const int N = 6;

  array = new int* [M];
  
  for (int i = 0; i<M; i++) {
    array[i] = new int[N];
  }

  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      array[i][j] = i*j + 1;
    }
  }

  array[2][1] = 0;
  array[0][4] = 0;
 
  bam(array, M, N);
  
  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      std::cout << array[i][j] << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
