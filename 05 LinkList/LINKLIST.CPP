#include <iostream.h>

template <class T>
class node
{
public:
  node(T d=0, node* n=NULL)
  {data=d; next=n;}
  node* next;
		T data;
};

template <class T>
class LinkList
{
public:
	    LinkList()       {head=new node<T>(0);}
	int isEmpty () const {return (head->data == 0);}
	int addItem (T item) ;
	int delItem (T item) ;

private:
	node <T>*head;
};
/*************************************************/

template <class T>
int LinkList<T>::addItem (T item)
{
 try
  {
	node<T>* newItem = new node<T> (item);
	for (node<T>* i=head->next; i != NULL; i=i->next);
	i->next=newItem;
	(head->data)++;
	return 1;
  }
  catch(...)
  {
	return 0;
  }
}

template <class T>
int LinkList<T>::delItem (T item)
{
 if (isEmpty())
	return 0;
 try
  {
	node<T>* i,*j=head;
	for (i=head->next; i != NULL; i=i->next)
		{
		 if (i->data == item)
			break;
		 j=i;
		}
	j->next=i->next;
	delete i;
	return 1;
  }
 catch (...)
  {
	return 0;
  }
}

/*************************************************/
void main ()
{
	LinkList <int>   l1;
	LinkList <char>  l2;
	LinkList <float> l3;

	l1.addItem(1); l1.addItem(2);
	l1.addItem(3); l1.addItem(4);
	l1.addItem(5); l1.addItem(6);

	l1.delItem (4);
}
