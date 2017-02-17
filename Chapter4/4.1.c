/***********************************************************/
//     File Name   : 4.1.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Sat 18 Feb 2017 07:15:43 AM CST
/**********************************************************/

#include <stdio.h>

int strindex(char s[], char t[])
{
    int i, j;
    if( !s[0] || !t[0] )
    {
        printf("One of the parameters is EMPTY STRING.\n");
        return -1;
    }
    for(i = 0; s[i] && i < 255; i++)
    {
        for(j = 0; t[j] && j < 255 && t[j] == s[i+j]; j++ )
            ;
        if(j>0 && t[j] == '\0')
            return i+j;
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
    return 0;
}
