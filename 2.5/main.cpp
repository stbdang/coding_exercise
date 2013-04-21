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

//Start with first nodes, implement recursive one
Node* addRecurse(Node* head1, Node* head2, int carry)
{
  //End case
  if ( !head1 && !head2 && !carry )
    return NULL;

  Node* newNode = new Node(0);

  if (head1)
    newNode->val += head1->val;

  if (head2)
    newNode->val += head2->val;

  newNode->val += carry;
  carry = newNode->val / 10;
  newNode->val %= 10;
 
  newNode->next = addRecurse(head1 ? head1->next : NULL, head2 ? head2->next : NULL, carry);

  return newNode;
}

Node* addTwoLists(Node* head1, Node* head2)
{
  Node* sum = NULL;
  Node* prev;
  int carry = 0;
  int sumNode = 0;

  while (head1 && head2) {
    Node* newNode = new Node(0);
    
    if (!sum) { // Allocate new node at the start
      sum = newNode;
      prev = NULL;
    }

    if (prev)
      prev->next = newNode;

    // add logic
    sumNode = head1->val + head2->val + carry;
    newNode->val = sumNode % 10;
    carry = sumNode / 10;


    head1 = head1->next;
    head2 = head2->next;

    prev = newNode;
  }

  while ( head1 ) {
    Node* newNode = new Node(0);
    prev->next = newNode;
    
    sumNode = head1->val + carry;
    newNode->val = sumNode % 10;
    carry = sumNode / 10;

    prev = newNode;
    head1 = head1->next;
  }

  while ( head2 ) {
    Node* newNode = new Node(0);
    prev->next = newNode;
    
    sumNode = head2->val + carry;
    newNode->val = sumNode % 10;
    carry = sumNode / 10;

    prev = newNode;
    head2 = head2->next;
  }

  // check for carry;
  if ( carry ){
    Node* newNode = new Node(carry);
    prev->next = newNode;
    prev = newNode; //Not necessary but if we need to add more later, it might be a good idea
  }

  return sum;
}

int main()
{
  Node* num1 = new Node(1);
  append(num1, new Node(9));
  append(num1, new Node(9));

  Node* num2 = new Node(9);
  append(num2, new Node(9));
  append(num2, new Node(9));

  Node* sum = addRecurse(num1, num2, 0);
  
  std::cout << "NUM 1 : ";
  printList(num1);

  std::cout << "\nNUM 2 : ";
  printList(num2);
  
  std::cout << "\nsum : ";
  printList(sum);

}
