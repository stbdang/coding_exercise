#include <iostream>
#define NUM_STACK 3
#define NUM_DATA 100

class WeirdStack
{
 public:
  WeirdStack();
  int pop(int stackInd, int& val);
  int push(int stackInd, int val);

 private:
  int data[NUM_DATA];
  int start[NUM_STACK];
  int end[NUM_STACK];
  int top[NUM_STACK];

};

WeirdStack::WeirdStack()
{
  for (int i=0; i < NUM_STACK; i++) {
    start[i] = i * NUM_DATA / NUM_STACK;
    top[i] = -1;
    end[i] = (i+1) * NUM_DATA/NUM_STACK -1;
  }
}

int WeirdStack::push(int stackInd, int val)
{
  if (stackInd >= NUM_STACK)
    return -1;

  if (top[stackInd] >= end[stackInd])
    return -2;

  if (top[stackInd] < 0 )
    top[stackInd] = start[stackInd];
  else
    top[stackInd]++;

  data[top[stackInd]] = val;
  
  return 0;
}


int WeirdStack::pop(int stackInd, int& val)
{
  if (stackInd >= NUM_STACK )
  { return -1; }

  if (top[stackInd] < 0 )
    return -2;

  val = data[top[stackInd]];

  if (top[stackInd] <= start[stackInd])
    top[stackInd] = -1;
  else
    top[stackInd]--;
  
  return 0;
}

int main()
{

  WeirdStack myStack;

  myStack.push(0, 0);
  myStack.push(1, 1);
  myStack.push(2, 2);
  myStack.push(1, 3);
  myStack.push(2, 4);
  myStack.push(2, 5);
  myStack.push(0, 6);
  myStack.push(0, 7);
  myStack.push(1, 8);
  myStack.push(1, 8);
  myStack.push(2, 3);
  myStack.push(1, 22);
  myStack.push(0, 10);

  for (int i =0; i < NUM_STACK; i++) {
    int val;
    std::cout << "Stack " << i << " :";
    while(myStack.pop(i, val) == 0) {
      std::cout << " " << val;
    } 
    std::cout << std::endl;
  }

  return 0;
}
