#include <iostream>

struct Node
{
 public:
  Node(int value)
   :val(value), next(NULL) {}

  struct Node* next;
  int val;
};

void append(Node* head, Node* newNode)
{
  while (head->next) {
    head=head->next;
  }
  head->next = newNode;

}

//class LinkedList
//{
// public:
//  void prepend(Node* head);
//  int length();
//  void append(Node* head);
//  void remove(int val); 
//  Node* getFromVal(int val);
//  
// private:
//  Node* head;
//  int length;
//}

void removeDuplicates(Node* head)
{
  //We can do a simple N^2 algorithm by searching any entries that have the same value from the start
  // Algorithm analysis
  // 1. Outer loop loops from the start to the end of list (cursor)
  // 2. at each node, a new inner loop starts. (dup)
  // 3. Value of cursor and dup->next is compared. 
  //   3.1 if equal, dup->next is deleted and dup->next and dup->next->next are linked
  //   3.2 if not equal, dup fowards by 1.
  // NOTE - HANDLE NODE DELETION PROPERLY - THINK WHAT NEEDS TO BE DONE AFTER IT'S DELETED


  Node* cursor = head;
  while (cursor) {
    Node* dup = cursor;
    while (dup->next) {
      if (dup->next->val == cursor->val)
      {
        //if a node is deleted (dup->next), we do not need to advance as next node is replaced with a new one.
        Node* temp = dup->next;
        dup->next = dup->next->next;
        delete temp;
      } else {
        dup=dup->next;
      }
    }
    cursor = cursor->next;
  }

}

void printList(Node* head)
{
  while(head)
  {
    std::cout << head->val << std::endl;
    head=head->next;
  }

}

int main() 
{
  Node* head = new Node(1); 

  append(head, new Node(4));  
  append(head, new Node(2));  
  append(head, new Node(2));  
  append(head, new Node(2));  
  append(head, new Node(2));  
  append(head, new Node(1));  
  append(head, new Node(3));  
  //append(head, new Node(1));  
  //append(head, new Node(1));  
  //append(head, new Node(1));  
  //append(head, new Node(1));  
  //append(head, new Node(1));  

  removeDuplicates(head);
  printList(head);

  return 0;
}
