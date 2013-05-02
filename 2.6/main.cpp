#include <iostream>

struct Node {
  Node(int value) : val(value), next(NULL) {}

  struct Node* next;
  int val;

} typedef Node;

void append(Node* head, Node* newNode)
{
  while (head->next) {
    head = head->next;
  }

  head->next = newNode;
}

Node* findLoopStart(Node* head)
{
  Node* ls = head;
  Node* prevLs = NULL;

  while ( ls ) {
    Node* current = head;
    Node* prevCurrent = NULL;
   
    while (current != ls)
    {
      prevCurrent = current;
      current = current->next;
    }

    if ( prevCurrent != prevLs ) {
      //found
      return ls;
    }

    prevLs = ls;   
    ls = ls->next;
  }

}

Node* findLoopStartBetter(Node* head)
{
  Node* pLS = head;

  while ( pLS->next )
  {
    Node* prev = head;

    while (prev->next != pLS->next)
    {
      prev = prev->next;
    }

    if ( prev != pLS ) {
      return pLS->next;
    }

    pLS = pLS->next;

  }


}

int main()
{
  Node* head = new Node(1);
  append(head, new Node(2)); 
  Node* loopstart = new Node(3);
  append(head, loopstart); 
  append(head, new Node(4)); 
  append(head, new Node(5)); 
  append(head, new Node(6)); 
  
  Node* loopend = new Node(7);
  append(head, loopend);

  loopend->next = loopstart;
  
  Node* ans = findLoopStartBetter(head);

  std::cout << "Start of loop is : " << ans->val << std::endl;
 
  return 0;
}
