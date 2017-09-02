/* Know more about Stacks */
/* http://www.geeksforgeeks.org/stack-data-structure-introduction-program/ */

#include <stdio.h>
#include <stdlib.h>
void push();
void pop();
void traverse();
void rev();
void rec_rev(struct stacks*top, struct stacks*top_next);

struct stacks
{
    int val;
    struct stacks*next;
} *ptr, *x, *top, *p, *b, *a;

void push()
{
    x=(struct stacks *)malloc(sizeof(struct stacks));
    printf("Enter the element : ");
    scanf("%d",&x->val);
    x->next=top;
    top=x;
}

void pop()
{
    printf("The element to be deleted : %d",x->val);
    top=top->next;
    free(x);
}

void traverse()
{
    p=top;
    while( p!=NULL)
    {
        printf("%d ",p->val);
        p=p->next;
    }
}

void rev()
{
    b=top;
    ptr=top;
    a=top->next;
    top->next=NULL;
    while (a!=NULL)
    {
        ptr=a;
        a=a->next;
        ptr->next=b;
        b=ptr;
    }
    top=ptr;
    printf("The stack after reversal : \n");
    traverse();
}

void rec_rev(struct stacks*top, struct stacks*top_next)
{
    if ( top_next!=NULL)
    {
        ptr=top_next->next;
        top_next->next=top;
        top=top_next;
        top->next=ptr;
        rec_rev(top, top_next);
    }
}

int main()
{
    struct stacks*top=NULL;
    int choice;
    do
    {
        printf("\nOperation : \n1.Push an element onto the Stack\n2.Pop an element from the Stack\n3.Traverse the Stack\n4.Reverse the Stack ( Iterative )\n5.Reverse the Stack ( Recursive )\n6.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : { push(); break;}
            case 2 : { pop(); break; }
            case 3 : { traverse(); break; }
            case 4 : { rev(); break; }
            case 5 : { rec_rev(top, top->next); break; }
        }
    }
    while ( choice!=6);
    return 0;
}
