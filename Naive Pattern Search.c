/* Explanation of Naive String Search */
/* http://www.personal.kent.edu/~rmuhamma/Algorithms/MyAlgorithms/StringMatch/naiveStringMatch.htm */
#include<conio.h>
#include<stdio.h>
int main()
{
    int i, j, k, c=0, m=0, a[50];
    char str[100], patt[20];
    printf("Enter the string\n");
    fgets(str,100,stdin);
    printf("Enter the pattern to be searched\n");
    scanf("%s",&patt);
    for ( i=0; str[i]!='\0'; i++)
    {
        j=0;
        k=i;
        while ( (str[k]==patt[j]) && (str[k]!='\0') && (patt[j]!='\0') )
        {
            k++;
            j++;
        }
        if ( patt[j]=='\0')
        {
            c++;
            for ( ; m<c; m++)
               a[m]=i;
        }
    }
    printf("The entered pattern occurs %d times in the given string",c);
    for ( m=0; m<c; m++)
    printf("%d ",a[m]);
    return 0;
}
