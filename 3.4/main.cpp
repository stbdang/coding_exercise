#include <iostream>

#define NUM 3

struct Node
{
  Node(int value) : val(value), next(NULL) {}

  int val;
  Node* next;
} typedef Node;

class RodStack
{
 public:
  RodStack();
  int push(int val);
  int pop(int& val);
  int peek(int& val);
  void printStack();
  int count;
 private:
  Node* top;
};

RodStack::RodStack()
  : top(NULL)
  , count(0)
{

}

int RodStack::push(int val)
{
  if (top && (val >= top->val))
  {
    return -2;
  }
  count++;
  Node* newNode = new Node(val);
  if (!top) {
    top = newNode;
    return 0;
  }
  
  newNode->next = top;
  top = newNode;
  return 0;
}

int RodStack::pop(int& val)
{
  if (!top) {
    return -1;
  }
  count--;
  val = top->val;
  Node* toBeDeleted = top;
  top = top->next;
  delete toBeDeleted;

  return 0;
}

int RodStack::peek(int& val)
{
  if (!top) {
    return -1;
  }

  val = top->val;
  return 0;
}

void RodStack::printStack()
{
  Node* cursor = top;
  while (cursor) {
    std::cout << " " << cursor->val;
    cursor=cursor->next;
  }

  std::cout << std::endl;
}

class TowersOfHanoi
{
 public:
  TowersOfHanoi(int N);
  int movePiece();
  int moveRecurse(int numBlocks, int origin, int destination);
  int findBuffer(int origin, int destination);
  int solveStep();
  int solveRecurse();
  void printTower();
 
 private:
  RodStack rods[3];
  int lastFrom;
  int lastTo;
  int numBlocks;

};

TowersOfHanoi::TowersOfHanoi(int N)
  : numBlocks(N)
{
  for(int i = N; i > 0; i--) {
    rods[0].push(i);
  }
  lastFrom = -1;
  lastTo = -1;
}

int TowersOfHanoi::movePiece()
{
  for (int i=0; i<3; i++) {
    for (int j = 2; j >=0; j--) {
      if(i!=j && !(i==lastTo && j==lastFrom)) { // to stop from going back and forth
        int val;
        if (rods[i].peek(val) < 0)
          continue;

        if (rods[j].push(val) < 0) {
	  std::cout << "Failed to push " << val << "to stack " << j << std::endl;
          continue;
        }

        // if it gets to this stage, it means we have pushed the value to the new stack, need to pop
        rods[i].pop(val); //no need to check since peek already succedeed.
        lastFrom = i;
        lastTo = j;
        return 0;
      }
    }
  }
  return -1;
}

int TowersOfHanoi::solveStep()
{
  while ( rods[2].count < numBlocks ) {
    for (int i =0; i <3; i++) {
      std::cout << "Stack " << i+1 << " : ";
      rods[i].printStack();
    }
    std::cout << std::endl;
    std::cin.ignore();
    movePiece();
  }
}

int TowersOfHanoi::findBuffer(int origin, int destination)
{
  for (int i = 0; i< 3; i++)
  {
    if ((i != origin) && (i != destination))
      return i;
  }
  return -1;
}

int TowersOfHanoi::moveRecurse(int numBlk, int origin, int destination)
{

  if (numBlk == 1) //end Case
  {
    int val;
    if (rods[origin].peek(val) < 0 ) {
      std::cout << "WAHT??" << std::endl;
      return -1;
    }

    if (rods[destination].push(val) < 0 ) {
      std::cout << "WTF" << std::endl;
      return -1;
    }
    rods[origin].pop(val);
    printTower();
    return 0;
  }

  moveRecurse(numBlk - 1, origin, findBuffer(origin, destination));

  // Need to handle general case // move Top
  int val;
  if (rods[origin].peek(val) == 0) {
    if ( val == numBlk ) {
      rods[destination].push(val);
      rods[origin].pop(val);
    }
    printTower();
  }

  moveRecurse(numBlk - 1, findBuffer(origin, destination), destination);

  return 0;
}

int TowersOfHanoi::solveRecurse()
{
  moveRecurse(numBlocks, 0, 2);
}

void TowersOfHanoi::printTower()
{
  for (int i =0; i <3; i++) {
    std::cout << "Stack " << i+1 << " : ";
    rods[i].printStack();
  }
  std::cout << std::endl;
  std::cin.ignore();

}

int main()
{
  TowersOfHanoi myPuzzle(5);
  myPuzzle.printTower();
  myPuzzle.solveRecurse();

  std::cout<<"Final result" << std::endl;
  myPuzzle.printTower();

  return 0;
}
