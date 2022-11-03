#include <iostream.h>
// Liner Queue
template <class T>
class Queue
{
public:
      Queue(int max=100);
     ~Queue()         { delete [] items; }
  int isEmpty() const { return (rear == front); }
  int isFull () const { return ((rear + 1)==maxQue ); } //1
 void makeEmpty()     { front = rear = - 1; }           //2;
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
 maxQue = max;
 front = rear = -1; // 3
 items = new T[maxQue];
}

template <class T>
int Queue<T>::enQueue(T newItem)
// If (queue is not full) newItem is at the rear of the queue
{
 if (isFull())
    return 0;
 rear++;   // 4
 items[rear] = newItem;
 return 1;
}

template <class T>
int Queue<T>::deQueue(T& item)
// If (queue is not empty) the front of the queue has been removed and returned
{
 if (isEmpty())
    return 0;
 front++; // 5
 item = items[front];
 return 1;
}
template <class T>
void Queue<T>::printAll () const
{
	for (int i=front+1; i<=rear; i++)
		cout << items[i] << " ";
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