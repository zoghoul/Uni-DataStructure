template <class T>
class Stack
{
public:
		Stack(int = 100);
  int isFull()   const { return (length == max); }
  int isEmpty()  const { return (length == 0  ); }
  int lengthIs() const { return  length; }
  int push(T item);
  int pop ();
  int top () const;
private:
  int length,max;
	T* info;
};
/*************************************************/
template <class T>
	Stack<T>::Stack(int size)
	 {
		max=size;
		info =new T [size];
		length = 0;
	 }

template <class T>
 void Stack<T>::push(T item)
	 {
		if(isFull())
		  return 0;
		info[length++]=item;
		return 1;
	 }

template <class T>
 int Stack<T>::pop()
	 {
		if(isEmpty())
			return 0;
		--length;
		return 1;
	 }

template <class T>
 T Stack<T>::top()
	 {
		if(isEmpty())
			return 0;
		return info[length-1];
	 }

/*
template <class T>
  int Stack<T>::isFull() const
		{ return (length == max); }

template <class T>
  int Stack<T>::isEmpty() const
		{ return (length == 0); }

template <class T>
  int Stack<T>::lengthIs()const
		{ return length; }
*/
