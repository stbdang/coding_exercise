#include <iostream>

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

void computeSum(Node* node*, int sumUntilNow)
{
  if (!node)
    return;

  node->sum = sumUntilNow + val;
  
  computeSum(node->left, node->sum);
  computeSum(node->right, node->sum);
   
}

int checkAndPrint(Node* node, int val, int runningSum)
{
  if(!node)
    return 0;

  int sum = runningSum + node->val;

  if (sum == val)
  {
    std::cout << std::endl << "Found !!" << std::endl;
    std::coun << node->val << " ";
    return 1;
  } 

  if (checkAndPrint(node->left, val, sum))
  {
    std::cout << node->val << " ";
    return 1;
  }

  return 0;
}

void printAllPaths(Node* root, int val);
{
   


}

int main()
{
  
}

