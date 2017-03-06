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

void itoa(int n, char s[])
{
    int i = 0, sign;
    unsigned tmp;
    tmp = (sign = n) > 0 ? n : -n;
    do
    {
        s[i++] = (tmp % 10) + '0';
    }while( (tmp /= 10) > 0 );
    if(sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    //printf("%s %d\n",s,n);
    reverse(s);
}

int main(int argc,char *argv[])
{
    int n = INT_MIN;
    char s[255] = {0,};
    itoa(n, s);
    printf("%s\n", s);
    return 0;
}
