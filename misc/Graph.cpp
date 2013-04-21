#include <iostream>
#include <queue>

#define MAXV 10

using namespace std;

struct GraphNode
{
  GraphNode* next;
  int val;
} typedef GraphNode; 

typedef struct
{
  GraphNode nodes[MAXV];
} Graph;

void addEdge(Graph* graph, int from, int to)
{
  GraphNode* cur = &graph->nodes[from];

  while (cur->next)
  {
    if (cur->val == to)
      return; // Same edge already exists
    cur = cur->next;
  }

  //Reached the end of list
  GraphNode* newNode = new GraphNode;
  newNode->next = NULL;
  newNode->val = to;
  cur->next = newNode;
}

void emptyGraph(Graph* graph)
{
  for (int i = 0; i < MAXV; i++)
  {
    GraphNode* cur = graph->nodes[i].next;

    while (cur)
    {
      GraphNode* toBeDeleted = cur;
      cur = cur->next;
      delete toBeDeleted;
    }
  }
}

void printGraph(Graph* graph)
{
  for (int i = 0; i < MAXV; i++)
  {
    cout << "##### NODE " << i << " ######\n";
    GraphNode* cur = graph->nodes[i].next;
    while (cur)
    {
      cout << "Edge to " << cur->val << "\n";
      cur = cur->next;
    }
  }
  cout << "End of " << __func__ << endl;
}

enum NodeState
{
  UNDISCOVERED,
  DISCOVERED,
  PROCESSED
};

void bfsPrint(Graph* graph, int start)
{
  int state[MAXV];
  int parent[MAXV];
  queue<GraphNode*> nodeQueue;

  for (int i = 0 ; i < MAXV; i++)
  {
    state[i] = UNDISCOVERED;
    parent[i] = -1;
  }
  
  state[start] = DISCOVERED;
  nodeQueue.push(&graph->nodes[start]);

  //START dequeueing
  while ( !nodeQueue.empty() )
  {
    GraphNode* nodeToProcess = nodeQueue.front();
    nodeQueue.pop();
    cout << "On Node " << nodeToProcess->val << endl;
    // look for adjacent nodes and if they are not discovered,
    // push them to queue. Once done with all adjacent nodes transition to processed.
    GraphNode* cur = nodeToProcess->next;
    while (cur)
    {
      if (state[cur->val] == UNDISCOVERED)
      {
        state[cur->val] = DISCOVERED;
        parent[cur->val] = nodeToProcess->val;
        nodeQueue.push(&graph->nodes[cur->val]);
      }
      cur = cur->next;
    }
    state[nodeToProcess->val] = PROCESSED;
  }

  for (int i = 0; i < MAXV; i++ )
  {
    cout << "Node " << i << " was traversed from node " << parent[i] << endl;

  }

}

int main()
{
  //setup 10 node graph.
  Graph* myGraph = new Graph;
  for (int i = 0 ; i< MAXV; i++)
  {
    myGraph->nodes[i].next = NULL;
    myGraph->nodes[i].val = i;
  }

  addEdge(myGraph, 0, 1); 
  addEdge(myGraph, 0, 4); 

  addEdge(myGraph, 1, 0); 
  addEdge(myGraph, 1, 2); 

  addEdge(myGraph, 2, 1); 
  addEdge(myGraph, 2, 5); 

  addEdge(myGraph, 3, 6); 

  addEdge(myGraph, 4, 0); 
  addEdge(myGraph, 4, 6); 
  addEdge(myGraph, 4, 7); 

  addEdge(myGraph, 5, 2); 
  addEdge(myGraph, 5, 7); 
  addEdge(myGraph, 5, 8); 
  addEdge(myGraph, 5, 9); 

  addEdge(myGraph, 6, 3); 
  addEdge(myGraph, 6, 4); 
  addEdge(myGraph, 6, 7); 

  addEdge(myGraph, 7, 4); 
  addEdge(myGraph, 7, 5); 
  addEdge(myGraph, 7, 6); 
  addEdge(myGraph, 7, 8); 

  addEdge(myGraph, 8, 7); 
  addEdge(myGraph, 8, 5); 

  addEdge(myGraph, 9, 5); 

  printGraph(myGraph);

  cout << "BFS STARTS ------------------\n";
  bfsPrint(myGraph, 0);
  return 0;
}
