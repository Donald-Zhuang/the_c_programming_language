/***********************************************************/
//     File Name   : 3.2.2.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Wed 15 Feb 2017 03:19:47 PM PST
/**********************************************************/

#include <stdio.h>

int anti_escope(char s[], char t[])
{
    int i=0, j=0;
    while(s[i] != '0')
    {
        if(s[i] == '\\')
        {
            switch (s[i+1])
            {
                case 'n':
                    t[j++] = '\n';
                    break;
                case 't':
                    t[j++] = '\t';
                    break;
                default:
                    t[j++] = s[i];
                    t[j++] = s[i+1];
                    break;
            }
            i+=2;
        }else{
            t[j++] = s[i];
            i++;
        }
    }
    return 0;
}

int main(int argc,char *argv[])
{
    char s[] = "She is safe.\\tDon't be worry.\\n";
    char t[255] = {0,};
    printf("%s\n", s);
    anti_escope(s, t);
    printf("%s\n", t);
    return 0;
}
