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

int fetchVal(Node* head, int index)
{
  for (int i = 0; i < index; i++) {
    head=head->next;
  }
  return head->val;
}

int checkForPalindrom(Node* head)
{
  //First find the length of list,
  int length = 0;
  Node* cursor = head;

  while(cursor) {
    length++;
    cursor = cursor->next;
  }

  std::cout << "Length : " << length << std::endl;
  //Second loop from first to the middle and compare values
  for (int i = 0; i < length / 2; i++ ) {
    if ( fetchVal(head, i) != fetchVal(head, length - i - 1) ) {
      return 0;
    }
  }

  return 1;
}

int meh(Node* head, int length, Node** last)
{

  if ( length == 0 ) { //end case
    *last = head;
    return 1;
  } else if ( length == 1 ) {
    *last = head->next;
    return 1;
  }

  if (!meh(head->next, length-2, last))
    return 0;

//At this point length is either 2 or 3 (first unwinding)

  int ret = ((head->val) == (*last)->val);
  *last = (*last)->next;
  return ret;
}

int checkFPRecurse(Node* head)
{
  Node* last;
  int length = 0;
  Node *cur = head;

  while(cur) {
    length++;
    cur=cur->next;
  }

  return meh(head, length, &last);
    
}

int main()
{
  Node* head = new Node(1);
  append(head, new Node(3)); 
  append(head, new Node(2)); 
  append(head, new Node(2)); 
  append(head, new Node(3)); 
  append(head, new Node(1)); 

  std::cout << "This is " << (checkFPRecurse(head) ? "a Palindrom" : "not a Palindrom") << std::endl;

}
