/*************************************************************************
	> File Name: 5.4.c
	> Author: donald.zhuang
	> mail: donald.zhuang@mstarsemi.com
	> Created Time: Wednesday, March 01, 2017 PM02:40:48 CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
int strend_d(char *s, char *t)
{
    int t_length = strlen(t);
    int s_length = strlen(s);
    int i = 0; 
    if( !(t_length && s_length) || t_length > s_length )
    {
        //printf("ERR: t is longer than s!\n");
        return 0;
    }
    s = s + s_length - t_length;
    for( ; *t == *s && *t != '\0'; t++, s++)
    {
        //printf("%c\n", *(t+i));
    }
    return *t == '\0' ? 1 : 0;
}
int main(int argc, char **argv)
{
    char *s = "Hello World!";
    char *t = "";
    
    printf(strend_d(s,t) ? "Yes\n" : "No\n");
    return 0;
}
