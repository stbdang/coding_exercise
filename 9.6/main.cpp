#include <iostream>
#include <list>

/* Print parentheses
This function prints a valid combination of parenthesis given number N

It starts with N starts and ends.

Rules
1. Number of end must be less or equal to start (can't have at the first)

*/

int printParentheses(int numStarts, int numEnds, std::list<std::string>& results, std::string result)
{
  //base case
  if ( numStarts == 0 && numEnds == 0 )
  {
    results.push_back(result);
    return 0;
  } 
  
  if ( numStarts > 0 ) {
    result.append(1, '(');
    printParentheses(numStarts - 1, numEnds, results, result);
    result.erase(result.length() - 1, 1);
  }

  if ( numEnds > numStarts) {
    result.append(1, ')');
    printParentheses(numStarts, numEnds - 1, results, result);
    result.erase(result.length() - 1, 1);
  }
  return 0;
}

int main()
{

  std::list<std::string> results;
  std::string meh;

  int N = 4;

  printParentheses(N, N, results, meh);

  std::list<std::string>::iterator it;

  for ( it = results.begin(); it != results.end(); it++) {
    std::cout << (*it) << std::endl;
  }
  

  return 0;
}
