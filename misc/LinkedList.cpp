#include <iostream>

using namespace std;

struct Node 
{
  Node* next;
  int val;
} typedef Node;


Node* addNodeWithVal(Node *node, int val)
{
  Node* newNode = new Node;
  newNode->val = val;
  node->next = newNode;
  return newNode;
}

void deleteList(Node* list)
{
  Node* node = list;
  
  while(node)
  {
    Node* toBeDeleted = node;
    node = node->next;
    cout << toBeDeleted->val << " will be deleted\n";
    delete toBeDeleted;
  }

}

void printList(Node* list)
{
  if(!list){
    cout << "Error - invalid list\n";
    return;
  }
  Node* node = list;
  while (node)
  {
    cout << "Node at 0x" << node << " val : " << node->val << endl;
    node = node->next;
  }
}

//EX1 : implement reversing singly-linked list;
Node* reverseList(Node* list)
{
  Node* prev = list;
  Node* cur = prev->next;
  prev->next = NULL; // this is the last element now.
  Node* temp;

  while(cur)
  {
    temp = cur;
    cur = cur->next;

    temp->next = prev;
    prev = temp;
  }
  
  return temp;
}

//EX2 Merge sort Linked list
int cutLinkInHalf(Node* list, Node** out1, Node** out2)
{
cout << __func__ << endl;
//Basic idea, advance 2 and return middle if end is reached.
  Node* cur = list;
  Node* middle = cur;

  if ( (!cur) || !(cur->next) )
    return -1; // Less than 2 , can't cut 

  cur = cur->next;

  while (cur)
  {
    Node* temp = cur->next;
    if ( temp )
    {
      if ( temp->next )
      {
        //Pair - advance middle pointer by one. Advance cursor by two.
        middle = middle->next;
        cur = cur->next->next;
        continue;
      }
    }
    // Cutting happens here
    *out2 = middle->next;
    *out1 = list;
    middle->next = NULL;
    return 0;
  }
}

Node* mergeList(Node* list1, Node* list2)
{
  cout << "\nmerge start =====================\n";
  printList(list1);
  cout << "=================================\n";
  printList(list2);
  cout << "=================================\n\n";

  Node* cur1, *cur2;
  Node* merged;

  if ( list1->val < list2->val) {
    merged = list1;
    cur1 = list1->next;
    cur2 = list2;
  }
  else {
    merged = list2;
    cur2 = list2->next;
    cur1 = list1;
  }  

  Node* cursor = merged;

  while (cur1 && cur2)
  {
    cout << cur1->val << " " << cur2->val << endl;

    if (cur1->val < cur2->val)
    {
      cursor->next = cur1;
      cur1=cur1->next;
    }
    else
    {
      cursor->next = cur2;
      cur2=cur2->next;
    } 
    cursor = cursor->next;
  } 

  if (cur1)
    cursor->next = cur1;
  else
    cursor->next = cur2;
 
  cout << "merged \n";
  printList(merged);

  return merged;
}

Node* mergeSortList(Node* list)
{
  Node* firstHalf, *secondHalf;

  if ( cutLinkInHalf(list, &firstHalf, &secondHalf) < 0 )
  {
    cout << "END node : " << list->val << endl;
    return list;
  }  

  firstHalf = mergeSortList(firstHalf);
  secondHalf = mergeSortList(secondHalf);
  
  return mergeList(firstHalf, secondHalf);
  
}

int main()
{
  Node* list = new Node;
  list->val = 1;

  Node* cur = addNodeWithVal(list, 217);
  cur = addNodeWithVal(cur, 3);
  cur = addNodeWithVal(cur, 34);
  cur = addNodeWithVal(cur, 12);
  cur = addNodeWithVal(cur, 22);
  cur = addNodeWithVal(cur, 7);
  cur = addNodeWithVal(cur, 84);
  cur = addNodeWithVal(cur, 9);
  cur = addNodeWithVal(cur, 10);
  cur = addNodeWithVal(cur, 44);
  cur = addNodeWithVal(cur, 2);
  cur = addNodeWithVal(cur, 23);
  cur = addNodeWithVal(cur, 67);

  Node* newList;

  newList = reverseList(list);
  printList(newList);

  Node* sortedList = mergeSortList(newList);

  cout << "\n ==========SORTED LIST==========\n"; 
  printList(sortedList);

  deleteList(sortedList); 
  return 0;
}
