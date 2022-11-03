#include <iostream.h>

template <class T, const int MAX_ITEMS=100>
class SortedList
{
public:
		 SortedList();
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
/*************************************************/
template <class T, const int MAX_ITEMS>
	SortedList<T, MAX_ITEMS>::SortedList()
		{ length = 0;ResetList(); }

template <class T, const int MAX_ITEMS>
  int SortedList<T, MAX_ITEMS>::IsFull() const
		{ return (length == MAX_ITEMS); }

template <class T, const int MAX_ITEMS>
  int SortedList<T, MAX_ITEMS>::LengthIs()const
		{ return length; }

template <class T, const int MAX_ITEMS>
 void SortedList<T, MAX_ITEMS>::ResetList()
		{ currentPos = -1; }

template <class T, const int MAX_ITEMS>
 T SortedList<T, MAX_ITEMS>::GetNextItem()
		{ return info[++currentPos]; }

template <class T, const int MAX_ITEMS>
 void SortedList<T, MAX_ITEMS>::RetrieveItem(T& item, int& found)
		{
		found = 0;// false
		for (int location = 0;location < length;location++)
			if (item == info[location])
				found = 1;//true
		}

template <class T, const int MAX_ITEMS>
 void SortedList<T, MAX_ITEMS>::printList () const
		{
		for (int location = 0;location < length;location++)
			cout << info[location]  << " " ;
		cout << endl;
		}

template <class T, const int MAX_ITEMS>
 void SortedList<T, MAX_ITEMS>::InsertItem(T item)
		{
		if(IsFull())
			return;
		for (int i=0; i<length; i++)
			if (info[i]>item)
			{
			  for (int j=length;j>i;j--)
				  info[j]=info[j-1];
			  break;
			}
		info[i]=item;
		length++;
		}

template <class T, const int MAX_ITEMS>
 void SortedList<T, MAX_ITEMS>::DeleteItem(T item)
		{
		int location;
		for (location = 0; item != info[location];location++);
		for (int i=location; i<length; i++)
			info[i]=info[i+1];
			--length;
		}  
/*************************************************/

void main ()
{
	SortedList <int,10>L1;
	L1.InsertItem(10);
	L1.InsertItem(70);
	L1.InsertItem(30);
	L1.InsertItem(90);
	L1.InsertItem(50);
	L1.DeleteItem(30);

	L1.printList();
	cout << L1.GetNextItem() << " ";
	cout << L1.GetNextItem() << " ";
	cout << L1.GetNextItem() << " ";
	cout << L1.GetNextItem() << "\n";

	SortedList <char>L2;
	L2.InsertItem('a');
	L2.InsertItem('c');
	L2.InsertItem('e');
	L2.InsertItem('d');
	L2.InsertItem('b');
	L2.printList();
}