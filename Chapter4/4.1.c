/***********************************************************/
//     File Name   : 4.1.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Sat 18 Feb 2017 07:15:43 AM CST
/**********************************************************/

#include <stdio.h>
#include <string.h>
int strindex(char s[], char t[])
{
    int i, j;
    for(i = strlen(s) - strlen(t); i >= 0 ; i--)
    {
        for(j = 0; t[j] && s[i+j] == t[j]; j++ )
            ;
        if(j > 0 && t[j] == '\0')
            return i+1;
    }
    return -1;
}

int main(int argc,char *argv[])
{
    printf("7 in 1234567 is %d\n", strindex("1234567", "7"));
    printf("  in 1234567 is %d\n", strindex("1234567", ""));
    printf("67 in 1234567 is %d\n", strindex("1234567", "67"));
    printf("4567 in 1234567 is %d\n", strindex("1234567", "4567"));
    printf("457 in 1234567 is %d\n", strindex("1234567", "457"));
    printf("1 in 1234567 is %d\n", strindex("1234567", "1"));
    printf("456 in 1234567 is %d\n", strindex("1234567", "456"));
    printf("45 in 12345458 is %d\n", strindex("12345458", "45"));
    printf("3 in 12345638 is %d\n", strindex("12345638", "3"));
    printf(" in  is %d\n", strindex("", ""));
    return 0;
}
