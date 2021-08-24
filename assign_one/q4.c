#include <stdio.h>

int main()
{
    int n=20;
    int k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
     for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                int k = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = k;
            }
        }
    }
    
    printf("Sorted array:\n");
    for(int l = 0;l<n;l++)
    {
        printf("%d\n",arr[l]);
    }
    return 0;
}
