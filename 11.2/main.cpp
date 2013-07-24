#include <iostream>
#include <list>


// sort strings so that anagrams are next to each other....hmmm how do we define "compare" function so that anagrams have the same value.
// Anagrams contain same set of characters. If we sum the value of each characters in a string, we know anagrams will have the same value.

int compare(std::string a, std::string b)
{
  unsigned int valA = 0, valB = 0;

  int i;
  for (i=0; i<a.length(); i++) {
    valA += (unsigned)a[i];
  }

  for (i=0; i<b.length(); i++) {
    valB += (unsigned)b[i];
  }

  return valA < valB;
}

int main()
{

  std::list<std::string> strings;

  strings.push_back(std::string("abcd"));
  strings.push_back(std::string("aaa"));
  strings.push_back(std::string("ad2w"));
  strings.push_back(std::string("bgrrrr"));
  strings.push_back(std::string("aefb"));
  strings.push_back(std::string("dcab"));
  strings.push_back(std::string("2wda"));
  strings.push_back(std::string("zzzzzzzz"));
  strings.push_back(std::string("zzz2zzzz"));

  strings.sort(compare);

  std::list<std::string>::iterator it;

  for (it = strings.begin(); it != strings.end(); it++)
  {
    std::cout << *it << std::endl;
  }

  return 0;
}
