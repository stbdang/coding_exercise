#include <iostream>
#include <list>
#include <queue>

struct Node {
  Node(int value) : val(value), left(NULL), right(NULL), sum(0) {}
  Node* left;
  Node* right;
  int val;
  int sum;

} typedef Node;

// There is only one path to the node, which means that you can store the value in the node which 
// indicates the sum of path from the root.

// I seriously hate this keyboard and I wanna cry. Oh my fucking god.....

// This is by no means complete, I need to revisit this problem later but currently I'm just sick and tired of it and would like to move to a new problem.


void printPath(std::list<int> record)
{
  std::cout << "New path !" << std::endl;
  for(std::list<int>::iterator it = record.begin(); it != record.end(); it++) {
    std::cout << *it << " ";
  }

  std::cout << std::endl << std::endl;

}

int checkAndPrint(Node* node, int val, int runningSum, std::list<int> record)
{
  if(!node)
    return 0;

  int sum = runningSum + node->val;
  record.push_back(node->val);

  if (sum == val)
  {
    printPath(record);
  } 

  checkAndPrint(node->left, val, sum, record);
  checkAndPrint(node->right, val, sum, record);

  return 0;
}

int printAll(Node* root, int val)
{
  std::list<int> list;
  std::queue<Node*> nodes;

  nodes.push(root); 

  while(!nodes.empty()) {
    Node* node = nodes.front();
    nodes.pop();

    std::cout << "Testing node " << node->val << std::endl;
    checkAndPrint(node, val, 0, list);

    if(node->left)
      nodes.push(node->left);
    
    if(node->right)
      nodes.push(node->right);
  }
}

int main()
{
  Node* root = new Node(5);
  Node* node1 = new Node(1);
  Node* node2 = new Node(2);
  Node* node3 = new Node(3);
  Node* node4 = new Node(4);
  Node* node6 = new Node(6);
  Node* node7 = new Node(7);
  Node* node8 = new Node(8);
  Node* node9 = new Node(9);
  Node* node10 = new Node(10);
  Node* node_1 = new Node(1);
  Node* node_n1 = new Node(-1);
  Node* node14 = new Node(1);

  root->left  = node3;
  root->right = node8;
  node3->left = node1;
  node1->right = node2;
  node3->right = node4;
  node8->left = node6;
  node6->right = node7;
  node8->right = node9;  
  node9->right = node10;  

  node4->right = node_1;
  node_1->left = node_n1;
  node_n1->right = node14;
  
  printAll(root, 13);
}

