#include <iostream.h>

struct NodeType
{
	double  info;
 NodeType* next;
};

class StackType
{
public:
		 StackType() {topPtr = '\0';}
		~StackType();
	int Push(double);
	int Pop ();
double Top () const;
private:
	NodeType* topPtr;
	int IsEmpty() const {return (topPtr == '\0');}
//	int IsFull () const;
};

StackType::~StackType()
{
 NodeType* tempPtr;
 while (topPtr != '\0')
 {
	tempPtr = topPtr;
	topPtr = topPtr->next;
	delete tempPtr;
 }
}
int StackType::Push(double newItem)
{
 try{
	NodeType* location;
	location = new NodeType;
	location->info = newItem;
	location->next = topPtr;
	topPtr = location;
	return 1;
	}
 catch (...)
	{return 0;}
}

int StackType::Pop()
{
 if (IsEmpty())
	return 0;
 else
 {
  NodeType* tempPtr;
  tempPtr = topPtr;
  topPtr = topPtr->next;
  delete tempPtr;
  return 1;
 }
}

double StackType::Top() const
{
 if (IsEmpty())
	return 0;
 else
	return topPtr->info;
}

void main ()
{
  StackType s;
  s.Push(10);  s.Push(20);
  s.Push(30);  s.Push(40);

  cout << s.Top() << ' ' ;  s.Pop();
  cout << s.Top() << ' ' ;  s.Pop();
  cout << s.Top() << ' ' ;  s.Pop();
  cout << s.Top() << ' ' ;  s.Pop();
}



/*
int StackType::IsFull() const
// Returns true if there is no room for another NodeType object
// on the free store and false otherwise.
{
NodeType* location;
try
{
location = new NodeType;
delete location;
return 0;
}
catch(...)
{
return 1;
}
}
*/