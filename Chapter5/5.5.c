/*************************************************************************
	> File Name: 5.5.c
	> Author: donald.zhuang
	> mail: donald.zhuang@mstarsemi.com
	> Created Time: Wednesday, March 01, 2017 PM03:22:41 CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int strncpy_d(char *src, char *des, int n)
{
    int i;
    for( i = 0; i < n && ( *des = *(src + i) ); des++, i++ )
        ;
   return *des = '\0';
}
int strncat_d(char *src, char *des, int n)
{
    int i = 0;
    while(*des)
        des++;
    
    for( ; i < n && (*des = *src); i++, des++, src++ )
        ;
    return *des = '\0';     
}
int strncmp_d(char *src, char *des, int n)
{
    int i;
    for ( i = 0; i < n && *src == *des; i++, src++, des++ )
        ;
    return i >= n ? 0 : 1; //if the first n character of src is same as des then return 0
}

int main(int argc, char **argv)
{
    char *src = "Hello World!\n";
    char des[255] = "Hello File\n";
    //strncpy_d(src, des, 5);
    //strncat_d(src, des, 5);
    
    printf(strncmp_d(src, des, 5) ? "No\n" :"Yes\n");
    return 0;
}
