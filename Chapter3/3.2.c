/***********************************************************/
//     File Name   : 3.2.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Wed 15 Feb 2017 03:04:33 PM PST
/**********************************************************/

#include <stdio.h>

int escope(char s[],char t[])
{
    int i = 0,j = 0;
    while(s[i] != '\0')
    {
        switch(s[i])
        {
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            default:
                t[j++] = s[i];
        }
        i++;
    }
    return 0;
}

int main(int argc,char *argv[])
{
    char s[] = "She is safe.\tDon't be warry.\n";
    char t[255] = {0,};

    printf("%s\n", s);
    escope(s,t);
    printf("%s\n", t);

    return 0;
}
