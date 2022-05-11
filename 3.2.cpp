#include <iostream>
#include "conio.h"

using namespace std;

typedef char elementtype;

int maxlength = 100;

typedef struct A{
	elementtype *elements;
	
	int front, rear;
} celltype;

typedef celltype QUEUE;


QUEUE MAKENULL(QUEUE Q)
{
	Q.elements = new elementtype[maxlength];
	
	Q.front = 1;
	Q.rear = maxlength;
	
	return Q;
}

int addone(int i)
{
	cout << "i: \t" << i << endl;
	return (i % maxlength) + 1;
}

bool EMPTY(QUEUE Q) {
    if (addone(Q.rear) == Q.front)
    	return true;
    else 
		return false;
}

elementtype FRONT(QUEUE Q)
{
    if(EMPTY(Q))
	{
		cout << "Stack is empty" << endl;
		
		return 0;
	}
	else 
	{
		cout << "tempone" << endl;
		cout << Q.elements[Q.rear + 2] << endl;
		cout << Q.elements[Q.front + 2] << endl;
		return Q.elements[Q.front];
	}

}

int ENQUEUE(elementtype x, QUEUE Q)
{	
    if (addone(Q.rear) == Q.front)
	{
		cout << "Stack overflow" << endl;
		return 1;
	}
	
    else
    {	
        Q.rear = addone(Q.rear);

        Q.elements[Q.rear] = x;
        
        return 0;
	}
	cout << "tempthree" << endl;
}

void DEQUEUE (QUEUE Q)
{
    if(EMPTY(Q))
		cout << "Stack is empty" << endl;

    else
    {
    	cout << "temp" << endl;
    	cout << Q.elements[Q.front + 3] << endl;
		Q.front = addone(Q.front);
		cout << Q.elements[Q.front] << endl;
	}
}


void PRINT(QUEUE Q)
{
	while(!EMPTY(Q))
	{
		cout << FRONT(Q);
		
		DEQUEUE(Q);
	}
	
	cout << endl;
}



int main()
{
			QUEUE Q;
		
		    char c;
		
		    MAKENULL(Q);                        
			
			c = getche();  
		
		            while (c != '='){
		            	cout << "while" << endl;
		            	
		                ENQUEUE(c, Q);
		                
		                c = getche();
					}
		

		
		DEQUEUE (Q);
		
		DEQUEUE (Q);
		
		ENQUEUE ('s', Q);		 
/*
		while (!EMPTY(Q)){
		    cout << FRONT(Q);
		
		    DEQUEUE (Q);
		
		}
*/		
		cout << endl;
	return 0;
}