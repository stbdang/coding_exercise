#include <iostream>
#include <vector>


/* 11.5 Find an index of a string in a sorted list of strings with empty strings in the list.

We need to find a good way to ignore empty strings...

We know a simple O(n) can find the string without much problem, so we skip it.

Sorted -> we can use BST but how do we handle empty strings? HMM

We somehow need to fetch the next non-empty string on the list. ( std::

       0    1   2     3     4     5      6    7   8     9
e.g. {"at", "", "", "baby", "", "cat", "dog", "", "", "mama" }

say we need to find "dog", we start at index 4.

(by the way, if we use std::list for this, there's really no point in BST because we will end up going forward and back and it would be better to just stick with O(n))

index 4 has nothing....meh. Here we can do two things, since there's no 4th item, we can simply go to the next non-empty item and do the comparison. Or we can compare with previos non-empty for less case and next non-empty for larger. For now I will just be stupid and to the next one.

So the next non empty is. "cat" and we know dog is larger, so the new range becomes 5-9 -> 7 is the next one.

Another empty...meh...so we go to 9 and compare and we know its smaller -> 5-8 -> 6 yay!

I just noticed something while I was doing this, what if we pass something that should be in the middle (e.g. "hair" which should be between dog and mama) and the problem gets complicated, we are stuck in an infinite loop of rage 6-9 ( and it's not closing!!! OMG)

So it seems we can use "previos" and "next" to solve this issue, if the value doesn't belong to any category, we know it's not there. Ok let's write this.


*/

int findNextNonEmpty(std::vector<std::string>& strVec, int startInd, int direction)
{
  int i = startInd;
  if (startInd < 0 )
    return -1;

  while(startInd < strVec.size() && strVec[i].empty()) {
    if (direction < 0)
      i--;
    else
      i++; 
  }
  return i;
}

int SearchForString(std::vector<std::string>& strVec, int start, int end, std::string key) {
  int middle = (start+end)/2;

  int next = findNextNonEmpty(strVec, middle, 1);
  std::cout << "Next : " << next << std::endl;
  if (next >= 0 )
  { 
    int retval = strVec[next].compare(key);
    if ( retval == 0 ) {
      return next;
    } else if ( retval < 0 ) {
      return SearchForString(strVec, next, end, key); 
    }
  }
 
  int prev = findNextNonEmpty(strVec, middle, -1);
  std::cout << "Prev : " << prev << std::endl;
  if (prev >= 0 )
  {
    int retval = strVec[prev].compare(key);
    if ( retval == 0 ) {
      return prev;
    } else if ( retval > 0 ) {
      return SearchForString(strVec, start, prev, key);
    }
  }

  // if it got here, means it never found it.
  return -1;
}

int main()
{
  std::vector<std::string> strVec;

  strVec.push_back("at");
  strVec.push_back("");
  strVec.push_back("");
  strVec.push_back("baby");
  strVec.push_back("");
  strVec.push_back("cat");
  strVec.push_back("dog");
  strVec.push_back("");
  strVec.push_back("");
  strVec.push_back("mama");

  std::string find = std::string("has");
  int ind = SearchForString(strVec, 0, strVec.size() -1, find);

  std::cout << "String " << find << " is on " << ind << std::endl;

  return 0;
}
