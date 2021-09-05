#include <stdio.h>

#define N 5

int cqueue[N];
int ft = -1; // circular queue
int bk = -1;

void add_to_queue(int data)
{
    if(bk == N-1 && ft == 0 || ft == bk+1)  // 1st condition is when the queue is linearly filled. 2nd is when circularly filled.
    {
        fprintf(stderr,"CQueue is full, cannot add\n");
    }
    else
    {
        if(bk == N-1 && ft != 0)        // linearly filled, time to push from behind
        {
            bk = -1;
        }
        bk++;
        cqueue[bk] = data;
        
        if(ft == -1)                    // to make the first pop
        {
            ft = 0;
        }
    }
}

int remove_from_queue()
{
    int temp=0;
    if(ft == -1 && bk == -1)
    {
        fprintf(stderr,"CQueue is empty, cannot remove\n");
        return -1;
    }
    else
    {
        temp = cqueue[ft];
        ft++;
        if(ft-1 == bk)  // reset the queue.
        {
            ft = -1;
            bk = -1;
        }
        if(ft == N)     //circularly filled so go back and start popping. 
        {
            ft == 0;
        }
        
    }
    return temp;
}

void Print()
{
    if(ft == -1 && bk == -1)
    {
        fprintf(stderr,"CQueue is empty, nothing to print.\n");
    }
    else
    {
        printf("Elements of Cqueue are:\n");
        if(ft<=bk)      // linear printing from front to back.
        {
            for(int i=ft;i<bk+1;i++)
            {
                printf("%d\n",cqueue[i]);
            }
        }
        else            // print from front to N-1 then again start printing from the back.(circular printing)
        {
            for(int j=ft;j<N;j++)
            {
                printf("%d\n",cqueue[j]);
            }
            
            for(int k=0;k<bk+1;k++)
            {
                printf("%d\n",cqueue[k]);
            }
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
    add_to_queue(7);
    add_to_queue(8);
    Print();

    return 0;
}