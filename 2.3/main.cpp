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

void printList(Node* head)
{
  while(head){
    std::cout << head->val << std::endl;
    head = head->next;
  }
}

void deleteNode(Node* node)
{
  while(node->next->next)
  {
    node->val = node->next->val;
    node=node->next;
  }
  node->val = node->next->val;
  
  delete node->next;
  node->next = NULL;
}

void deleteNodeSmarter(Node* node)
{
  //We are gonna move one node forward and use the original node as previous.
  Node* temp = node->next;
  
  if(!temp) //Node is the last node, can't do anything.
    return;

  node->val = temp->val;
  node->next = temp->next;
  delete temp;
}

int main()
{
  Node* head = new Node(0);
  append(head, new Node(1));
  append(head, new Node(2));
  append(head, new Node(3));
  append(head, new Node(4));
  append(head, new Node(5));
  Node* meh = new Node(-1);

  append(head, meh);
  append(head, new Node(6));
  append(head, new Node(7));
  append(head, new Node(8));

  std::cout << "Original list\n";  
  printList(head);

  //deleteNode(meh);
  deleteNodeSmarter(meh);

  std::cout << "\nNew list\n";  
  printList(head);

  return 0;
}
