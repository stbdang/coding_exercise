#include <iostream>

#define NUM_ELEM 5


class stack_node 
{
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
}

stack_node::stack_node()
  : next(NULL)
  , prev(NULL)
  , count(0);
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
}

MultiStack::MultiStack()
  : head (new stack_node)
{
  current_stack = head;
}

MultiStack::~MultiStack()
{
  while(head) {
    stack_node* toBeDeleted = head;
    delete toBeDeleted;
    head = head->next;
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

int Mu
