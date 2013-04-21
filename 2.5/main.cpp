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

Node* addTwoLists(Node* head1, Node* head2)
{
  Node* sum = new Node(0);
  Node* cursor = sum;
  int carry = 0;
  int sumNode = 0;

  while (head1 && head2) {
    sumNode = head1->val + head2->val + carry;
    cursor->val = sumNode % 10;

    Node* newNode = new Node(0);
    cursor->next = newNode;
    cursor = newNode;
    carry = sumNode / 10;

    head1 = head1->next;
    head2 = head2->next;
  }

  while ( head1 ) {
    sumNode = head1->val + carry;
    

}

int main()
{

}
