#include <iostream>
#include <stack>

int sortStack(std::stack<int> &working)
{
  std::stack<int> buffer;
  if (working.empty())
    return -1;

  // find the maximum value
  int maxVal;
  int maxValcount;
  
  while(!working.empty())
  {
    maxVal = working.top();
    maxValcount = 1;
    working.pop();

    //Finding the maximum - push non-maximum to the buffer
    while(!working.empty())
    {
      if (working.top() > maxVal) // bigger number found
      {
        for(int i=0; i<maxValcount; i++)
          buffer.push(maxVal);
        maxVal = working.top();
        working.pop();
        maxValcount=1;
      } else if (working.top() == maxVal) { // increment count for max number
        working.pop();
        maxValcount++; 
      } else { // Usual case, just move to buffer
        buffer.push(working.top());
        working.pop();
      }
    }
    
    // Move back unsorted part back to working
    // At this time there's no values that are same with maxVal since we already extracted out maxVal.
    // So stopping when buffer.top() > maxVal guarantees buffer will contain sorted part and rest has moved to working.
    while(!buffer.empty() && buffer.top() < maxVal)
    {
      working.push(buffer.top());
      buffer.pop();
    }

    // Push maximum to the buffer (sorted part)
    std::cout << "Max val : " << maxVal << " Count : " << maxValcount << std::endl;
    for (int i=0; i<maxValcount; i++)
      buffer.push(maxVal);
  }

  // Now buffer contains reverse-sorted stack, move to working.
  while(!buffer.empty())
  {
    working.push(buffer.top());
    buffer.pop();
  }

}

int main()
{
  std::stack<int> unsorted;

  unsorted.push(8); 
  unsorted.push(3); 
  unsorted.push(3); 
  unsorted.push(3); 
  unsorted.push(9); 
  unsorted.push(1); 
  unsorted.push(2); 
  unsorted.push(2); 
  unsorted.push(5); 

  sortStack(unsorted);

  std::cout << "Sorted stack" << std::endl;

  while(!unsorted.empty())
  {
    std::cout << unsorted.top() <<std::endl;
    unsorted.pop();
  } 
  return 0;
}
