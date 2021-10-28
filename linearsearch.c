#include<stdio.h>
/*
int linearsearch(int arr[],int size, int element)
{
	int i;
   for( i=0; i<size ; i++)
    {
       if(arr[i]==element)
      {
        return i;
      }  
    }
    return -1;
} */
    int binarysearch(int arr[],int size, int element)
    {
        int mid;
        int high = size-1;
        int low = 0;
        while (low<=high)
        {
            mid = (high+low)/2;
            if(arr[mid] == element)
            {
                return mid;
            }
            if(arr[mid]<element)
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return -1;
        
        
    }   
 

int main()
{
   int arr[] = {11,22,33,44,55,66,77,88,99,100,101,202};
   int size = sizeof(arr)/sizeof(int);
   int element = 100;
  // int search = linearsearch(arr, size, element);
   int search = binarysearch(arr, size, element);   
  printf("The element %d was found at index %d",element,search);

    return 0;
}
