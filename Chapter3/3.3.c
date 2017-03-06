/***********************************************************/
//     File Name   : 3.3.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Thu 16 Feb 2017 03:15:31 PM PST
/**********************************************************/

#include <stdio.h>

int expand_d(char s[], char d[])
{
    int i, j = 0;
    for (i=0; s[i]; )
    {
        if( ( isdigit(s[i]) && s[i+1] == '-' && isdigit(s[i+2]) ) || \
            ( isalpha(s[i]) && s[i+1] == '-' && isalpha(s[i+2]) )    \
          ) 
        {
            int k = s[i], incr = (s[i+2] - s[i] > 0) ? 1 : -1;
            while( k != s[i+2] )
            {
                d[j++] = k;
                k += incr;
            }
            d[j++] = k;
            i += 3;
        }else{
            d[j++] = s[i++];
        } 
    }
    d[j] = '\0';
    return 0;
}

int main(int argc,char *argv[])
{
    char s[] = "-za-da-aa-c-a1-4.a-4-f-c9-0,\n";
    char d[255] = {0, };
    printf("%s", s);
    expand_d(s, d);
    printf("%s", d);
    return 0;
}
