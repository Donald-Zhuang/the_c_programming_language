/***********************************************************/
//     File Name   : 2.6.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Mon 30 Jan 2017 06:04:46 AM PST
/**********************************************************/

#include <stdio.h>
int setbits_d(int x, int p, int n, int y )
{
    return ( ((y & ~(~0 << n)) << (p + 1 - n)) | \
             (~((~(~0 << n)) << (p + 1 - n)) & x) );
}
int main(int argc,char *argv[])
{
    int num1 = 0, num2 = 0, pos = 0, cnt = 0;
    scanf("%d %d %d %d", &num1, &num2, &pos, &cnt);
    printf("%x and %x result is %d\n",num1, num2, setbits_d(num1, pos, cnt, num2));
    return 0;
}
