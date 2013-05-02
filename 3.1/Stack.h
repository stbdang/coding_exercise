struct Node {
  Node(int value) : next(NULL), val(value)
  { }

  Node* next;
  int val;
} typedef Node;


class Stack
{
 public:
  void push(int elem);
  int pop(int& val);

 private:
  Node* head; 
};
