/***********************************************************/
//     File Name   : 2.10.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Mon 30 Jan 2017 05:32:34 PM PST
/**********************************************************/

#include <stdio.h>

char UpToLow_d(char ch)
{
    return (((ch >= 'A')&&(ch <= 'Z')) ? ('a'+ ch - 'A') : ch );
}


int main(int argc,char *argv[])
{
    char ch;
    ch = getchar();
    printf("%c:the result is %c\n", ch, UpToLow_d(ch));
    return 0;
}
