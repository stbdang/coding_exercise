#include <iostream>
#include <string>
#include <cstdio>

void convertToStr(int val, std::string& retval) 
{
  while (val) {
    retval.append(1, '0' + (val%10));
    val /= 10;
  }
}

int compressString(std::string str, std::string& out)
{
  if (!out.empty())
    return -1;

  char charOnTrack = str[0];
  int count = 1;
  
  out.append(1, charOnTrack);

  for (int i =1; i < str.length(); i++) {
    if ( str[i] == charOnTrack ) {
      count++;
    } else {
      std::string retval;
      convertToStr(count, retval);
      out.append(retval);
      charOnTrack = str[i];
      out.append(1, charOnTrack);
      count = 1;
    }

  }
  std::string retval;
  convertToStr(count, retval);
  out.append(retval);
  return 0;
}

int encodeString(std::string in, std::string& out)
{
  char charInTrack;
  int i;
  int charCount;

  charInTrack = in[0];
  out.append(1, charInTrack);
  charCount = 1;

  // Need some for loop from start to end
  for(i = 1; i < in.length(); i++) {
    // There are two cases
    // 1. New characer sequence
    // 2. Continued from previous.
    // Need to keep track of what we are tracking.
    if ( in[i] == charInTrack ) {
      charCount++;
    } else {
      char num[10];
      sprintf(num, "%d", charCount); 
      out.append(num);
      charInTrack = in[i];
      out.append(1, charInTrack);
      charCount = 1;
    }
  }
  char num[10];
  sprintf(num, "%d", charCount);
  out.append(num);
  return 0;
}

int main()
{
  std::string test = "aaaaabbbsssccagllll";
  std::string out;

  //compressString(test, out);
  encodeString(test, out);

  std::cout << out << std::endl;
  return 0;
}
