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

int GetFloat(double *num)
{
    char ch;
    int sign = 1;

    //ignore the space character
    while ( isspace(ch = getch()) )
        ;
    if ( !isdigit(ch) && ch != EOF && ch != '+' && ch != '-' && ch != '.' )
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
        *num = *num * 10.0 + ch - '0';
    
	if(ch == '.')
	{
		double dpower = 1.0;
		ch = getch();
		for ( ;isdigit(ch); ch = getch() )
		{
			*num = *num * 10.0 + ch - '0';
			dpower *= 10;
		}
		*num = *num / dpower;
	}

    *num *= sign;
    //if it isn't the End Of Input, ungetch the character to buf
    if(ch != EOF)
        ungetch(ch);
    
    return ch;
}

int main(int argc,char *argv[])
{
    double  num[255] = {0};
	int i, ret;
    for(i = 0; ret != EOF && i < 255; i++)
    {
        ret = GetFloat(&num[i]);
        num[i] = (ret == '-' || ret == '+') ? 0.0 : num[i]; 
    }
    for( i-- ;i >= 0;i--)
        printf("%f ", num[i]);
    printf("\n");
    return 0;
}
