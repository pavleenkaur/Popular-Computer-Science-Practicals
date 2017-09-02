/* Know more about Queues */
/* https://www.tutorialspoint.com/data_structures_algorithms/dsa_queue.htm */

#include <stdio.h>
#include <stdlib.h>
void ins();
void del();
void traverse();

struct queue
{
    int val;
    struct queue*next;
} *r ,*f, *x, *p;

void ins()
{
    x=(struct queue *)malloc(sizeof(struct queue));
    printf("Enter the value of an element : ");
    scanf("%d",&x->val);
    x->next=NULL;
    if ( f==NULL)
    {
        f=x;
        r=x;
    }
    else
    {
        r->next=x;
        r=x;
    }
}

void del()
{
    if(f==r)
        printf("Underflow detected\n");
    else
    {
        printf("The element to be deleted : %d",f->val);
        f=f->next;
    }
}

void traverse()
{
    p=f;
    while( p!=NULL)
    {
        printf("%d ",p->val);
        p=p->next;
    }
}

int main()
{
    f=NULL;
    r=NULL;
    int choice;
    do
    {
        printf("\nOperation : \n1.Insert an element into the Queue\n2.Delete an element from the Queue\n3.Traverse the Queue\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : { ins(); break;}
            case 2 : { del(); break; }
            case 3 : { traverse(); break; }
        }
    }
    while ( choice!=4);
    return 0;
}
