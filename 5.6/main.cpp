#include <iostream>

int swapEvenAndOdd(int number)
{
  //So now, I don't really want to do this but I'll give it a shot.
  // Problem statement: let's give it an example
  // eg. 9 -> 1001 , this becomes 0110 -> 6
  // e.g. 11011000101 -> 1733 becomes 100111001010 -> 2506
  // We can create a comb to just get even and odd bits, then shift odd up by 1 and shift even down by 1.


  int comb = 0;
  for (int i = 0; i < sizeof(int) * 8; i += 2)
  {
    comb |= 1<<i;
  }

  int odds = number & comb;
  int evens = number & (~comb);

  return (odds << 1 ) | (evens >> 1);

}



int main()
{

  int test = 1733;

  std::cout << "Result is " << swapEvenAndOdd(test) << std::endl;

  return 0;
}
