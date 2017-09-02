/* Know more about Queues */
/* https://www.tutorialspoint.com/data_structures_algorithms/dsa_queue.htm */

#include<stdio.h>
#include<stdlib.h>
int r = - 1;
int f = - 1;
void ins(int q[20]);
void del(int q[20]);
void traverse(int q[20]);

void ins(int q[20])
{
    int val;
    if (r==19)
        printf("Overflow detected\n");
    else
    {
        if (f==- 1)
            f=0;
        printf("Enter the value of an element : ");
        scanf("%d",&val);
        r=r++;
        q[r] = val;
    }
}

void del(int q[20])
{
    if ( f==- 1 || f==19 )
        printf("Underflow detected\n");
    else
    {
        printf("Element to be deleted : %d",q[f]);
        f++;
    }
}

void traverse(int q[20])
{
    int i;
    if (f==- 1)
        printf("Underflow detected\n");
    else
    {
        printf("The Queue is : \n");
        for ( i = f; i<=r; i++)
            printf("%d ", q[i]);
    }
}

int main()
{
    int choice, q[20];
    do
    {
        printf("\nOperation :\n1.Insert an element into the Queue\n2.Delete an element from the Queue\n3.Traverse the Queue\n4.Exit\n");
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
