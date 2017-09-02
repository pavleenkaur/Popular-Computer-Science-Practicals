/* Get to know about Linked Lists */
/* https://www.tutorialspoint.com/data_structures_algorithms/linked_list_algorithms.htm */ 

#include<stdio.h>
#include<stdlib.h>
void create();
void traverse();
void ins_beg();
void ins_end();
void ins_any(int pos);
void del_beg();
void del_end();
void del_any(int pos);
void reverse();
void del_alt();
void split();

struct stud
{
    int age;
    struct stud*next;
} *f,*l,*x,*p,*a,*b,*m,*n,*node;

int main()
{
    int ch, pos, n;
    do
    {
    printf("\nOperation :\n");
    printf("\n1.Create the List\n2.Traverse the List\n3.Insert an element\n4.Delete an element\n5.Reverse the List\n6.Delete alternate nodes from the List\n7.Split the List\n8.Exit\n");
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
            printf("\n1.Insert in the beginning\n2.Insert at the end\n3.Insert anywhere");
            scanf("%d",&n);
            switch(n)
            {
                case 1 : { ins_beg(); break;}
                case 2 : { ins_end(); break;}
                case 3 : { printf("Enter the position : ");
                scanf("%d",&pos);
                ins_any(pos);
                break;
                }
            }
            break;
        }
        case 4 : {
            printf("\n1.Delete from the beginning\n2.Delete from the end\n3.Delete from anywhere");
            scanf("%d",&n);
            switch(n)
            {
                case 1 : { del_beg(); break;}
                case 2 : { del_end(); break;}
                case 3 : { printf("Enter the position : ");
                scanf("%d",&pos);
                del_any(pos);
                break;
                }
            }
            break;
        }
        case 5 : {
            reverse();
            break;
        }
        case 6 : {
            del_alt();
            break;
        }
        case 7 : {
            split();
            break;
        }
    }
    }
    while(ch!=8);
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
}

void traverse()
{
    l=f;
    printf("\nAge : ");
    while ( l!=NULL )
    {
        printf("%d ",l->age);
        l=l->next;
    }
}

void ins_beg()
{
    node=(struct stud *)malloc(sizeof(struct stud));
    printf("Enter the Age : ");
    scanf("%d",&node->age);
    node->next=NULL;
    node->next=f;
    f=node;
    printf("Linked List after insertion : \n");
    traverse();
}

void ins_end()
{
    node=(struct stud *)malloc(sizeof(struct stud));
    printf("Enter the Age : ");
    scanf("%d",&node->age);
    node->next=NULL;
    l=f;
    while ( l->next!=NULL)
    {
        l=l->next;
    }
    l->next=node;
    l=node;
    printf("Linked List after insertion : \n");
    traverse();
}

void ins_any(int pos)
{
    node=(struct stud *)malloc(sizeof(struct stud));
    printf("Enter the Age : ");
    scanf("%d",&node->age);
    node->next=NULL;
    int i=2;
    l=f;
    while ( i!=pos)
    {
        l=l->next;
        i++;
    }
    node->next=l->next;
    l->next=node;
    printf("Linked List after insertion : \n");
    traverse();
}

void del_beg()
{
    struct stud*ptr;
    ptr=f;
    f=f->next;
    free(ptr);
    printf("Linked List after deletion : \n");
    traverse();
}

void del_end()
{
    struct stud*ptr1;
    l=f;
    while ( l->next->next!=NULL)
    {
        l=l->next;
    }
    ptr1=l->next;
    free(ptr1);
    l->next=NULL;
    printf("Linked List after deletion : \n");
    traverse();
}

void del_any(int pos)
{
    struct stud *ptr2;
    int i=2;
    l=f;
    while ( i!=pos)
    {
        l=l->next;
        i++;
    }
    ptr2=l->next;
    l->next=l->next->next;
    free(ptr2);
    printf("Linked List after deletion : \n");
    traverse();
}

void reverse()
{
    p=f;
    b=f;
    a=f->next;
    f->next=NULL;
    while ( a!=NULL )
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

void del_alt()
{
    struct stud *x;
    x=f;
    while ( x!=NULL && x->next!=NULL)
    {
        struct stud *ptr;
        ptr=x->next;
        x->next=ptr->next;
        free(ptr);
        x=x->next;
    }
    traverse();
}

void split()
{
    l=f;
    p=l->next;
    while ( p!=NULL && p->next!=NULL )
    {
        l=l->next;
        p=p->next->next;
    }
    m=l->next;
    l->next=NULL;
    l=f;
    printf("The first half is : \n");
    while (l!=NULL)
    {
        printf("Age : %d\n",l->age);
        l=l->next;
    }
    printf("The second half id : \n");
    n=m;
    while ( n!=NULL)
    {
        printf("Age : %d\n",n->age);
        n=n->next;
    }
}
