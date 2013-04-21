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

Node* partitionList(Node* head, int mid)
{
  Node* tempHead = NULL;
  Node* tempMid  = NULL;
  Node* curHead = NULL, *curMid = NULL;

  while (head) {
    if (head->val < mid) {
       if (!tempHead) {
         tempHead = head;
       } else {
         curHead->next = head;
       }
       curHead = head;
    } else {
      if (!tempMid) {
        tempMid = head;
      } else {
        curMid->next = head;
      }
      curMid = head;
    }
   
    head = head->next;
  }

  if ( curMid )
    curMid->next = NULL;
  
  if ( curHead ) 
    curHead->next = NULL;

  if ( !tempHead )
    return tempMid;
  
  curHead->next = tempMid;

  return tempHead;

}

int main()
{
  Node* head = new Node(5);
  append(head, new Node(6));
  append(head, new Node(4));
  append(head, new Node(7));
  append(head, new Node(3));
  append(head, new Node(9));
  append(head, new Node(6));
  append(head, new Node(16));
  append(head, new Node(-4));
  append(head, new Node(32));
  append(head, new Node(1));

  std::cout << "Old List" << std::endl;
  printList(head);

  Node* newHead = partitionList(head, 0);

  std::cout << "New List" << std::endl;
  printList(newHead);

  return 0;
}
