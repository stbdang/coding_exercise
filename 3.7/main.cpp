#include <iostream>
#include <string>

struct Animal
{
  Animal(std::string name, int kind)
    : name(name)
    , kind(kind)
    , next(NULL)
  {
  }
    
  std::string name;
  int kind; // dog = 0, cat = 1
  Animal* next;

} typedef Animal;

class AnimalInventory
{
 public:
  AnimalInventory();
  void enqueue(Animal* newAnimal);
  Animal* dequeueAny();
  Animal* dequeueDog();
  Animal* dequeueCat();

 private:
  Animal* dequeue(int kind);
  Animal* head;
  Animal* tail;

};

AnimalInventory::AnimalInventory()
  :head(NULL)
  ,tail(NULL)
{
}

void AnimalInventory::enqueue(Animal* newAnimal)
{
  if (!head) {
    head = newAnimal;
    tail = head;
  }

  tail->next = newAnimal;  
  tail = newAnimal;
}

Animal* AnimalInventory::dequeue(int kindLooking)
{
  Animal* cursor = head;
  Animal* prev = NULL;
  
  while(cursor){
    if(cursor->kind == kindLooking || kindLooking == -1) {
      if (cursor==head) {
        head = head->next;
        return cursor;
      } 
      if (cursor==tail) {
        tail = prev;
      }
      prev->next = cursor->next;
      return cursor;      
    }
    prev = cursor;
    cursor = cursor->next; 
  }
}

Animal* AnimalInventory::dequeueAny()
{
  return dequeue(-1);
}

Animal* AnimalInventory::dequeueDog()
{
  return dequeue(0);
}

Animal* AnimalInventory::dequeueCat()
{
  return dequeue(1);
}

int main()
{
  AnimalInventory myInventory;
  myInventory.enqueue(new Animal("Sarah", 1));
  myInventory.enqueue(new Animal("Michelle", 1));
  myInventory.enqueue(new Animal("David", 0));
  myInventory.enqueue(new Animal("Daniel", 1));
  myInventory.enqueue(new Animal("Andrew", 0));
  myInventory.enqueue(new Animal("Grace", 0));

  Animal* temp;

  temp = myInventory.dequeueCat();
  std::cout << "I got a " << (temp->kind ? "cat" : "dog") << " named " << temp->name << std::endl;

  temp = myInventory.dequeueDog();
  std::cout << "I got a " << (temp->kind ? "cat" : "dog") << " named " << temp->name << std::endl;

  temp = myInventory.dequeueAny();
  std::cout << "I got a " << (temp->kind ? "cat" : "dog") << " named " << temp->name << std::endl;

  myInventory.enqueue(new Animal("Josh", 0));
  myInventory.enqueue(new Animal("Kelly", 1));


  temp = myInventory.dequeueCat();
  std::cout << "I got a " << (temp->kind ? "cat" : "dog") << " named " << temp->name << std::endl;

  temp = myInventory.dequeueCat();
  std::cout << "I got a " << (temp->kind ? "cat" : "dog") << " named " << temp->name << std::endl;

  temp = myInventory.dequeueAny();
  std::cout << "I got a " << (temp->kind ? "cat" : "dog") << " named " << temp->name << std::endl;

  return 0;
}
 
