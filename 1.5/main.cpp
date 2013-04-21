#include <iostream>
#include <string>

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

int main()
{
  std::string test = "aaaaabbbsssccagllll";
  std::string out;

  compressString(test, out);

  std::cout << out << std::endl;
  return 0;
}
