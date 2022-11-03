#include<iostream.h>
#include<conio.h>

class Stack
{
private:
	  char s[100];
	  int depth;
public:
			 Stack() { depth=0; }
	  void push (char x)
	  {
		 s[depth++]=x;
	  }
	  char pop()
	  {
		 if(depth<0)
			 depth=0;
		 if(depth>=1)
			 return s[--depth];
		 else
			 return 0;
	  }
	  int IsEmpty() const { return (depth==0); }
	  char head()
	  {
		 if(depth>0)
			return s[depth-1];
		 else
			return 0;
		}
};

void main()
{
  Stack stack;
  char *infix;
  char expression[50];
l1:
  cin>>expression;
  infix=expression;

  while(*infix!=0)
  {
	 switch(*infix)
	 {
		 case '(':
			  stack.push('(');
			  break;
		 case '+':
			  if(stack.head() != 0 )
				 while(!stack.IsEmpty() && stack.head() != '(')
						cout<<stack.pop();
			  stack.push('+');
			  break;
		 case '-':
			  if(stack.head() != 0 )
				 while(!stack.IsEmpty() && stack.head() != '(')
						cout<<stack.pop();
			  stack.push('-');
			  break;
		 case '*':
			  if(stack.head()=='*'||stack.head()=='/')
				 while(!stack.IsEmpty() && stack.head() != '(')
						cout<<stack.pop();
			  stack.push('*');
			  break;
		 case '/':
			  if(stack.head()=='*'||stack.head()=='/')
				 while(!stack.IsEmpty() && stack.head() != '(')
						cout<<stack.pop();
			  stack.push('/');
			  break;
		 case ')':
			  while(stack.head() != '(')
						cout<<stack.pop();
			  stack.pop();
			  break;
		 default:
			  cout<<(*infix);
	 }  // end of switch
	 *(infix++);
  }    // end of while

  while(!stack.IsEmpty())
		 cout<<stack.pop();

  getch();
goto l1;
  return;
}