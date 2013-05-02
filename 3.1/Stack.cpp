#include "Stack.h"

Stack::Stack()
{
  head = NULL;
}

void Stack::push(int elem)
{
  Node* newNode = new Node(elem);
  if (!head) {
    head = new Node(elem);
    return;
  }

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
