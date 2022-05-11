#include <iostream>
#include <conio.h>
 
using namespace std;

typedef char elementtype;

int maxlength = 100;

typedef struct A{
	int top;
		
    elementtype *elements;
} celltype;

typedef celltype* STACK;


STACK MAKENULL (STACK S) {
	S->elements = new elementtype[maxlength];
	
	S->top = maxlength + 1;	

	return S;
}

bool EMPTY (STACK S) {
    if (S->top + 1 > maxlength)
    	return true;
    else 
		return false;
}

elementtype TOP (STACK S)
{
    if(EMPTY(S))
	{
		cout << "Stack is empty" << endl;
		
		return 0;
	}
	else 
	{
		return S->elements[S->top + 1];
	}

}

void POP (STACK S)
{
    if(EMPTY(S))
		cout << "Stack is empty" << endl;
    else 
    {
		S->top = S->top + 1;
	}
}

void PUSH (elementtype x, STACK S)
{
    if (S->top == 1)
		cout << "Stack overflow" << endl;
		
    else
    {
        S->top = S->top - 1;

        S->elements[S->top] = x;
	}
}

void PRINT(STACK S)
{
	while(!EMPTY(S))
	{
		cout << TOP(S);
		
		POP(S);
	}
	
	cout << endl;
}




int main()
{

 
STACK S;

            char c;

        

            MAKENULL(S);                            

            c = getchar();

            while (c != '=') {

                  switch (c) {

                                   // витерти останній символ              

                        case '#': POP(S); break;

                                   // витерти усю стрічку

                        case '@': MAKENULL(S); break;

                                   // продублювати останній символ

                        case '^': PUSH(TOP(S), S); break;

                                   // додати символ до стрічки

                        default :

                                  PUSH(c, S);
					}
					
                  c = getchar();

				}

// вивести введену стрічку на екран

 PRINT(S);
	return 0;
};