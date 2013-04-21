#include <iostream>
#include <string>

using namespace std;
#define NUM_BUCKET 100

struct Node
{
  Node();
  string key;
  int val;
  Node* prev;
  Node* next;
} typedef Node;

Node::Node()
 : val (0),
 prev (NULL),
 next (NULL)
{

}

class HashTable
{
public:
  //default constructor and destructor
  void Insert(string key, int val);
  void Delete(string key, int val);

  int Value(string key);

private:
  unsigned int Hash(string key);
  void removeNode(Node* toBeRemoved, int index);
  Node table[NUM_BUCKET];

};

//This is a hashing function
unsigned int HashTable::Hash(string key)
{
  unsigned long sum = 0;
  for (int i = 0 ; i < key.length(); i++)
  {
    sum += (unsigned int)key[i];
  }
  cout << "Hash for " << key << " is " << sum % NUM_BUCKET << endl;
  return sum % NUM_BUCKET;
}

void HashTable::Insert(string key, int val)
{
  unsigned int index = this->Hash(key);
  Node* cursor = &table[index];
  Node* lastItem;

  if (table[index].key.empty())
  {
    table[index].key = key;
    table[index].val = val;
    return;
  }

  while(cursor)
  {
    if (cursor->key == key)
    {
      cout << "Same key already exists\n";
      return;
    }
    lastItem = cursor;
    cursor = cursor->next;
  }

  lastItem->next = new Node;
  lastItem->next->val = val;
  lastItem->next->key = key;
  lastItem->next->prev = lastItem;
}

void HashTable::removeNode(Node* toBeRemoved, int index)
{
  if (toBeRemoved == &table[index]) //special case where we need to remove the first item.
  {
    toBeRemoved->val = 0;

    Node* toBeCollapsed = toBeRemoved->next;
    if (toBeCollapsed)
    {
      toBeRemoved->next = toBeCollapsed->next;
      toBeRemoved->val = toBeCollapsed->val;
    }
    delete toBeCollapsed;
    return;
  }

  //General case
  if (!toBeRemoved->next)
  {
    toBeRemoved->prev->next = NULL;
    delete toBeRemoved;
    return;
  }

  toBeRemoved->prev->next = toBeRemoved->next;
  toBeRemoved->next->prev = toBeRemoved->prev;
  delete toBeRemoved;
  return;

}

void HashTable::Delete(string key, int val)
{
  unsigned int index = this->Hash(key);

  Node* cursor = &table[index];

  while(cursor)
  {
    Node* nextItem = cursor->next;
    if (key == cursor->key && val == cursor->val)
    {
      this->removeNode(cursor, index);
    }
    cursor = nextItem;
  }
}

int HashTable::Value(string key)
{
  unsigned int index = this->Hash(key);

  Node* cursor = &table[index];

  while(cursor)
  {
    if (key == cursor->key)
      return cursor->val;
    cursor=cursor->next;
  }
  return -1;
}

int main()
{
  HashTable* table = new HashTable;

  table->Insert("Test", 1);
  table->Insert("Test", 1);
  table->Insert("Test22", 133);
  table->Insert("Test3", 14);
  table->Insert("Test4", 144);
  table->Insert("Tes33", 134);
  table->Insert("Tes22", 1111);
  table->Insert("Tes22", 19);
  table->Insert("Tes31", 19);

  cout << "HAHA " << table->Value("Test3") << endl;
  cout << "MEH? " << table->Value("eee") << endl;
  cout << "HMM  " << table->Value("Tes22") << endl;
  cout << "HMM  " << table->Value("Tes31") << endl;
  return 0;
}
