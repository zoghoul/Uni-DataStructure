#include <iostream.h>
template <class T>
struct node
{
	 T  info;
 node* next;
};
template <class T>
class StackType
{
public:
		 StackType() {topPtr = '\0';}
		~StackType();
	int Push(T);
	int Pop ();
	  T Top () const;
private:
	node<T>* topPtr;
	int IsEmpty() const {return (topPtr == '\0');}
//	int IsFull () const;
};

template <class T>
StackType<T>::~StackType()
{
 node<T>* tempPtr;
 while (topPtr != '\0')
 {
	tempPtr = topPtr;
	topPtr = topPtr->next;
	delete tempPtr;
 }
}

template <class T>
int StackType<T>::Push(T newItem)
{
 try{
	node<T>* location;
	location = new node<T>;
	location->info = newItem;
	location->next = topPtr;
	topPtr = location;
	return 1;
	}
 catch (...)
	{return 0;}
}

template <class T>
int StackType<T>::Pop()
{
 if (IsEmpty())
	return 0;
 else
 {
  node<T>* tempPtr;
  tempPtr = topPtr;
  topPtr = topPtr->next;
  delete tempPtr;
  return 1;
 }
}

template <class T>
T StackType<T>::Top() const
{
 if (IsEmpty())
	return 0;
 else
	return topPtr->info;
}

void main ()
{
  StackType <int> s;
  s.Push(10);  s.Push(20);
  s.Push(30);  s.Push(40);

  cout << s.Top() << ' ' ;  s.Pop();
  cout << s.Top() << ' ' ;  s.Pop();
  cout << s.Top() << ' ' ;  s.Pop();
  cout << s.Top() << ' ' ;  s.Pop();
}



/*
int StackType::IsFull() const
// Returns true if there is no room for another node object
// on the free store and false otherwise.
{
node<T>* location;
try
{
location = new node<T>;
delete location;
return 0;
}
catch(...)
{
return 1;
}
}
*/