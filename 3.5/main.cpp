#include <iostream>
#include <stack> 

class MyQueue
{
 public:
  int dequeue(int& val);
  void enqueue(int val);

 private:
  std::stack<int> stackFirst;
  std::stack<int> stackSecond;

};

void MyQueue::enqueue(int val)
{
  stackFirst.push(val);
}

int MyQueue::dequeue(int& val)
{
  if (stackFirst.empty())
    return -1;

  while(!stackFirst.empty())
  {
    stackSecond.push(stackFirst.top());
    stackFirst.pop();
  }
  
  val = stackSecond.top();
  stackSecond.pop();

  while(!stackSecond.empty())
  {
    stackFirst.push(stackSecond.top());
    stackSecond.pop();
  }
  
  return 0;
}

int main()
{
  MyQueue myqueue;

  //myqueue.enqueue(0); 
  myqueue.enqueue(1); 
  myqueue.enqueue(2); 
  myqueue.enqueue(3); 
  myqueue.enqueue(4); 
  myqueue.enqueue(5); 
  myqueue.enqueue(6); 
  myqueue.enqueue(7); 
  myqueue.enqueue(8); 
  myqueue.enqueue(9); 

  int val;
  while(myqueue.dequeue(val) == 0) {
    std::cout << val << std::endl;
  }

  return 0;
}
