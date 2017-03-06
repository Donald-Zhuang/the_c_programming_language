/*************************************************************************
  > File Name: alloc.c
  > Author: donald.zhuang
  > Mail: 1034894966@qq.com
  > Created Time: Fri 03 Mar 2017 07:33:48 AM CST
 ************************************************************************/
#include <stdio.h>
#include <string.h>
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
    *(str + i) = '\0';
    return i;
}

#define MAX_INPUT_LINE (1000)
static char *pline[MAX_INPUT_LINE] = {0};
int readlines(char *str[], int maxlines)
{
    int nlines = 0, len;
    char *p, line[MAX_LINE_LENGTH];

    while( (len = getline_d(line, MAX_LINE_LENGTH)) > 0)
    {
        if(nlines >= maxlines || (p = alloc_d(len)) == NULL )
        {
            return -1;
        }
        else
        {
            line[len - 1] = '\0';
            strcpy(p, line);
            str[nlines++] = p;
        }
    }
    return nlines;
}

void writelines(char *str[], int nlines)
{
    while(nlines--)
    {
        printf("%s\n", *str++);
    }
}

void qsort_d(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);
    if(left > right)
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for(i = left + 1; i <= right; i++)
    {
        if(strcmp(v[i], v[left]) < 0)
        {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort_d(v, left, last - 1);
    qsort_d(v, last+1, right);
}

void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int main(int argc, char **argv)
{
    int nlines = 0;
    if( (nlines = readlines(pline, MAX_LINE_LENGTH) ) >= 0)
    {
        qsort_d(pline, 0, nlines - 1);
        writelines(pline, nlines);
        return 0;
    }
    else 
    {
        printf("ERR: input error!\n");
        return 1;
    }
    return 0;
}
