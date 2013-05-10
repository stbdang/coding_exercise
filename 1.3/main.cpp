#include <iostream>

bool ifPerm ( std::string a, std::string b )
{
  if (b.length() > a.length())
    return false;

  int aMap[256], bMap[256];
  
  for (int i = 0; i <256; i++) {
    aMap[i] = 0;
    bMap[i] = 0;
  }

  for (int i = 0; i < a.length(); i++) {
    aMap[(int)a[i]]++;
  }

  for (int i = 0; i < b.length(); i++) {
    bMap[(int)b[i]]++;
  }

  for (int i = 0; i < 256; i++) {
    if (bMap[i] > aMap[i])
      return false;
  }
  return true;
}


int main()
{
  std::string testA = "This is a test string for excercise 1.3";
  std::string testB = "string for excercise 1.3 12321";

  if ( ifPerm(testA, testB) )
    std::cout << "B is a perm of A" << std::endl;
  else
    std::cout << "B is not a perm of A" << std::endl;

  return 0;
}
