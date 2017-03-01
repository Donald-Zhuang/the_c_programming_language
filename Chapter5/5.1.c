/***********************************************************/
//     File Name   : 5.1.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Tue 28 Feb 2017 07:34:59 AM CST
/**********************************************************/

#include <stdio.h>

char buf[BUFSIZ] = {0};
int bufp = 0;

char getch(void)
{
    if(bufp < 0)
    {
    //    printf("ERR: the buf is empty!\n");
    }
    return bufp > 0 ? buf[--bufp] : getchar();
}
void ungetch(char ch)
{
    if(bufp > BUFSIZ)
        printf("ERR: the buf is full!\n");
    else
        buf[bufp++] = ch;
}

int GetInt(int *num)
{
    char ch;
    int sign = 0;

    //ignore the space character
    while ( isspace(ch = getch()) )
        ;
    if ( !isdigit(ch) && ch != EOF && ch != '+' && ch != '-' )
        return 0;

    //calculate the digital number
    sign = (ch == '-') ? -1 : 1;
    if(ch == '-' || ch == '+')
    {
        int tmp = ch;
        ch = getch();
        if (!isdigit(ch))
        {
            ungetch(ch);
//          ungetch(tmp);
            return tmp;
        }
    }
    for ( *num = 0; isdigit(ch); ch = getch() )
        *num = *num * 10 + ch - '0';
    *num *= sign;
    
    //if it isn't the End Of Input, ungetch the character to buf
    if(ch != EOF)
        ungetch(ch);
    
    return ch;
}

int main(int argc,char *argv[])
{
    int i, num[255] = {0}, ret;
    for(i = 0; ret != EOF && i < 255; i++)
    {
        ret = GetInt(&num[i]);
        num[i] = (ret == '-' || ret == '+') ? 0 : num[i]; 
    }
    for( i-- ;i >= 0;i--)
        printf("%d ", num[i]);
    printf("\n");
    return 0;
}
