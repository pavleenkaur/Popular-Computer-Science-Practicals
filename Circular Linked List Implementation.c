/* Know more about Circular Lists */
/* http://www.geeksforgeeks.org/circular-linked-list/ */

#include<stdio.h>
#include<stdlib.h>
void create();
void traverse();
void reverse();

struct stud
{
    int age;
    struct stud*next;
} *f,*l,*x, *p, *b, *a;

int main()
{
    int ch;
    do
    {
    printf("\nOperation :");
    printf("\n1.Create a Circular List\n2.Traverse the List\n3.Reverse the List\n4.Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1 : {
            create();
            break;
        }
        case 2 : {
            traverse();
            break;
        }
        case 3 : {
            reverse();
            break;
        }
    }
    }
    while(ch!=4);
    return 0;
}

void create()
{
    f=(struct stud *)malloc(sizeof(struct stud));
    int n,i;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("Enter the Age : ");
    scanf("%d",&f->age);
    f->next=NULL;
    l=f;
    for ( i=1; i<n; i++)
    {
        x=(struct stud *)malloc(sizeof(struct stud));
        printf("Enter the Age : ");
        scanf("%d",&x->age);
        x->next=NULL;
        l->next=x;
        l=x;
    }
    l->next=f;
}

void traverse()
{
    l=f;
    printf("\nAge : ");
    while ( l->next!=f )
    {
        printf("%d ",l->age);
        l=l->next;
    }
    printf("%d",l->age);
}

void reverse()
{
    p=f;
    b=f;
    a=f->next;
    f->next=l;
    while ( a!=f )
    {
        p=a;
        a=a->next;
        p->next=b;
        b=p;
    }
    f=p;
    printf("\nList after reversal : \n");
    traverse();
}

