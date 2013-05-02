#include <iostream>
#include <vector>
#include <list>

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
  void createListsfromTree(std::vector<std::list<Node*> >& nodeLists);

 private:
  void printRecursive(Node* node);
  int findDepth(Node* node);
  void addToList(std::vector<std::list<Node*> >& nodeLists, Node* node, int level);

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

void BST::addToList(std::vector<std::list<Node*> >& nodeLists, Node* node, int level)
{
  //add current node to the list

  // check whether we have the list for level is created.
  std::vector<std::list<Node*> >::iterator it = nodeLists.begin();
  std::list<Node*> list;
  
  for (int i = 0; i < level; i++)  {
    it++;
  }

  if (it == nodeLists.end())
    nodeLists.push_back(list);

  it = nodeLists.begin();

  for (int i = 0; i < level; i++)  {
    it++;
  }
  
  if (it == nodeLists.end()) {
    std::cout << "WTF" <<std::endl;
    return;
  }

  (*it).push_back(node);
  

  if(node->left)
    addToList(nodeLists, node->left, level+1);

  if(node->right)
    addToList(nodeLists, node->right, level+1);
}

void BST::createListsfromTree(std::vector<std::list<Node*> >& nodeLists)
{
  addToList(nodeLists, root, 0);
}

int main() 
{
  BST myBST;
  std::vector<std::list<Node*> > nodeLists;

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

  myBST.createListsfromTree(nodeLists);

  std::vector<std::list<Node*> >::iterator it;
  int i = 0;
  for (it = nodeLists.begin(); it != nodeLists.end(); it++)
  {
    std::list<Node*>::iterator listIt;
   std::cout << "List " << i << " : ";
    for (listIt = (*it).begin(); listIt != (*it).end(); listIt++) {
      std::cout<< (*listIt)->val << " ";
    }
    std::cout << std::endl;
    i++;
  }

  return 0;
}
