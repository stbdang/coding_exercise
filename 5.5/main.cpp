#include <iostream>

int findNumberOfChanges(int num1, int num2)
{
  int retval=0;
  for (int i = num1 ^ num2; i != 0; i = i&(i-1))
    retval++;
  
  return retval;

}

void printBinary(int num, std::string& out)
{
  for (int i = num; i!=0; i = i >> 1) {
    if (i&1)
      out.insert(0, "1");
    else
      out.insert(0, "0");
  }
}

int main()
{
  int num1 = 101;
  int num2 = 100;

  std::string meh;
  std::string meh2;

  printBinary(num1, meh);
  printBinary(num2, meh2);

  std::cout << num1 << " : " << meh << std::endl;
  std::cout << num2 << " : " << meh2 << std::endl;

  std::cout << "Num " << num1 << " and " << num2 << " requires " << findNumberOfChanges(num1, num2) << " changes" << std::endl;
  return 0;
}
