/***********************************************************/
//     File Name   : 4.7.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Tue 21 Feb 2017 08:26:44 AM CST
/**********************************************************/

#include <stdio.h>
#include <string.h>

#define EMPTY_OF_STACK  (0)
#define FULL_OF_STACK   (BUFSIZ)

static char buf[BUFSIZ] = {0, };
static int  bufp = 0;

int ungetch( char ch )
{
    if (bufp < FULL_OF_STACK)
        buf[bufp++] = ch;
    else 
        printf("ERROR: Full of Stack!\n");
    return bufp;
}

int ungets( char *s )
{
    while(*s)
    {
        ungetch(*s);
        s++;
    }
}

int main(int argc,char *argv[])
{
    char *s = "Hello, world!\n";
    
    ungets(s);

    printf("%s, %d\n", buf, bufp);
    return 0;
}
