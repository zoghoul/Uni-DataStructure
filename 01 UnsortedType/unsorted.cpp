#include <"unsorted.h">
	  UnsortedType::UnsortedType					  {length = 0;}
 int UnsortedType::IsFull()   const				  {return (length == MAX_ITEMS);}
 int UnsortedType::LengthIs() const				  {return length;}
void UnsortedType::InsertItem(ItemType item)   {info[length++] = item;}
void UnsortedType::ResetList() 					  {currentPos = –1;}
void UnsortedType::GetNextItem(ItemType& item) {item = info[++currentPos];}

void UnsortedType::RetrieveItem(ItemType& item, bool& found)
{
	int moreToSearch;
	int location = 0;
	found = 0;// false
	moreToSearch = (location < length);
	while (moreToSearch && !found)
	{
		switch (item.ComparedTo(info[location]))
		{
			case LESS :
			case GREATER :
				location++;
				moreToSearch = (location < length);
				break;
			case EQUAL :
				found = true;
				item = info[location];
				break;
		}
	}
}

void UnsortedType::DeleteItem(ItemType item)
{
	int location = 0;
	while (item.ComparedTo(info[location]) != EQUAL)
		location++;
	info[location] = info[--length];
}
