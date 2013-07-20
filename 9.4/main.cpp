#include <iostream>
#include <list>

// return all subsets of a set, 
// How do we define a set : array seems easy enough
// Subset will be a list because it's easier to push/pop

int recurseForSubset(int set[], int N, int index, std::list<std::list<int> >& subsets, std::list<int> subset)
{
  if (index >= N)
  {
    subsets.push_back(subset);
    return 0;
  }

  int val = set[index];
  index++;

  recurseForSubset(set, N, index, subsets, subset);

  subset.push_back(val);
  recurseForSubset(set, N, index, subsets, subset);

  return 0;
}

int returnAllSubset(int set[], int N, std::list<std::list<int> >& retVal)
{
  std::list<int> subset;
  recurseForSubset(set, N, 0, retVal, subset);
}

int main()
{

  int N = 4;
  int set[4] = {0, 1, 2, 3};//, 4, 5, 6, 7, 8, 9};

  std::list<std::list<int> > subsets;

  returnAllSubset(set, N, subsets);

  std::list<std::list<int> >::iterator it;

  for (it = subsets.begin(); it != subsets.end(); it++)
  {
    std::cout << "=========================" << std::endl;
    while (!(*it).empty()) {
      std::cout << (*it).front() << " ";
      (*it).pop_front();
    }
    std::cout << std::endl << std::endl;
  }

  return 0;
}

