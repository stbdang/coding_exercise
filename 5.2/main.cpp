#include <string>
#include <iostream>

int printBinary(float x)
{
  float meh = 1;
  int count = 1;
  std::string out;
  
  out.append("0.");
 
  while(1)
  {
    if (count >= 32) {
      std::cout<<"ERROR" << std::endl;
      return -1;
    }

    meh/=2;
    if ( x>=meh) {
      x -= meh;
      out.append(1, '1');
      if (x == 0.0) 
      {
        std::cout<<out<<std::endl;
        return 0;
      }
    } else {
      out.append(1, '0');
    }

  }
  

}

int main()
{
  float x = 0.2145634423125;
  
  printBinary(x);

}


