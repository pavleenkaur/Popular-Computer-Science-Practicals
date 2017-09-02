/* Know more about Postfix expressions */
/* http://www.geeksforgeeks.org/stack-set-4-evaluation-postfix-expression/ */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int top=-1;
int s[10];
void push( int num, char exp[10] );
void calc( char a );
void push( int num , char exp[10])
{
    top++;
    s[top]=(int)(exp[num]-48);
}
void calc( char a )
{
    int m, n, res=0;
    m=s[top];
    s[top]='\0';
    top--;
    n=s[top];
    s[top]='\0';
    top--;
    switch(a)
    {
        case '+' : { res=n+m; break; }
        case '-' : { res=n-m; break; }
        case '*' : { res=n*m; break; }
        case '/' : { res=n/m; break; }
    }
    top++;
    s[top]=res;
}
int main()
{
    char exp[10];
    int i;
    printf("Enter the Postfix Expression : ");
    gets(exp);
    for ( i=0; exp[i]!='\0'; i++)
    {
        if ((exp[i]>='0') && (exp[i]<='9'))
            push(i, exp);
        if ( exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' )
            calc(exp[i]);
    }

    printf("The result of the expression is : %d",s[top]);
    return 0;
}
