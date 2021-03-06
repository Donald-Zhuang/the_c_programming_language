/***********************************************************/
//     File Name   : 3.4.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Fri 17 Feb 2017 08:18:53 AM CST
/**********************************************************/

#include <stdio.h>
#include <limits.h>
#include <string.h>

void reverse(char s[])
{
    unsigned int low = 0, high = strlen(s)-1, tmp;
    for( ; low < high; low++, high-- )
    {
        tmp = s[low];
        s[low] = s[high];
        s[high] = tmp;
    }
}

void itob(int n, char s[], int base)
{
    int i = 0, sign, tmpbase;
    unsigned tmp;
    tmp = (sign = n) > 0 ? n : -n;
    do
    {
        tmpbase = tmp%base;
        s[i++] = tmpbase > 9 ? tmpbase + 'A' - 10 :'0' + tmpbase;
    }while( (tmp /= base) > 0 );
    if(sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main(int argc,char *argv[])
{
    int n = INT_MAX;
    char s[255] = {0,};
    printf("%x %o %d\n",n,n,n);
    itob(n, s, 16);
    printf("%s\n", s);
    itob(n, s, 8);
    printf("%s\n", s);
    itob(n, s, 2);
    printf("%s\n", s);
    itob(n, s, 10);
    printf("%s\n", s);
    itob(n, s, 15);
    printf("%s\n", s);
    return 0;
}
