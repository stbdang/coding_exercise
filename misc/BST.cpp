#include <iostream>

using namespace std;

enum TraversalMode
{
  PREORDER,
  INORDER,
  POSTORDER
};

struct Node {
  Node()
   : left(NULL)
   , right(NULL)
  {};

  Node(int value)
   : left(NULL)
   , right(NULL)
   , val(value)
  {};

  Node* left;
  Node* right;
  int val;
} typedef Node;

class BST
{
 public:
  BST() { root=NULL; };
  void insert(int val);
  void remove(int val);
  void traversal(int mode);

 private:
  void preOrderCB(Node* node);
  void inOrderCB(Node* node);
  void postOrderCB(Node* node);
  void traverse(Node* node, int mode);
  Node* root;
};

void BST::insert(int val)
{
  Node* newNode = new Node(val);

  if (!root)
  {
    root = newNode;
    return;
  }
  
  Node* cur = root;
  Node* parent;
  while (cur)
  {
    parent = cur;
    if (val < cur->val)
      cur = cur->left;
    else
      cur = cur->right;
  }
  
  if (val < parent->val)
    parent->left = newNode;
  else
    parent->right = newNode; 
}

void BST::remove(int val)
{
//Can't be bothered to implement...MEH
}

void BST::preOrderCB(Node* node)
{
  cout << "Preorder traversal : " << node->val << endl;
}

void BST::inOrderCB(Node* node)
{
  cout << "Inorder traversal : " << node->val << endl;
}

void BST::postOrderCB(Node* node)
{
  cout << "Postorder traversal : " << node->val << endl;
}

void BST::traverse(Node* node, int mode)
{
  if (!node)
    return;

  if ( mode == PREORDER )
    preOrderCB(node);

  traverse(node->left, mode);

  if ( mode == INORDER )
    inOrderCB(node);

  traverse(node->right, mode);

  if ( mode == POSTORDER )
    postOrderCB(node);
}

void BST::traversal(int mode)
{
  traverse(root, mode);
}

int main()
{
  BST myBST;

  myBST.insert(20); 
  myBST.insert(5); 
  myBST.insert(15); 
  myBST.insert(25); 
  myBST.insert(10); 
  myBST.insert(0); 
  myBST.insert(30); 
  
  myBST.traversal(PREORDER);
  myBST.traversal(INORDER);
  myBST.traversal(POSTORDER);

  return 0;
}

