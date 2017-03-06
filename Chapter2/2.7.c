/***********************************************************/
//     File Name   : 2.7.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Mon 30 Jan 2017 06:23:36 AM PST
/**********************************************************/

#include <stdio.h>
int invert_d(int x, int p, int n)
{
    return ( (~(~0 << n) << (p-n+1)) ^ x );
}
int main(int argc,char *argv[])
{
    int num, pos, cnt;
    scanf("%d %d %d", &num, &pos, &cnt);
    printf("%x: result is %x", num, invert_d(num, pos, cnt));
    return 0;
}
