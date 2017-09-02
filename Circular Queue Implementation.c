/* Know more about Circular Queues */
/* http://www.geeksforgeeks.org/circular-queue-set-1-introduction-array-implementation/ */

#include <stdio.h>
#include <stdlib.h>
void ins(int q[5]);
void del(int q[5]);
void traverse(int q[5]);
int r=-1;
int f=-1;

void ins(int q[5])
{
    if(r==-1)
        f++; r++;
    else if ((f==r+1) || (f==0 && r==4))
        printf("Overflow.\n");
    else if ( r==4 && f!=0)
        r=0;
    else
        r++;
    printf("Enter the value of an element : ");
    scanf("%d",&q[r]);
}

void del(int q[5])
{
   printf("The element to be deleted is : %d",q[f]);
   if ( f==-1)
    printf("Underflow.\n");
   else if ( f==4)
    f=0;
   else if ( f==r )
   {
       f=-1;
       r=-1;
   }
   else
    f++;
}

void traverse(int q[5])
{
    int i;
    if(f<r)
        for ( i=f; i<=r; i++)
            printf("%d ",q[i]);
    else
    {
        for ( i=f; i<4; i++)
            printf("%d ",q[i]);
        for ( i=0; i<=r; i++)
            printf("%d ",q[i]);
    }
}

int main()
{
    int choice, q[5];
    do
    {
        printf("\nOperations : \n1.Insert an element into the Queue\n2.Delete an element from the Queue\n3.Traverse the Queue\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : { ins(q); break; }
            case 2 : { del(q); break; }
            case 3 : { traverse(q); break; }
        }
    }
    while ( choice!=4);
    return 0;
}
