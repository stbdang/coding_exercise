#include <iostream>

#define NUM_ELEM 5


class stack_node 
{
 public:
  stack_node();
  int push(int val);
  int pop(int& val);

  int empty();
  int full();

  stack_node* next;
  stack_node* prev;

 private:
  int data[NUM_ELEM];
  int count;
};

stack_node::stack_node()
  : next(NULL)
  , prev(NULL)
  , count(0)
{

}

int stack_node::push(int val)
{
  if (full())
    return -1;

  data[count] = val;
  count++;
  return 0;
}

int stack_node::pop(int& val)
{
  if (empty())
    return -1;

  val = data[count-1];
  count--;
  return 0;
}

int stack_node::full()
{
  return (count >= NUM_ELEM);
}

int stack_node::empty()
{
  return (count <= 0);
}

class MultiStack 
{
 public:
  MultiStack();
  ~MultiStack();
  int push(int val);
  int pop (int& val);

 private:
  stack_node* head;
  stack_node* current_stack;
};

MultiStack::MultiStack()
  : head (new stack_node)
{
  current_stack = head;
}

MultiStack::~MultiStack()
{
  while(head) {
    stack_node* toBeDeleted = head;
    head = head->next;
    delete toBeDeleted;
  }
}

int MultiStack::push(int val)
{
  if (current_stack->full()) // need to create a new stack node
  {
    stack_node* newStack = new stack_node;
    current_stack->next = newStack;
    newStack->prev = current_stack;
    current_stack = newStack;
  }
 
  return current_stack->push(val);

}

int MultiStack::pop(int& val)
{
  if (current_stack->empty()) // need to delete and move to the earlier stack node
  {
    if (current_stack == head) // Can't remove as this is the head node
    {
      return -1;
    }
    stack_node* toBeDeleted = current_stack;
    current_stack = current_stack->prev;
    current_stack->next = NULL;
    delete toBeDeleted;
  }

  return current_stack->pop(val);
}

int main()
{
  MultiStack myStack;

  myStack.push(0); 
  myStack.push(1); 
  myStack.push(2); 
  myStack.push(3); 
  myStack.push(4); 
  myStack.push(5); 
  myStack.push(6); 
  myStack.push(7); 
  myStack.push(8); 
  myStack.push(9); 
  myStack.push(10); 
  myStack.push(11); 

  int val;
  while (myStack.pop(val) == 0)
  {
    std::cout << val << std::endl;
  }

  return 0;
}


