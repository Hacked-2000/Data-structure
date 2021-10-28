#include<stdio.h>

int main()
{
    int num,element,i,search;
    int arr[10] = { 11,22,33,44,55,66,77,88,99,100};
   // printf("\nEnter the elements : ");
   // scanf("%d",arr);
    printf("\nWhich element want to search : ");
    scanf("%d",&element);

    for ( i = 0; i < 10; i++)
    {
        if(arr[i]==element)
        {
            search = i+1;
            break ;
        }
        else
    
            search = 0;
        
    }

    if(search != 0)
        {
            printf("%d is found at &d",element,search);
        }
    else
    {
    printf("Not in Data");
    }
}