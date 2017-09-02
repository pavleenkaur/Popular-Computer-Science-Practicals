/* Get to know about Linked Lists */
/* https://www.tutorialspoint.com/data_structures_algorithms/linked_list_algorithms.htm */ 

#include<iostream>
void create_list();
void display_list();
void middle_element();
void reverse_list();
void palindrome();
void split();
using namespace std;
struct stud
{
    int age;
    char name[20];
    stud*next;
} *first,*last,*x,*ptr,*ahead,*backward,*m,*n;

int main()
{
    int choice;
    do
    {
    cout<<"\nOperation :"<<endl;
    cout<<"\n1.Create a List\n2.Display the List\n3.Find the Middle element of the List\n4.Reverse the List\n5.Check for palindrome\n6.Split in List in two\n7.Exit"<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1 : {
            create_list();
            break;
        }
        case 2 : {
            display_list();
            break;
        }
        case 3 : {
            middle_element();
            break;
        }
        case 4 : {
            reverse_list();
            break;
        }
        case 5 : {
            palindrome();
            break;
        }
        case 6 : {
            split();
            break;
        }
    }
    }

    while(choice!=7);
    return 0;
}
void create_list()
{
    first=new stud;
    int n,i;
    cout<<"\nEnter the number of elements : ";
    cin>>n;
    cout<<"\nEnter the Name : ";
    cin>>first->name;
    cout<<"Enter the Age : ";
    cin>>first->age;

    first->next=NULL;
    last=first;

    for ( i=1; i<n; i++)
    {
        x=new stud;
        cout<<"\nEnter the Name : ";
        cin>>x->name;
        cout<<"Enter the Age : ";
        cin>>x->age;
        x->next=NULL;
        last->next=x;
        last=x;
    }
}

void display_list()
{
    last=first;
    while ( last!=NULL )
    {
        cout<<"\nName : "<<last->name;
        cout<<"\nAge : "<<last->age;
        last=last->next;
    }
}

void middle_element()
{
    last=first;
    ptr=last->next;
    while ( ptr!=NULL && ptr->next!=NULL )
    {
        last=last->next;
        ptr=ptr->next->next;
    }
    cout<<"\nThe details of the middle element are :"<<endl;
    cout<<"\nName : "<<last->name;
    cout<<"\nAge : "<<last->age;
}

void reverse_list()
{
    ptr=first;
    backward=first;
    ahead=first->next;
    first->next=NULL;
    while ( ahead!=NULL )
    {
        ptr=ahead;
        ahead=ahead->next;
        ptr->next=backward;
        backward=ptr;
    }
    first=ptr;
    cout<<"\nList after reversal : "<<endl;
    display_list();
}

void palindrome()
{
    int flag=0;
    last=first;
    ptr=last->next;
    while ( ptr!=NULL && ptr->next!=NULL )
    {
        last=last->next;
        ptr=ptr->next->next;
    }
    if ( ptr==NULL)
        m=last;
    else
        m=last->next;
    ptr=first;
    backward=first;
    ahead=first->next;
    first->next=NULL;
    while ( ahead!=m )
    {
        ptr=ahead;
        ahead=ahead->next;
        ptr->next=backward;
        backward=ptr;
    }
    if ( m==last)
    {
        ahead=ahead->next;
        last=backward;
    }
    while ( ahead!=NULL && last!=NULL)
    {
        if ( ahead->age!=last->age)
        {
            flag=1;
            break;
        }
        ahead=ahead->next;
        last=last->next;
    }
    if ( flag==1)
        cout<<"The List is not a palindrome"<<endl;

    else
        cout<<"It is a palindrome"<<endl;
}

void split()
{
    last=first;
    ptr=last->next;
    while ( ptr!=NULL && ptr->next!=NULL )
    {
        last=last->next;
        ptr=ptr->next->next;
    }
    m=last->next;
    last->next=NULL;
    last=first;
    cout<<"The first half is : "<<endl;
    while (last!=NULL)
    {
        cout<<"Name : "<<last->name<<endl;
        cout<<"Age : "<<last->age<<endl;
        last=last->next;
    }
    cout<<"The second half id : "<<endl;
    n=m;
    while ( n!=NULL)
    {
        cout<<"Name : "<<n->name<<endl;
        cout<<"Age : "<<n->age<<endl;
        n=n->next;
    }
}
