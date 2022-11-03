#include <iostream.h>
// Circular Queue Size+1
template <class T>
class Queue
{
public:
      Queue(int max=100);
     ~Queue()         { delete [] items; }
  int isEmpty() const { return (rear == front); }
  int isFull () const { return ((rear + 1) % maxQue == front); }	  //r+1=max
 void makeEmpty()     { front = rear = maxQue - 1; }	// Not needed //f=r=-1; 
 void printAll () const;
  int enQueue(T newItem);
  int deQueue(T& item);
private:
  int front, rear;
  T * items;
  int maxQue;
};
/*****************************************************************************/
template <class T>
     Queue<T>::Queue(int max)
{
 maxQue = max+1 ;
 front = rear = maxQue-1; // -1
 items = new T[maxQue];
}

template <class T>
int Queue<T>::enQueue(T newItem)
// If (queue is not full) newItem is at the rear of the queue
{
 if (isFull())
    return 0;
 rear = (rear +1) % maxQue;   // rear++;
 items[rear] = newItem;
 return 1;
}

template <class T>
int Queue<T>::deQueue(T& item)
// If (queue is not empty) the front of the queue has been removed and returned
{
 if (isEmpty())
    return 0;
 front = (front + 1) % maxQue;   // front++;
 item = items[front];
 return 1;
}

template <class T>
void Queue<T>::printAll () const
{
	for (int i=front+1; i!=rear; i=(i+1)%maxQue)
		cout << items[i] << " ";
	if (!isEmpty())
		cout << items[i] << " ";
	cout << endl;
}
/*****************************************************************************/
void main()
{
 Queue <int> line(3);
 int x;

 line.enQueue(10); line.enQueue(20);
 line.deQueue(x); 
 line.enQueue(30); line.enQueue(40);
 line.deQueue(x);
 line.enQueue(50);
 
 line.printAll();

 if(line.deQueue(x)) cout << x << " ";
 if(line.deQueue(x)) cout << x << " ";
 if(line.deQueue(x)) cout << x << " ";
}