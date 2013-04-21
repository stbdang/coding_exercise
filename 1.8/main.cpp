#include <iostream>

int isSubString(std::string str1, std::string str2)
{
  int matched = 1;
  if (str2.empty())
    return 1;
  
  
  if (str1.length() < str2.length())
    return 0;


  for (int i = 0; i < str1.length(); i++) {
    matched = 1;
    for ( int j = 0; j < str2.length(); j++) {
      if ( str1[i+j] != str2[j] ) {
        matched = 0;
        break;
      }
    }
    if (matched) {
      return 1;
    }
  }
  return 0;
}


int main()
{
  std::string test = "Teststringhahaha";
  std::string test2 = "ddstringhahahaTest";

  test = test.append(test);

  if ( isSubString(test, test2) )
    std::cout << "This is a cyclic match" << std::endl;
  else
    std::cout << "Not a cyclic match" << std::endl;

  return 0;
}
