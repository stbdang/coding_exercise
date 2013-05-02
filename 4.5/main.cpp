#include <iostream>

struct Node {
  Node(int value) : val(value), left(NULL), right(NULL) {}
  Node* left;
  Node* right;
  int val;

} typedef Node;

int checkIfBST(Node* node)
{
  int retValLeft = 1;
  int retValRight = 1;

  if (node->left) {
    if (node->left->val > node->val)
      return 0;
    retValLeft =  checkIfBST(node->left);
  }

  if (node->right) {
    if (node->right->val < node->val)
      return 0;
    retValRight = checkIfBST(node->right);
  }

  int retVal;
  retVal = (retValLeft && retValRight);
  return retVal;
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

  root->left  = node3;
  root->right = node8;
  node3->left = node1;
  node1->right = node2;
  node3->right = node4;
  node8->left = node6;
  node6->right = node7;
  node8->right = node9;  
  node9->right = node10;  


  int isBST = checkIfBST(root);

  std::cout << "This is " << (isBST ? "a BST" : "not a BST") << std::endl;
  return 0;
}
