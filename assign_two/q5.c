#include <stdio.h>

#define N 5

int queue[N];
int ft = -1; //queue
int bk = -1;

void add_to_queue(int data)
{
    if(bk == N-1)
    {
        fprintf(stderr,"Queue is full, cannot add\n");
    }
    else
    {
        bk++;   //increment and then store
        queue[bk] = data;
    }
}

int remove_from_queue()
{
    int temp=0;
    if(ft == bk)
    {
        fprintf(stderr,"Queue is empty, cannot remove\n");
        return -1;
    }
    else
    {
        ft++;
        temp = queue[ft];
        if(ft == bk)
        {
            ft = -1;
            bk = -1;
        }
    }
    return temp;
}

void Print()
{
    if(ft == bk)
    {
        fprintf(stderr,"Queue is empty, nothing to print.\n");
    }
    else
    {
        printf("Elements of queue are:\n");
        for(int i=ft+1;i<bk+1;i++)
        {
            printf("%d\n",queue[i]);
        }
    }
}

int main()
{
    remove_from_queue();//error
    add_to_queue(1);
    add_to_queue(2);
    add_to_queue(3);
    add_to_queue(4);
    add_to_queue(5);
    add_to_queue(6);//error
    printf("removing element:%d\n",remove_from_queue());
    printf("removing element:%d\n",remove_from_queue());
    Print();

    return 0;
}