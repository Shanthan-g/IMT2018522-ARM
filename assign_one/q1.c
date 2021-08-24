

#include <stdio.h>

int main()
{
    int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    
    
    if(a>b && a>c)
    {
        printf("Largest of three: %d",a);    
    }
    
    else if(b>a && b>c)
    {
        printf("Largest of three: %d",b);    
    }
    
    else
    {
        printf("Largest of three: %d",c);    
    }
    return 0;
}