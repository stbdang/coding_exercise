#include <iostream>

struct Node {
  Node(int value) : val(value), left(NULL), right(NULL), parent(NULL) {}
  Node* left;
  Node* right;
  Node* parent;
  int val;

} typedef Node;

class BST {
 public:
  BST() : root(NULL) {}
  void addNode(int val);
  void printTree();
  int findNextVal(int val);

 private:
  void printRecursive(Node* node);
  int findDepth(Node* node);
  Node* findNextNode(Node* node);
  Node* findNode(int val);

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
        cursor->right->parent = cursor;
        return;
      }
    } else {
      if ( cursor->left ) {
        cursor = cursor->left;
        continue;
      } else {
        cursor->left = new Node(val);
        cursor->left->parent = cursor;
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

Node* BST::findNextNode(Node* node)
{
  if (node->right)
  {
    Node* immediateNext = node->right;
    while(immediateNext->left)
      immediateNext = immediateNext->left;
    return immediateNext;

  }
  //we need to go to parent and search now
  // if it's the left node of the parent, return parent
  while(node->parent)
  {
    std::cout << node->parent->val << std::endl;
    if ( node == node->parent->left)
      return node->parent;
    node = node->parent;
  }

  return NULL;
}

Node* BST::findNode(int val)
{
  Node* cursor = root;

  while(cursor) {
    if(val < cursor->val) {
      cursor = cursor->left;

    } else if (val > cursor->val) {
      cursor = cursor->right;
    } else { // equal
      std::cout << "Node found" <<std::endl;
      return cursor;
    }
  }

  return NULL;
}

int BST::findNextVal(int val)
{
  Node* node = findNode(val);

  Node* nextNode = findNextNode(node);

  if (nextNode)
    return nextNode->val;

  return -1;
}

int main()
{
  BST myBST;
 
  myBST.addNode(5);
  myBST.addNode(4);
  myBST.addNode(7);
  myBST.addNode(11);
  myBST.addNode(42);
  myBST.addNode(12);
  myBST.addNode(0);
  myBST.addNode(8);
  myBST.addNode(9);
  myBST.addNode(1);
  myBST.addNode(2);
  myBST.addNode(3);

  int nextVal = myBST.findNextVal(7);
  
  std::cout << "Next val : " << nextVal << std::endl;
  return 0;
}

