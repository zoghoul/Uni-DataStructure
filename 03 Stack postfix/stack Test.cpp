#include <iostream.h>
#include "stack.h"

void main ()
{
	Stack <int,4>L1;
	L1.push(10);
	L1.push(20);
	L1.push(30);
	L1.push(40);
	cout << L1.pop() << " ";
	cout << L1.pop() << " ";
	cout << L1.pop() << " ";
	cout << L1.pop() << "\n";

	Stack <char>L2;
	L2.push('a');
	L2.push('b');
	L2.push('c');
	L2.push('d');
	L2.push('e');
	cout << L2.pop() << " ";
	cout << L2.pop() << " ";
	cout << L2.pop() << " ";
	cout << L2.pop() << "\n";
}