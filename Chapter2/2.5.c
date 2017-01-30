/***********************************************************/
//     File Name   : 2.5.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Mon 30 Jan 2017 05:34:28 AM PST
/***********************************************************/

#include <stdio.h>

#define STR_MAX_LENGTH (255)

int any_d(char s1[], char s2[])
{
    int i, j;
    
    for ( i = 0; s1[i] != '\0'; i++ )
    {
        for ( j = 0; s2[j] != '\0'; j++ )
        {
            if( s1[i] == s2[j] )
            {
                return i;
            }
        }
    }
    return -1;
}
int main(int argc,char *argv[])
{
    int i,ch;
    char str_in1[STR_MAX_LENGTH] = {0}, str_in2[STR_MAX_LENGTH] = {0};
    for (i = 0; ((ch = getchar())!= '\n') && (str_in1[i] = ch) && (i < (STR_MAX_LENGTH - 1)); i++) 
        ;
    for (i = 0; ((ch = getchar())!= '\n') && (str_in2[i] = ch) && (i < (STR_MAX_LENGTH - 1)); i++) 
        ;
    
    printf("the position is %d\n", any_d(str_in1, str_in2));
    return 0;
}
