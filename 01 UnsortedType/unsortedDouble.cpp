#include <iostream.h>

template <class T, const int MAX_ITEMS>
class UnsortedList
{
public:
	    UnsortedList();
	int IsFull()   const;
	int LengthIs() const;
  void RetrieveItem(T& item, int& found);
  void InsertItem(T item);
  void DeleteItem(T item);
  void ResetList();
  void printList() const;
	  T GetNextItem();

private:
  int length;
  T info[MAX_ITEMS];
  int currentPos;
};


template <class T, const int MAX_ITEMS>
	UnsortedList<T, MAX_ITEMS>::UnsortedList()
		{ length = 0;ResetList(); }

template <class T, const int MAX_ITEMS>
  int UnsortedList<T, MAX_ITEMS>::IsFull() const
		{ return (length == MAX_ITEMS); }

template <class T, const int MAX_ITEMS>
  int UnsortedList<T, MAX_ITEMS>::LengthIs()const
		{ return length; }

template <class T, const int MAX_ITEMS>
 void UnsortedList<T, MAX_ITEMS>::InsertItem(T item)
		{ if(!IsFull())info[length++]=item; }

template <class T, const int MAX_ITEMS>
 void UnsortedList<T, MAX_ITEMS>::ResetList()
		{ currentPos = -1; }

template <class T, const int MAX_ITEMS>
 T UnsortedList<T, MAX_ITEMS>::GetNextItem()
		{ return info[++currentPos]; }

template <class T, const int MAX_ITEMS>
 void UnsortedList<T, MAX_ITEMS>::RetrieveItem(T& item, int& found)
		{
		found = 0;// false
		for (int location = 0;location < length;location++)
			if (item == info[location])
				found = 1;//true
		}
template <class T, const int MAX_ITEMS>
 void UnsortedList<T, MAX_ITEMS>::DeleteItem(T item)
		{
		for (int location = 0; item != info[location];location++);
		info[location] = info[--length];
		}
template <class T, const int MAX_ITEMS>
 void UnsortedList<T, MAX_ITEMS>::printList () const
		{
		for (int location = 0;location < length;location++)
			cout << info[location]  << " " ;
		cout << endl;
		}


void main ()
{
	UnsortedList <int,10>L1;
	L1.InsertItem(10);
	L1.InsertItem(70);
	L1.InsertItem(30);
	L1.InsertItem(90);
	L1.InsertItem(50);

	L1.printList();
	cout << L1.GetNextItem() << " ";
	cout << L1.GetNextItem() << " ";
	cout << L1.GetNextItem() << " ";
	cout << L1.GetNextItem() << " ";
	cout << L1.GetNextItem() << "\n" ;

	UnsortedList <char,5>L2;
	L2.InsertItem('a');
	L2.InsertItem('b');
	L2.InsertItem('c');
	L2.InsertItem('d');
	L2.InsertItem('e');
	L2.printList();
}