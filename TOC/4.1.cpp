//4.1
#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
// List of C keywords
char *keywords[] = {
    "auto","break","case","char","const","continue","default",
    "do","double","else","enum","extern","float","for","goto",
    "if","int","long","register","return","short","signed",
    "sizeof","static","struct","switch","typedef","union",
    "unsigned","void","volatile","while"
};  
 
// Check whether the string is a keyword
int isKeyword(char str[])
{
    int i;
    for(i = 0; i < 32; i++)
    {
        if(strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}
 
// State Function Declaration
int q1(char str[], int i);
 
// Start State
int q0(char str[], int i)
{
    if(isalpha(str[i]) || str[i] == '_')
        return q1(str, i + 1);
 
    return 0;
}
 
// Accept State
int q1(char str[], int i)
{
    if(str[i] == '\0')
        return 1;
 
    if(isalnum(str[i]) || str[i] == '_')
        return q1(str, i + 1);
 
    return 0;
}
 
int main()
{
    char str[50];
    char choice;
 
    while(1)
    {
        printf("\nEnter a string: ");
        scanf("%s", str);
 
        if(isKeyword(str))
            printf("%s is a C Keyword.\n", str);
        else if(q0(str, 0))
            printf("%s is a Valid Identifier.\n", str);
        else
            printf("%s is an Invalid Identifier.\n", str);
 
        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &choice);
 
        if(choice == 'n' || choice == 'N')
            break;
    }
 
    printf("\nProgram Terminated.\n");
 
    return 0;
}   
