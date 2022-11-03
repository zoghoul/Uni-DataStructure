#include <iostream.h>
// Circular Queue Count
template <class T>
class Queue
{
public:
      Queue(int max=100);
     ~Queue()         { delete [] items; }
  int isEmpty() const { return (count == 0); }		// rear == front
  int isFull () const { return (count == maxQue); } 
 //void makeEmpty()     { front = rear = - 1; }     // not needed
 void printAll() const;
  int enQueue(T newItem);
  int deQueue(T& item);
private:
  int front, rear, count;
  T * items;
  int maxQue;
};
/*****************************************************************************/
template <class T>
     Queue<T>::Queue(int max)
{
 maxQue = max;
 front = rear = -1; // 3
 items = new T[maxQue];
 count=0;
}

template <class T>
int Queue<T>::enQueue(T newItem)
// If (queue is not full) newItem is at the rear of the queue
{
 if (isFull())
    return 0;
 rear = (rear +1) % maxQue;   // 4
 items[rear] = newItem;
 count++;
 return 1;
}

template <class T>
int Queue<T>::deQueue(T& item)
// If (queue is not empty) the front of the queue has been removed and returned
{
 if (isEmpty())
    return 0;
 front = (front + 1) % maxQue; // 5
 item = items[front];
 count--;
 return 1;
}
// printAll from "Size+1" works as well
template <class T>
void Queue<T>::printAll () const
{
	for (int i=0; i<count; i++)
		cout << items[(i+front+1)%maxQue] << " ";
	cout << endl;
}

/*****************************************************************************/
void main()
{
 Queue <int> line(3);
 int x;

 line.enQueue(10);
 line.enQueue(20);
 line.deQueue(x);
 line.enQueue(30);
 line.enQueue(40);

 line.printAll();

 if(line.deQueue(x)) cout << x << " ";
 if(line.deQueue(x)) cout << x << " ";
 if(line.deQueue(x)) cout << x << " ";
}