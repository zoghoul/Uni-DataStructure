#include <iostream>
using namespace std;

template <class ItemType>
class SpecializedList
{
private:
	struct node
	{
	 ItemType info;
		 node *next,*back;
	};
	int length;     //optinal
	node* list;
	node *currentNextPos,
		 *currentBackPos;
public:
		  SpecializedList() {length = 0; list = NULL;}
//		 ~SpecializedList(); // Class destructor. you should use makeEmpty();

	void ResetForward (){currentNextPos = NULL;}
	void ResetBackward(){currentBackPos = NULL;}

	void GetNextItem (ItemType& item, int& finished);
	void GetPriorItem(ItemType& item, int& finished);

	void InsertFront(ItemType item);
	void InsertEnd  (ItemType item);
	void InsertItem (ItemType item);
	 int deleteItem (ItemType item);

	 int LengthIs() const {return length;}
	void printForward () const;
	void printBackward() const;
};


template<class ItemType>
void SpecializedList<ItemType>::GetNextItem(ItemType& item, int& finished)
{
 if (currentNextPos == NULL)
	currentNextPos = list->next;
 else
	currentNextPos = currentNextPos->next;
 item = currentNextPos->info;
 finished = (currentNextPos == list);
}

template<class ItemType>
void SpecializedList<ItemType>::GetPriorItem(ItemType& item,int& finished)
{
 if (currentBackPos == NULL)
	currentBackPos = list;
 else
	currentBackPos = currentBackPos->back;
 item = currentBackPos->info;
 finished = (currentBackPos == list->next);
}

template<class ItemType>
void SpecializedList<ItemType>::InsertFront(ItemType item)
{
 node* newNode;
 newNode = new node;
 newNode->info = item;
 if (list == NULL)
 { // list is empty.
	newNode->back = newNode;
	newNode->next = newNode;
	list = newNode;
 }
 else
 {
	newNode->back = list;
	newNode->next = list->next;
	list->next->back = newNode; //newNode->back->next=newNode;
	list->next = newNode;       //newNode->next->back=newNode;
 }
 length++;
}

template<class ItemType>
void SpecializedList<ItemType>::InsertEnd(ItemType item)
{
 InsertFront(item);
 list = list->next;
}

template<class ItemType>
void SpecializedList<ItemType>::InsertItem(ItemType item)
{
 node* newNode;
 newNode = new node;
 newNode->info = item;
 if (list == NULL)
 { // list is empty.
	newNode->back = newNode;
	newNode->next = newNode;
	list = newNode;
 }
 else
 {
  node *i;
  for (i=list->next; i!=list; i=i->next)
	if( i->info > item )
	{
	  newNode->back = i->back;
	  newNode->next = i;
	  (i->back)->next = newNode;
	  i->back=newNode;
	  length++;return;
	}
  if( list->info >= item )
	{
	  i=list;  // optinal
	  newNode->back = i->back;
	  newNode->next = i;
	  (i->back)->next = newNode;
	  i->back=newNode;
	}
  else
	{
	  i=list;  // optinal
	  list=newNode;
	  newNode->back = i;
	  newNode->next = i->next;
	  (i->next)->back = newNode;
	  i->next=newNode;
	}
 }
 length++;
}
template<class ItemType>
int SpecializedList<ItemType>::deleteItem(ItemType item)
{
 if (list==NULL)
	return 0;
 node* i;
 for (i=list->next; i!=list; i=i->next)
	if( i->info == item )
	{
	  (i->back)->next=i->next;
	  (i->next)->back=i->back;
	  delete i;
	  return 1;
	}
	if( list->info == item )
	{
	  i=list;  // optinal
	  list=list->back;
	  list->next=i->next;
	  (i->next)->back=list;
	  delete i;
	  return 1;
	}
 return 0;
}

template<class ItemType>
void SpecializedList<ItemType>::printForward() const
{
 if (list==NULL)
	return;
 for (node* i=list->next; i!=list; i=i->next)
	cout << i-> info << ' ';
 cout<< list->info << ' ';
}

template<class ItemType>
void SpecializedList<ItemType>::printBackward() const
{
 if (list==NULL)
	return;
 cout<< list->info << ' ';
 for (node* i=list->back; i!=list; i=i->back)
	cout << i-> info << ' ';
}

/*************************************************/
template <class t>
void printBack(SpecializedList<t> l,t item)
{
  int finished=1;
  l.GetNextItem(item, finished);
  if (!finished)
	 printBack(l,item);
  cout << item << ' ' ;
}
/*************************************************/

int main ()
{

	SpecializedList <int>   l1;
	l1.ResetForward ();
	l1.ResetBackward();

	l1.InsertFront(1); l1.InsertEnd(3);
	l1.InsertFront(6); l1.InsertEnd(4);
	l1.InsertFront(5); l1.InsertEnd(2);

	l1.deleteItem (6);
	l1.deleteItem (2);

	l1.printForward ();
	cout <<endl;
	l1.printBackward();

	cout << endl;
	int x=10;
	printBack(l1,x);
	cout << endl;

	cout << "\n\n\t * * *\n\n";
	SpecializedList <int>   l2;
	l2.ResetForward ();
	l2.ResetBackward();

	l2.InsertItem(1); l2.InsertItem(3);
	l2.InsertItem(6); l2.InsertItem(4);
	l2.InsertItem(5); l2.InsertItem(2);

	l2.deleteItem (6);
	l2.deleteItem (2);

	l2.printForward ();
	cout <<endl;
	l2.printBackward();

	cout << endl;

	return 0;
}
