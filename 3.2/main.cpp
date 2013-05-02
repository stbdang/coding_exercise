#include <new>
#include <iostream>

struct Node {
  Node(int value) : next(NULL), val(value)
  { }

  Node* next;
  int val;
  int min;
} typedef Node;


class Stack
{
 public:
  Stack();
  void push(int elem);
  int pop(int& val);
  int min(int& val);

 private:
  Node* head; 
};

Stack::Stack()
{
  head = NULL;
}

void Stack::push(int elem)
{
  Node* newNode = new Node(elem);
  if (!head) {
    head = new Node(elem);
    head->min = head->val;
    return;
  }

  if (head->min < newNode->val)
    newNode->min = head->min;
  else
    newNode->min = newNode->val;

  newNode->next = head;
  head = newNode; 
}

int Stack::pop(int& val)
{
  if (head) {
    val = head->val;
    Node* newHead = head->next;
    delete head;
    head = newHead;
    return 0;
  }
  return -1;
}

int Stack::min(int& val)
{
  if (head) {
    val = head->min;
    return 0;
  }
  return 1;
}

int main()
{
  Stack myStack;

  myStack.push(9);
  myStack.push(2);
  myStack.push(8);
  myStack.push(4);
  myStack.push(3);
  myStack.push(2);
  myStack.push(31);
  myStack.push(21);
  myStack.push(23);
  myStack.push(3);
  myStack.push(1);
  myStack.push(7);
  
  int val;
  int more = 1;
  while(more)
  {
    int min;
    myStack.min(min);
    if (myStack.pop(val) < 0)
      more = 0;
    else
      std::cout << "Current : " << val << " Min : " << min << std::endl;

  } 
  
  return 0;
}
