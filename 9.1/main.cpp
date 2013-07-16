#include <iostream>

int countHowManyWays(int steps)
{
  // you can hop 1, 2 or 3 steps at a time. We need to find how many possible ways the child can run up the stairs.

  // Base case
  if ( steps == 0 )
    return 1;
 
  // We somewhat need to call the function recursively with different number of steps (1,2,3)
  int answer = 0;
  if (steps >= 1 )
    answer += countHowManyWays(steps - 1);
  
  if ( steps >= 2 )
    answer += countHowManyWays(steps - 2);
 
  if ( steps >= 3 )
    answer += countHowManyWays(steps - 3);

  return answer;

}

// Let's try 3 (good example)
// we know there are
// 3
// 2 1
// 1 2
// 1 1 1
// total 4 ways.

// 4 ->
// 1 -> 4
// 2 -> 2
// 3 -> 1

// 5
// 1 -> 7
// 2 -> 4
// 3 -> 2
// 


int main()
{
  int steps = 5;

  std::cout << "Number of ways for " << steps << ": " << countHowManyWays(steps) << std::endl;
  return 0;
}
