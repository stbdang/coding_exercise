#include <iostream>

#define N 3

struct Node
{
  Node(int value) : val(value), next(NULL) {}

  int val;
  Node* next;
} typedef Node;

class RodStack
{
 public:
  RodStack();
  int push(int val);
  int pop(int& val);
  int peek(int& val);
  void printStack();
  int count;
 private:
  Node* top;
};

RodStack::RodStack()
  : top(NULL)
  , count(0)
{

}

int RodStack::push(int val)
{
  if (top && (val >= top->val))
  {
    return -2;
  }
  count++;
  Node* newNode = new Node(val);
  if (!top) {
    top = newNode;
    return 0;
  }
  
  newNode->next = top;
  top = newNode;
  return 0;
}

int RodStack::pop(int& val)
{
  if (!top) {
    return -1;
  }
  count--;
  val = top->val;
  Node* toBeDeleted = top;
  top = top->next;
  delete toBeDeleted;

  return 0;
}

int RodStack::peek(int& val)
{
  if (!top) {
    return -1;
  }

  val = top->val;
  return 0;
}

void RodStack::printStack()
{
  Node* cursor = top;
  while (cursor) {
    std::cout << " " << cursor->val;
    cursor=cursor->next;
  }

  std::cout << std::endl;
}


int movePiece(RodStack* stacks)
{
  for (int i=0; i<3; i++) {
    for (int j = 2; j >=0; j--) {
      if(i!=j) {
        int val;
        if (stacks[i].peek(val) < 0)
          continue;

        if (stacks[j].push(val) < 0)
          continue;

        // if it gets to this stage, it means we have pushed the value to the new stack, need to pop
        stacks[i].pop(val); //no need to check since peek already succedeed.
        return 0;
      }
    }
  }
  return -1;
}

int main()
{
  RodStack rods[3];

  for(int i = N; i > 0; i--) {
    rods[0].push(i);
  }

  while ( rods[2].count < N ) {
    for (int i =0; i <3; i++) {
      std::cout << "Stack " << i+1 << " : ";
      rods[i].printStack();
    }
    std::cout << std::endl;
    std::cin.ignore();
    movePiece(rods);
  }
  return 0;
}
