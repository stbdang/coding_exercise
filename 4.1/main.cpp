#include <iostream>
#include <cmath>

struct Node {

  Node(int value) : left(NULL), right(NULL) {}
  Node* left;
  Node* right;

  int val;

} typedef Node;

//class BinaryTree {
// public:
//
// private:
//  Node* root;
//};

// Run DFS and have it return depth of all leaf nodes
// Balanced tree must be balanced anywhere in the tree - recursive call on child nodes

int runTree(Node* node, int& depth)
{
  int leftDepth = 0;
  int rightDepth = 0;
  int leftBalanced = 0;
  int rightBalanced = 0;
  
  if (node->left) {
    leftBalanced = runTree(node->left, leftDepth);
    leftDepth++;
    std::cout << "Left node depth : " << leftDepth << std::endl;
  }
  if (node->right) {
    rightBalanced = runTree(node->right, rightDepth);
    rightDepth++;
    std::cout << "Right node depth : " << rightDepth << std::endl;
  }
  if (!(node->left) && !(node->right)){ // leaf node
    depth = 0;
    return 0;
  }

  depth = (leftDepth > rightDepth) ? leftDepth : rightDepth;

  if ((leftBalanced < 0) || (rightBalanced < 0)) {
    return -1;
  }

  if (std::abs(leftDepth - rightDepth) > 1) { //depth diff by more than one
    return -1;
  }

  return 0;
}

int checkIfBalanced(Node* root)
{
  int depth;
  return runTree(root, depth);
}

int checkHeightOfBalanced(Node* root)
{
// return : height (-1 is unbalanced)
  int leftHeight;
  int rightHeight;  

  if (!root->left && !root->right)
  {  return 0; }

  if (root->left) {
    leftHeight = checkHeightOfBalanced(root->left);
    leftHeight++;
  }

  if (root->right) {
    rightHeight = checkHeightOfBalanced(root->right);
    rightHeight++;
  }

  if ( std::abs(rightHeight - leftHeight) > 1 )
    return -1;

  return std::max(rightHeight, leftHeight);
}

int main()
{
  Node* root = new Node(0);
  
  Node* node1 = new Node(1);
  Node* node2 = new Node(2);
  Node* node3 = new Node(3);
  Node* node4 = new Node(4);
  Node* node5 = new Node(5);
  Node* node6 = new Node(6);
  Node* node7 = new Node(7);
  Node* node8 = new Node(8);
  Node* node9 = new Node(9);

  root->left = node1;
  node1->left = node2;
  node1->right = node3;
  root->right = node4;
  node4->left = node5;
  node4->right = node6;
  node6->left = node7;
  node7->left = node8;
  node6->right = node9;

  std::cout << "This tree is " << ((checkIfBalanced(root) < 0) ? "not balanced" : "balanced") << std::endl;
  std::cout << "This tree is " << ((checkHeightOfBalanced(root) < 0) ? "not balanced" : "balanced") << std::endl;
    
  return 0;
}
