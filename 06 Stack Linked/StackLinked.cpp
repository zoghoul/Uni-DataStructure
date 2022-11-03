typedef char ItemType;
struct NodeType;
class StackType
{
public:
StackType();
~StackType();
int Push(ItemType) ;
int Pop();
ItemType Top() const;
int IsEmpty() const;
int IsFull () const;
private:
NodeType* topPtr;
};

struct NodeType
{
ItemType info;
NodeType* next;
};

StackType::StackType() // Class constructor.
{
topPtr = '\0';
}

int StackType::IsEmpty() const
// Returns true if there are no elements on the stack and false otherwise.
{
return (topPtr == '\0');
}

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
StackType::~StackType()
// Post: Stack is empty; all items have been deallocated.
{
NodeType* tempPtr;
while (topPtr != '\0')
{
tempPtr = topPtr;
topPtr = topPtr->next;
delete tempPtr;
}
}
int StackType::Push(ItemType newItem)
// Adds newItem to the top of the stack.
// Pre: Stack has been initialized.
// Post: If stack is full, FullStack exception is thrown;
// else, newItem is at the top of the stack.
{
if (IsFull())
return 0;
else
{
NodeType* location;
location = new NodeType;
location->info = newItem;
location->next = topPtr;
topPtr = location;
return 1;
}
}

int StackType::Pop()
// Removes top item from stack
// Pre: Stack has been initialized.
// Post: If stack is empty, EmptyStack exception is thrown;
// else, top element has been removed.
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

ItemType StackType::Top() const
// Returns a copy of the top item in the stack.
// Pre: Stack has been initialized.
// Post: If stack is empty, EmptyStack exception is thrown
// else, a copy of the top element is returned.
{
if (IsEmpty())
return 0;
else
return topPtr->info;
}
void main ()
{
}