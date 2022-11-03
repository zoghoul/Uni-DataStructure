#include <iostream.h>

template <class ItemType>
struct node
{
ItemType info;
	node* next;
};
template <class ItemType>
class Queue
{
public:
	  Queue  ()      { front = rear = NULL;}
	 ~Queue  ()      { makeEmpty(); }
 int isEmpty()const { return (front == NULL);}
 int isFull() const;
 int enQueue(ItemType );
 int deQueue(ItemType&);
void makeEmpty();
private:
  node<ItemType>* front;
  node<ItemType>* rear;
};
/**********************************************************/
template <class ItemType>
void Queue<ItemType>::makeEmpty()
{
 node<ItemType>* tempPtr;
 while (front != NULL)
 {
	tempPtr = front;
	front = front->next;
	delete tempPtr;
 }
 rear = NULL;
}

template<class ItemType>
int Queue<ItemType>::isFull() const
{
 node<ItemType>* location;
 try
 {
	location = new node<ItemType>;
	delete location;
	return 0;
 }
 catch(...) { return 1; }
}
// Adds newItem to the rear of the queue.
// Pre: Queue has been initialized.
// Post: If (queue is not full), newItem is at the rear of the queue;
// otherwise, a FullQueue exception is thrown.
template <class ItemType>
int Queue<ItemType>::enQueue(ItemType newItem)
{
 if (isFull())
	return 0;
 else
 {
	node<ItemType>* newNode;
	newNode = new node<ItemType>;
	newNode->info = newItem;
	newNode->next = NULL;
	if (rear == NULL)
	  front = newNode;
	else
	  rear->next = newNode;
	rear = newNode;
 }
 return 1;
}
// Removes front item from the queue and returns it in item.
// Pre: Queue has been initialized
// Post: If (queue is not empty), the front of the queue has been
// removed and a copy returned in item;
// otherwise, an EmptyQueue exception is thrown.
template <class ItemType>
int Queue<ItemType>::deQueue(ItemType& item)
{
 if (isEmpty())
	return 0;
 else
 {
	node<ItemType>* tempPtr;
	tempPtr = front;
	item = front->info;
	front = front->next;
	if (front == NULL)
		rear = NULL;
	delete tempPtr;
 }
 return 1;
}

/**********************************************************/

void main ()
{
  Queue <int> q1;
  q1.enQueue(1);
  q1.enQueue(2);
  q1.enQueue(3);
  q1.enQueue(4);

  for (int x; !q1.isEmpty(); cout << x << ' ')
	 q1.deQueue(x);
}
