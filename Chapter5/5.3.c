/*************************************************************************
	> File Name: 5.3.c
	> Author: Donald.Zhuang
	> Mail: 
	> Created Time: Wednesday, March 01, 2017 AM11:17:20 CST
 ************************************************************************/

#include<stdio.h>

void strcat_d(char *src, char *des)
{
    while(*des != '\0')
        des++;
    while(*src = *des)
		;
}

int main(int argc, char **argv)
{
    char *src = "Hello World!\n";
    char des[255] = "Log:\n";
 
	strcat_d(src, des);
    
	printf("%s",des);
    return 0;
}
