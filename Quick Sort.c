/* Explanation of Quick Sort */
/* https://www.tutorialspoint.com/data_structures_algorithms/quick_sort_algorithm.htm */

#include<stdio.h>
#include<conio.h>
void quicksort(int arr[20], int fst, int last);

int main()
{
 int arr[30], i, size;

 printf("Enter the limit of the elements : ");
 scanf("%d",&size);
 printf("Enter the elements : ");
 for(i=0; i<size; i++)
    scanf("%d",&arr[i]);

 quicksort(arr,0,size-1);

 printf("Sorted elements are : \n");
 for(i=0; i<size; i++)
    printf("%d ",arr[i]);

 getch();
 return 0;
}

void quicksort(int arr[20], int fst, int last)
{
 int i,j,pivot,tmp;
 if(fst<last)
 {
   pivot=fst;
   i=fst;
   j=last;
   while(i<j)
   {
     while(arr[i]<=arr[pivot] && i<last)
        i++;
     while(arr[j]>arr[pivot])
        j--;
     if(i<j)
     {
        tmp=arr[i];
        arr[i]=arr[j];
        arr[j]=tmp;
     }
   }
   tmp=arr[pivot];
   arr[pivot]=arr[j];
   arr[j]=tmp;
   quicksort(arr,fst,j-1);
   quicksort(arr,j+1,last);
 }
}
