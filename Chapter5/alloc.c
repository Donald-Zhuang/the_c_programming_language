/*************************************************************************
	> File Name: alloc.c
	> Author: donald.zhuang
	> Mail: 1034894966@qq.com
	> Created Time: Fri 03 Mar 2017 07:33:48 AM CST
 ************************************************************************/

#include<stdio.h>

#define MAX_ALLOC_SIZE  (10000)
static char allocbuf[MAX_ALLOC_SIZE] = {0};
static char* allocp = allocbuf;
char *alloc_d(unsigned int length)
{
    if( allocbuf + MAX_ALLOC_SIZE - allocp >= length )
    {
        allocp += length;
        return allocp - length;
    }
    else
    {
        return NULL;
    }
}
void free_d(char *p)
{
    if(p < allocbuf + MAX_ALLOC_SIZE && p >= allocbuf )
    {
        allocp = p;
    }
    else
    {
        printf("ERR: Free the pointer failed!\n");
        return ;
    }
}

static char getchbuf[BUFSIZ];
static unsigned getchbufp = 0;
char getch( void )
{
    return getchbufp > 0 ? getchbuf[--getchbufp] : getchar();
}

unsigned ungetch(char ch)
{
    if(getchbufp < BUFSIZ)
    {
        getchbuf[getchbufp++] = ch;
    }
    else
    {
        printf("ERR: the getchbuf is FULL!\n");
        return ch;
    }
}

#define MAX_LINE_LENGTH (255)
static char getbuf[MAX_LINE_LENGTH] = {0};
int getline_d(char *str, int maxline)
{
    char ch;
    int i;

    for(i = 0; i < maxline && ( ch = getch() ) != EOF && ch != '\n'; i++)
    {
        *(str+i) = ch;
    }
    if(ch != EOF && ch != '\n')
    {
        ungetch(ch);
    }
    return i;
}

#define MAX_INPUT_LINE (1000)
static char *pline[MAX_INPUT_LINE] = {0};
int readlines(char *str, int nline)
{
    int i;
    for (i = 0; i < nline; i++)
    {

    }
}
int main(int argc, char **argv)
{

    return 0;
}
