#include <iostream.h>

template<class ItemType>
struct node
{
ItemType info;
	node* next;
};

template <class ItemType>
class UnsortedLinkList
{
private:
	int length;     //optinal
	node<ItemType>* listData;
	node<ItemType>* currentPos;
public:
	  UnsortedLinkList(){ length = 0; listData = NULL; }
	 ~UnsortedLinkList(){ makeEmpty(); }
void resetList() { currentPos = NULL; }
 int lengthIs() const  { return length; }
 int isFull()   const;
void makeEmpty();
 int retrieveItem(ItemType item);
void getNextItem (ItemType& item);
 int insertItem  (ItemType item);
 int deleteItem  (ItemType item);
};

template<class ItemType>
int UnsortedLinkList<ItemType>::isFull() const
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

template <class ItemType>
void UnsortedLinkList<ItemType>::makeEmpty()
{
 node<ItemType>* tempPtr;
 while (listData != NULL)
 {
	tempPtr = listData;
	listData = listData->next;
	delete tempPtr;
 }
 length = 0;
}

template <class ItemType>
int UnsortedLinkList<ItemType>::retrieveItem(ItemType item)
{
 node<ItemType>* location;
 for (location = listData; location != NULL;location = location->next)
	if (item == location->info)
	  return 1;
 return 0;
}


template <class ItemType>
int UnsortedLinkList<ItemType>::insertItem(ItemType item)
{
 if (isFull())
	 return 0;
 node<ItemType>* location;
 location = new node<ItemType>;
 location->info = item;
 location->next = listData;
 listData = location;
 length++;
 return 1;
}

template <class ItemType>
int UnsortedLinkList<ItemType>::deleteItem(ItemType item)
{
 if (listData==NULL)
	 return 0;
 node<ItemType>* location = listData;
 node<ItemType>* tempLocation;
 if (item == listData->info)
 {
	tempLocation = location;
	listData = listData->next; // Delete first node.
 }
 else
 {
	while (!(item==(location->next)->info))
		location = location->next;
	// Delete node at location->next.
	tempLocation = location->next;
	location->next = (location->next)->next;
 }
 delete tempLocation;
 length--;
 return 1;
}

template <class ItemType>
void UnsortedLinkList<ItemType>::getNextItem(ItemType& item)
{
 if (currentPos == NULL)
	currentPos = listData;
 else
	currentPos = currentPos->next;
 item = currentPos->info;
}
/*************************************************/
void main ()
{

	UnsortedLinkList <int>   l1;
	//UnsortedLinkList <char>  l2;
	//UnsortedLinkList <float> l3;

	l1.insertItem(1); l1.insertItem(2);
	l1.insertItem(3); l1.insertItem(4);
	l1.insertItem(5); l1.insertItem(6);

	l1.deleteItem (4);

}
