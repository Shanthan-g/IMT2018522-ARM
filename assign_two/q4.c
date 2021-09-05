#include <stdio.h>

#define N 5

int stack[N];
int pt = 0; //Ascending empty stack

void Push(int data)
{
    if(pt > N-1)
    {
        fprintf(stderr,"Stack is full, cannot push\n");
    }
    else
    {
        stack[pt] = data;
        pt++;   //store data and increment pt, since empty stack
    }
}

int Pop()
{
    if(pt == 0)
    {
        fprintf(stderr,"Stack is empty, cannot pop\n");
        return -1;
    }
    else
    {
        pt--;
        return stack[pt];
    }
}

void Print()
{
    if(pt == 0)
    {
        fprintf(stderr,"Stack is empty, nothing to print.\n");
    }
    else
    {
        printf("Elements of stack are:\n");
        for(int i=pt-1;i>-1;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}

int main()
{
    Pop();//error
    Push(1);
    Push(2);
    Push(3);
    Push(4);
    Push(5);
    Push(6);//error
    printf("Popping element:%d\n",Pop());
    printf("Popping element:%d\n",Pop());
    printf("Popping element:%d\n",Pop());
    Push(7);
    Push(8);
    Push(9);
    Print();

    return 0;
}