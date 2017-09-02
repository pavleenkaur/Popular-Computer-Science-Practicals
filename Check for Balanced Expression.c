/* Know more about Balanced Expressions */
/* http://interactivepython.org/runestone/static/pythonds/BasicDS/SimpleBalancedParentheses.html */

#include <stdio.h>
#include <stdlib.h>
int top=-1;
void push(char a, int s[20]);
void check();

void push(char a, int s[20])
{
    top++;
    s[top]=a;
}

void pop()
{
    if ( top==-1)
        printf("Underflow deteced\n");
    else
        top--;
}

void check()
{
    if ( top==-1)
        printf("The expression is properly parenthesized.\n ");
    else
        printf("The expression is not parenthesized properly. \n");
}

int main()
{
    int i;
    int s[20];
    char exp[20];
    printf("Enter the expression : ");
    gets(exp);
    for ( i=0; exp[i]!='\0'; i++)
    {
        if ( exp[i]=='(' || exp[i]=='{' || exp[i]=='[' )
            push(exp[i], s);
        else if ( exp[i]==')' || exp[i]=='}' || exp[i]==']')
            pop();
    }
    check();
    return 0;
}
