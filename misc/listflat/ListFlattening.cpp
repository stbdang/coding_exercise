#include <iostream>
#include <queue>

typedef struct Node {
  Node(int val)
    : value(val) {}
  struct Node *next;
  struct Node *prev;
  struct Node *child;

  int value;

} Node;

void listFlatten(Node* head, Node** tail)
{
  Node* cur = head;
  
  while (cur)
  {
    if ( cur->child ) {
      (*tail)->next = cur->child;
      cur->child->prev = *tail;
      Node* childTail = cur->child;
      while (childTail->next)
        childTail = childTail->next;

      *tail = childTail;
    }    

    cur = cur->next;
  }

}

void listUnflatten(Node* head, Node** tail)
{
  Node *cur = *tail;
  
  while (cur)
  {
    //std::cout << "examining " << cur->value << std::endl;
    if ( cur->child ) {
      if(cur->child->prev) {
        cur->child->prev->next = NULL; 
        cur->child->prev = NULL;
      }
      
      Node* tailCur = cur;
      while (tailCur) {
        tailCur = tailCur->next;
      }
      *tail = tailCur;
    }
    cur = cur->prev;
  }
}

void printList(Node* head)
{
  while(head) {
    std::cout << head->value << " ";
   
    head = head->next;
  }
}

void printListBF(Node* head)
{
  std::queue<Node*> nodeQueue;
  nodeQueue.push(head);

  while(nodeQueue.front()) {
    head = nodeQueue.front();
    nodeQueue.pop();

    while(head) {
      std::cout << head->value << " ";

      if ( head->child )
        nodeQueue.push(head->child);
      head = head->next;
    }
  }

}

void printListDF(Node* head)
{
  while(head) {
    std::cout << head->value << " ";

    if (head->child)
      printListDF(head->child);
  
    head = head->next;
  }
}

int main()
{
  Node *head, *tail;

  Node *node0 = new Node(5);
  Node *node1 = new Node(33);
  Node *node2 = new Node(17);
  Node *node3 = new Node(2);
  Node *node4 = new Node(1);
  Node *node5 = new Node(6);
  Node *node6 = new Node(25);
  Node *node7 = new Node(6);
  Node *node8 = new Node(2);
  Node *node9 = new Node(7);
  Node *node10 = new Node(8);
  Node *node11 = new Node(9);
  Node *node12 = new Node(12);
  Node *node13 = new Node(5);
  Node *node14 = new Node(7);
  Node *node15 = new Node(21);
  Node *node16 = new Node(3);

  node0->next = node1;
  node0->child = node5;
  node1->next = node2;
  node1->prev = node0;
  node2->next = node3;
  node2->prev = node1;
  node3->next = node4;
  node3->prev = node2;
  node3->child = node8;  
  node4->prev = node3;

  node5->next = node6;
  node6->prev = node5;
  node6->next = node7;
  node6->child = node10;
  node7->prev = node6;
  node7->child = node11;
  node11->child = node14;

  node8->next = node9;
  node8->child = node12;
  node9->prev = node8;  
  
  node12->next = node13;
  node12->child = node15;
  node13->prev = node12;

  node15->next = node16;
  node16->prev = node15;

  head = node0;
  tail = node4;
  
  //listFlatten(head, &tail);
  //printList(head);
  
  //printListBF(head); 

  //printListDF(head);

  listFlatten(head, &tail);
  listUnflatten(head, &tail);

  printList(head);
  return 0;

}
