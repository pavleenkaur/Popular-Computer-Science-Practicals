/* Explanation of Bubble Sort */
/* https://www.tutorialspoint.com/data_structures_algorithms/bubble_sort_algorithm.htm */

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[50], n, i, j, temp;

    printf("Enter the limit of the unsorted array : ");
    scanf("%d",&n);
    printf("Enter the elements of the array : ");
    for ( i=0; i<n; i++ )
        scanf("%d",&a[i]);

    for ( i=0; i<n; i++)
    {
        for ( j=0; j<n-1; j++)
        {
            if ( a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }

    }

    printf("The sorted array is : \n");
    for ( i=0; i<n; i++)
        printf("%d ",a[i]);
    return 0;
}
