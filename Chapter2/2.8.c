/***********************************************************/
//     File Name   : 2.8.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Mon 30 Jan 2017 06:33:18 AM PST
/**********************************************************/

#include <stdio.h>
int int_length( void )
{
    unsigned int x = ~0, i = 0;
    while( (++i) && (x <<= 1) )
        ;
    printf("length of integer is %d\n", i);
    return i;
}
int rightrot_d(int x, int n)
{
    int length = int_length();
    while(n--)
    {
        if( 1 & x )
        {
            x >>= 1;
            x |= 1<<(length-1); 
        }
        else
        {
            x >>= 1;
            x &= ~(1<<(length-1));
        }
    }
    return x;
}

int main(int argc,char *argv[])
{
    int num, cnt;
    scanf("%d %d", &num, &cnt);
    printf("%x: the result is %x\n",num, rightrot_d(num, cnt));
    return 0;
}
