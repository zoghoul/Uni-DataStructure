#include <iostream.h>

template <class T, const int MAX_ITEMS=100>
class Stack
{
public:
		 Stack();
	int isFull()   const;
	int isEmpty()  const;
	int lengthIs() const;
  void push(T item);
	  T pop ();
private:
	int length;
	  T info[MAX_ITEMS];
};
/*************************************************/
template <class T, const int MAX_ITEMS>
	Stack<T, MAX_ITEMS>::Stack()
		{ length = 0; }

template <class T, const int MAX_ITEMS>
  int Stack<T, MAX_ITEMS>::isFull() const
		{ return (length == MAX_ITEMS); }

template <class T, const int MAX_ITEMS>
  int Stack<T, MAX_ITEMS>::isEmpty() const
		{ return (length == 0); }

template <class T, const int MAX_ITEMS>
  int Stack<T, MAX_ITEMS>::lengthIs()const
		{ return length; }

template <class T, const int MAX_ITEMS>
 void Stack<T, MAX_ITEMS>::push(T item)
		{
		if(! isFull())
			info[length++]=item;
		}

template <class T, const int MAX_ITEMS>
 T Stack<T, MAX_ITEMS>::pop()
		{
		if(! isEmpty())
			return info[--length];
		return 0;
		}
/*************************************************/
void main ()
{
	Stack <int,4>L1;
	L1.push(10);
	L1.push(20);
	L1.push(30);
	L1.push(40);
	cout << L1.pop() << " ";
	cout << L1.pop() << " ";
	cout << L1.pop() << " ";
	cout << L1.pop() << "\n";

	Stack <char>L2;
	L2.push('a');
	L2.push('b');
	L2.push('c');
	L2.push('d');
	L2.push('e');
	cout << L2.pop() << " ";
	cout << L2.pop() << " ";
	cout << L2.pop() << " ";
	cout << L2.pop() << "\n";
}