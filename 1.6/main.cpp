#include <iostream>

void printMat(int val[10][10])
{
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      std::cout << val[i][j] << " ";
    }
    std::cout << std::endl;
  }

}

void swapRowAndCol(int input[10][10])
{
  for (int i = 0; i < 10; i++ ) {
    for (int j = 0; j < i; j++ ) {
      int temp = input[i][j];
      input[i][j] = input[j][i];
      input[j][i] = temp;
    }
  } 
}

int main()
{
  int test[10][10];

  for (int i = 0; i < 10; i ++) {
    for (int j = 0; j < 10; j++) {
      test[i][j] = i*10 + j;
    }
  }
  printMat(test);
  
  swapRowAndCol(test);
  printMat(test);

  return 0;
}
