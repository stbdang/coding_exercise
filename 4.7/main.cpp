#include <iostream>
#include <queue>

struct Node {
  Node(int value) : val(value), left(NULL), right(NULL) {}
  Node* left;
  Node* right;
  int val;

} typedef Node;

int isAncestor(Node* node, Node* decendent)
{
  std::queue<Node*> nodeQueue;
  
  nodeQueue.push(node);

  while (!nodeQueue.empty())
  {
    Node* nodeToExamine = nodeQueue.front();
    nodeQueue.pop();

    if (nodeToExamine == decendent) {
      std::cout << "Found " << nodeToExamine->val << std::endl;
      return 1;
    }
    
    if (nodeToExamine->left)
      nodeQueue.push(nodeToExamine->left);

    if (nodeToExamine->right)
      nodeQueue.push(nodeToExamine->right);

  }

  return 0;

}

Node* findCommonAncestor(Node* root, Node* node1, Node* node2)
{
  Node* cursor = root;

  while (cursor) {
    if (cursor->left) {
      if (isAncestor(cursor->left, node1) && isAncestor(cursor->left, node2)) {
        cursor = cursor->left;
        continue;
      }
    }
    
    if (cursor->right) {
      if (isAncestor(cursor->right, node1) && isAncestor(cursor->right, node2)) {
        cursor = cursor->right;
        continue;
      }
    }

    return cursor;
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

  root->left  = node3;
  root->right = node8;
  node3->left = node1;
  node1->right = node2;
  node3->right = node4;
  node8->left = node6;
  node6->right = node7;
  node8->right = node9;  
  node9->right = node10;  

  Node* commonAncestor = findCommonAncestor(root, node7, node9);

  std::cout << "Common ancestor is located at " << commonAncestor->val << std::endl;
  return 0;
}
