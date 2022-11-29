#include <iostream>
using namespace std;
#define SIZE 50000            
char stack[SIZE];
int top=-1;       /* Global declarations */
int kq[10000];
int top_int=-1;
int char2int(char x) {
	if  (((int) x - 48) >= 0)
	return ((int) x - 48);
}


void push_int(int elem)
{                       /* Function for PUSH operation */
    kq[++top_int]=elem;
}		
 

void push(char elem)
{                       /* Function for PUSH operation */
    stack[++top]=elem;
}
 

int pop_int()
{                      /* Function for POP operation */
    return(kq[top_int--]);
}

char pop()
{                      /* Function for POP operation */
    return(stack[top--]);
}
 
int pr(char symbol)
{                 /* Function for precedence */
    
	if(symbol == '^')/* exponent operator, highest precedence*/
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')          /* lowest precedence */
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

int main()
{   
    freopen("input.txt","r",stdin);
	for (int tc=1;tc<=10;tc++) {
		int val=0;
		int dem1=0;
		int dem2=0;
		top=-1;	
		top_int=-1;
		char infix[50000],postfix[50000],ch,elem;
		int i=0,k=0;
		char c=0;
		int n;
		cin>>n;
		int x=0;
		for (x=0;x< n;) {
			cin>>c;
			infix[x++]=c;
		}
		infix[x]=0;

		push('#');
		while( (ch=infix[i++]) != '\0')
		{
			if( ch == '(' ) push(ch);
			else
				if(isalnum(ch)) postfix[k++]=ch;
				else
					if( ch == ')')
					{
						while( stack[top] != '(')
							postfix[k++]=pop();
						elem=pop(); /* Remove ( */
					}
					else
					{       /* Operator */
						while( pr(stack[top]) >= pr(ch) )
							postfix[k++]=pop();

						push(ch);
					}
		}
		
		while( stack[top] != '#')     /* Pop from stack till empty */
			postfix[k++]=pop();
		postfix[k]='\0';          /* Make postfix as valid string */
		
		for (int i=0;i<k;i++) {
			if (isalnum(postfix[i])) {push_int( char2int (postfix[i])); } 
			else {
				if (postfix[i]=='*') {
					int temp= pop_int()*pop_int();
					push_int(temp);
				}	
				else { if (postfix[i]=='+') {
					int temp=pop_int()+pop_int();
					push_int(temp);
					}
				}
			}
			
		}
		cout<<"#"<<tc<<" "<<kq[0]<<endl;
	}
	return 0;
}