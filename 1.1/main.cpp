#include <iostream>
#include <string>

// Excercise 1.1 - find if a string has all unique characters.
// 1. We can use int num_occurence[128] to count the number of characters.
// 2. sort and find if we have any duplicates.


int main()
{
  std::string test = "This string tests the Excercise 1.1 which finds if the string only contains unique characters.";
  int size = sizeof(char) * 256;
  int num_occurence[size]; //1 byte - 256 values

  for (int i = 0; i < size; i++) {
    num_occurence[i] = 0;
  }

  for (int i = 0; i < test.length(); i++) {
    num_occurence[(int)test[i]]++;
  }

  for (int i = 0; i < sizeof(char) *256; i++) {
    std::cout << (char)i << " : " << num_occurence[i] << std::endl; 
  }
  
  std::cout<<"" << std::endl;  
  return 0;
}
