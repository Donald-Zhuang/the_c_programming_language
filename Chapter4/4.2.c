/***********************************************************/
//     File Name   : 4.2.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Sat 18 Feb 2017 07:39:58 AM CST
/**********************************************************/

#include <stdio.h>

double atof_d( char s[] )
{
    int i = 0, j = 0, sign = 1;
    double fRet = 0.0, fPower = 1.0;

    while (isspace(s[i]))
        i++;

    sign = s[i] == '-' ?  -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        i++;
    while ( isdigit(s[i]) )
        fRet = fRet * 10 + s[i++] - '0';

    if(s[i] == '.')
    {
        while( isdigit(s[++i]) )
        {
            fRet = fRet * 10 + s[i] - '0';
            fPower *= 10;
        }
    } 
    fRet = sign * fRet / fPower;

    if( s[i] == 'e' || s[i] == 'E')
    {
        int  num = 0;
        
        sign = s[++i] == '-' ? -1 : 1;
        i += (s[i] == '-' || s[i] == '+') ? 1 : 0;
        
        while(isdigit(s[i]))
            num = num * 10 + s[i++] - '0';
        while(num--)
            fRet *= ( (sign == -1) ? 0.1 : 10 ); 
    }

    return fRet;
}


int main(int argc,char *argv[])
{
    printf("123.4\t%f\n",atof_d("123.4"));
    printf(".4\t%f\n",atof_d(".4"));
    printf("123.\t%f\n",atof_d("123."));
    printf("0.\t%f\n",atof_d("0."));
    printf("123s\t%f\n",atof_d("123s"));
    printf("-123.4\t%f\n",atof_d("-123.4"));
    printf("+123.4\t%f\n",atof_d("+123.4"));
    printf("  123.4\t%f\n",atof_d(" 123.4  "));
    
    printf("12e3\t%f\n",atof_d("12.e3"));
    printf("-12e3\t%f\n",atof_d("-12e3"));
    printf("12e-3\t%f\n",atof_d("12e-3"));
    printf("12.3e3\t%f\n",atof_d("12.3e3"));
    printf(".12e3\t%f\n",atof_d(".12e3"));
    printf("12.e-3\t%f\n",atof_d("12.e-3"));
    printf("12.e3\t%f\n",atof_d("12.e3"));
    return 0;
}
