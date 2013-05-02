#include <iostream>

struct Node {
  Node(int value) : val(value), left(NULL), right(NULL) {}
  Node* left;
  Node* right;
  int val;

} typedef Node;

class BST {
 public:
  BST() : root(NULL) {}
  void addNode(int val);
  void printTree();
  void constructBalanced(int val[], int start, int end);
  int findMaxdepth();

 private:
  void printRecursive(Node* node);
  int findDepth(Node* node);

  Node* root;
};

void BST::addNode(int val)
{
  std::cout<<"Adding " << val << std::endl;
  if (!root) {
    Node* newRoot = new Node(val);
    root = newRoot;
    return;
  }

  Node* cursor = root;

  while(cursor) {
    if (cursor->val < val) {
      if (cursor->right) {
        cursor = cursor->right;
        continue;
      } else {
        cursor->right = new Node(val);
        return;
      }
    } else {
      if ( cursor->left ) {
        cursor = cursor->left;
        continue;
      } else {
        cursor->left = new Node(val);
        return;
      }
    }
  }
}

void BST::printRecursive(Node* node)
{
  if(node->left)
    printRecursive(node->left);
  
  std::cout << "Node val : " << node->val << std::endl;

  if (node->right)
    printRecursive(node->right);
}

void BST::printTree()
{
  printRecursive(root);
}

void BST::constructBalanced(int val[], int start, int end)
{
  if (start > end)
    return;

  if (start == end) {
    addNode(val[start]);
    return;
  }
  addNode(val[(start + end)/2]);

  constructBalanced(val, start, (start + end)/2 - 1);  

  constructBalanced(val, (start+end)/2 + 1, end);  
}

int BST::findDepth(Node* node)
{
  if (!(node->left) && !(node->right))
    return 0;
 
  int leftDepth = 0;
  if (node->left)
    leftDepth = findDepth(node->left);

  int rightDepth = 0;
  if (node->right)
    rightDepth = findDepth(node->right);

  return ((leftDepth > rightDepth) ? leftDepth : rightDepth) + 1;
}
int BST::findMaxdepth()
{
  return findDepth(root); 
}

int main()
{
  BST myBST;
  
  int treeData[] = {-2, -1, 1, 3, 4, 6, 7, 8, 11, 14, 15, 21, 25, 26, 29};//, 30, 31, 32, 35, 37};
  
  std::cout << "Array length : " << sizeof(treeData)/sizeof(int) << std::endl;
  myBST.constructBalanced(treeData, 0, sizeof(treeData)/sizeof(int) - 1);
 // myBST.addNode(6);
 // myBST.addNode(3);
 // myBST.addNode(2);
 // myBST.addNode(9);
 // myBST.addNode(1);
 // myBST.addNode(33);
 // myBST.addNode(13);
 // myBST.addNode(4);
 // myBST.addNode(8);
 // myBST.addNode(21);
 // myBST.addNode(-1);
 // myBST.addNode(-2);

  myBST.printTree();

  std::cout << "Max depth of the tree is : " << myBST.findMaxdepth() << std::endl;

  return 0;
}

