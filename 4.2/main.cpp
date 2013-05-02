#include <iostream>
#include <queue>
#include <list>

enum NodeState
{
  UNDISCOVERED,
  DISCOVERED,
  VISITED
};

struct GraphNode
{
  GraphNode(int value);
  std::list<GraphNode*> adjacents;
  int val;
  NodeState state;


} typedef GraphNode;

GraphNode::GraphNode(int value)
  : val(value)
  , state(UNDISCOVERED)

{
}

// The tricky part about this is that it's a directed graph. This means there could be a path from A to B but not from B to A.
// Use BFS to start at A and do an exhastive search untll all nodes are visited. Do the same for B.

int BFSTraversal(GraphNode* start, GraphNode* end)
{
  std::queue<GraphNode*> myQueue;
  myQueue.push(start);

  while(!myQueue.empty()) {
    GraphNode* cursor = myQueue.front();
    cursor->state = VISITED;
    myQueue.pop();
    
    if (cursor == end)
      return 1;
    
    for (std::list<GraphNode*>::iterator it=cursor->adjacents.begin();
	   it != cursor->adjacents.end(); it++) {
      if ((*it)->state == UNDISCOVERED) {
        std::cout << "Discovered node " << (*it)->val << std::endl;
        (*it)->state = DISCOVERED;
        myQueue.push(*it);
      }
    }
  }
  return 0;
}

void resetNodes(std::list<GraphNode*> nodeList)
{
  std::list<GraphNode*>::iterator it;
  for (it = nodeList.begin(); it != nodeList.end(); it++) {
    (*it)->state = UNDISCOVERED;
  }
}

int isTherePath(std::list<GraphNode*>& nodeList, GraphNode* node1, GraphNode* node2)
{
  std::cout << "Forward search" << std::endl;
  if (BFSTraversal(node1, node2))
    return 1;
  
  resetNodes(nodeList);
  
  std::cout << "Reverse search" << std::endl;
  if (BFSTraversal(node2, node1))
    return 1;

  return 0;
}

/* Sample graph
       1    ->    2     <->    3
       V                       ^V
       4          5      <     6
                  ^            ^
       7    >     8      >     9      
*/
int main()
{
  std::list<GraphNode*> nodeList;

  GraphNode* node1 = new GraphNode(1);  
  GraphNode* node2 = new GraphNode(2);  
  GraphNode* node3 = new GraphNode(3);  
  GraphNode* node4 = new GraphNode(4);  
  GraphNode* node5 = new GraphNode(5);  
  GraphNode* node6 = new GraphNode(6);  
  GraphNode* node7 = new GraphNode(7);  
  GraphNode* node8 = new GraphNode(8);  
  GraphNode* node9 = new GraphNode(9);  

  nodeList.push_back(node1);
  nodeList.push_back(node2);
  nodeList.push_back(node3);
  nodeList.push_back(node4);
  nodeList.push_back(node5);
  nodeList.push_back(node6);
  nodeList.push_back(node7);
  nodeList.push_back(node8);
  nodeList.push_back(node9);

  node1->adjacents.push_back(node2);
  node1->adjacents.push_back(node4);
  node2->adjacents.push_back(node3);
  node3->adjacents.push_back(node2);
  node3->adjacents.push_back(node6);
  node6->adjacents.push_back(node3);
  node6->adjacents.push_back(node5);
  node7->adjacents.push_back(node8);
  node8->adjacents.push_back(node5);
  node8->adjacents.push_back(node9);
  node9->adjacents.push_back(node6);
 
  GraphNode* start = node1;
  GraphNode* end = node7;
  
  std::cout << "Node " << start->val << " is " << ( isTherePath(nodeList, start, end) ? "connected to " : "not connetected to ") <<
    "Node " << end->val << std::endl;

  return 0;
}
