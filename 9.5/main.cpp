#include <iostream>
#include <list>
#include <string>

int recursePerm(std::string str, int used[], std::list<std::string>& perms, std::string perm)
{
  int len = str.length();

  if (perm.length()>=len) {
    perms.push_back(perm);
    return 0;
  }

  int i;
  for (i = 0; i < len; i++)
  {
    if (!used[i]) {
      used[i] = 1;
      perm.append(1, str[i]);
      recursePerm(str, used, perms, perm);
      perm.erase(perm.length()-1, 1);  // remove the last character
      used[i] = 0;
    }
  }
  
  return 0;
  
}

int main()
{
  std::string str = "abcd";
  int used[3];  

  int i;
  for (i = 0; i < sizeof(used) / sizeof(int); i++)
    used[i] = 0;

  std::string perm;
  std::list<std::string> perms;

  recursePerm(str, used, perms, perm);

  std::list<std::string>::iterator it;

  for (it = perms.begin(); it != perms.end(); it++)
  {
    std::cout << (*it) << std::endl;
  }
  
  return 0;
}
