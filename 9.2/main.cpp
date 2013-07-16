#include <iostream>
#include <vector>

int findNumberOfPaths(int startX, int startY, int endX, int endY, std::vector< std::pair<int,int> >& notAllowed)
{

  if ( ( startX == endX ) && ( startY == endY ) )
    return 1;

  int numberOfPaths = 0;
  
  std::vector<std::pair<int,int> >::iterator it;
  
  bool canGoRight = true, canGoDown = true;
  for (it = notAllowed.begin(); it != notAllowed.end(); it++)
  {
    std::pair<int,int> node = *it;
    if (node.first == startX + 1 && node.second == startY) {
      std::cout << "Can't go right from " << startX << "," << startY << std::endl;
      canGoRight = false;
    }
    if (node.first == startX && node.second == startY + 1) {
      std::cout << "Can't go down from " << startX << "," << startY << std::endl;
      canGoDown = false;
    }
  }

  if ( startX < endX && canGoRight)
    numberOfPaths += findNumberOfPaths(startX + 1, startY, endX, endY, notAllowed);

  if ( startY < endY && canGoDown)
    numberOfPaths += findNumberOfPaths(startX, startY + 1, endX, endY, notAllowed);

  return numberOfPaths;

}

// let's try an example
// 0,0 to 2,2
// 0,1 -> 0,2 -> 1,2 -> 2,2
//     -> 1,1 -> 1,2 -> 2,2
//            -> 2,1 -> 2,2
// 1,0 -> 1,1 ......2
//     -> 2,0 ......1
// 
// 6 ways 

int main()
{
  int x = 2, y = 2;

  std::vector< std::pair<int, int> > notAllowed;

  notAllowed.push_back(std::pair <int, int> (1, 1));
  //notAllowed.push_back(std::pair <int, int> (3, 2));
  //notAllowed.push_back(std::pair <int, int> (4, 6));

  std::cout << "Number of paths from (0,0) to " << x << "," << y << " is : " << findNumberOfPaths(0, 0, x, y, notAllowed) << std::endl;

  return 0;
}
