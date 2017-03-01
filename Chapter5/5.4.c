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
	char *bs = s;
	char *bt = t;

	while(*s)
		s++;
	while(*t)
		t++;
	for( ; *s == *t; s--, t--)
		if(s == bs || t == bt)
			break;
	if(*s == *t && t == bt && *s != '\0')
		return 1;
	else 
		return 0;
}
int main(int argc, char **argv)
{
    char *s = "Hello World!";
    char *t = "World!";
    
    printf(strend_d(s,t) ? "Yes\n" : "No\n");
    return 0;
}
