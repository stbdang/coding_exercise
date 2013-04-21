#include <iostream>

struct Node {
  Node(int value)
    : val(value), next(NULL) {}


  struct Node* next; 
  int val;
} typedef Node;

void append(Node* head, Node* newNode)
{
  while (head->next) {
    head=head->next;
  }
  head->next = newNode;

}

Node* findNthToLast(Node* head, int n)
{
  Node* temp = head;
  for(int i=0; i<n; i++) {
    temp=temp->next;
    if(!temp)
      return NULL;
  }

  while(temp) {
    temp = temp->next;
    head = head->next;
  }

  return head;

}

void printList(Node* head)
{
  while(head) {
    std::cout<< head->val << std::endl;
    head=head->next;
  }

}

int main()
{
  Node* head = new Node(0);  
  append(head, new Node(1));
  append(head, new Node(2));
  append(head, new Node(3));
  append(head, new Node(4));
  append(head, new Node(5));
  append(head, new Node(6));
  append(head, new Node(7));
  append(head, new Node(8));

  printList(head);

  Node* node = findNthToLast(head, 3);
  std::cout << "Node 3rd from last : " << node->val << std::endl;

  return 0;
}

