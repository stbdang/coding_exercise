#include <iostream>

char findFirstNonrepeat(std::string input)
{
  for(int i =0; i < input.length(); i++)
  {
    int found = 0;
    for (int j = i+1; j < input.length(); j++)
    {
      if (input[i] == input[j])
      {
        found = 1;
        break;
      }

    }
    if (!found)
      return input[i];
  }

}

int main()
{
  std::string test = "his is a test thingy";

  std::cout << "First non repeated char : " << findFirstNonrepeat(test) << std::endl;


  return 0;
}
