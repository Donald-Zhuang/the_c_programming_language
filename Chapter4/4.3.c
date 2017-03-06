/***********************************************************/
//     File Name   : 4.3.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Sat 18 Feb 2017 10:41:30 AM CST
/**********************************************************/

#include <stdio.h>

#define MAX_LENGTH_OF_OP    (100)
#define MAX_DEPTH_OF_STACK  (255)
#define END_OF_STACK        (-1)
#define NUMBER              ('0')

double stack[MAX_DEPTH_OF_STACK] = {0,};
int sp = END_OF_STACK;

char buf[BUFSIZ] = {0,};
int bufp = END_OF_STACK;

char getch(void)
{
    return (bufp > END_OF_STACK ? buf[bufp--] : getchar() );
}

void ungetch(char ch)
{
    if(bufp < BUFSIZ)
    {
        buf[++bufp] = ch;
    }
    else
    {
        printf("the buffer is full!\n");
    }
}

char getop(char s[])
{
    char ch = 0, cnt = 0;
    while( (s[0] = ch = getch()) == ' ' || ch == '\t' )
        ;
    s[1] = '\0';
    if( !isdigit(ch) && ch != '.' && ch != 'e' && ch != 'E' )
        return ch;
    cnt = 0;
    if(isdigit(ch))
    {
        while(isdigit(s[++cnt] = ch = getch()))
            ;
    }
    if (ch == '.')
    {
        while(isdigit(s[++cnt] = ch = getch()))
            ;
    }
    if(ch == 'e' || ch == 'E')
    {
        while( ( isdigit(s[++cnt] = ch = getch()) ) || (ch == '-') || (ch == '+') )
            ;
    }
    s[cnt] = '\0';
    if(ch != EOF)
        ungetch(ch);
    return NUMBER;
} 

void push(double num)
{
    if (sp < MAX_DEPTH_OF_STACK )
    {
       stack[++sp] = num;
    }
    else
    {
        printf("the stack is full!\n");
    }
}

double pop(void)
{
    if (sp > END_OF_STACK)
    {
        return stack[sp--];
    }
    else 
    {
        printf("the stack is empty!\n");
        return 0;
    }
}

void printTopStack(void)
{
    printf("The top element of stack is %f\n", stack[sp]);
}

void duplicateTopStack(void)
{
    printf("Copy top element and push it: %f\n", stack[++sp] = stack[sp-1] );
}

void cleanStack(void)
{
    printf("Clean the stack!\n");
    sp = END_OF_STACK;
}

void swapTopTwoElement(void)
{
    if( sp < END_OF_STACK + 2 )
    {
        printf("Error: the number of elements in the stack is lease than two!\n");
        return ;
    }else{
        printf("Swap the top two element of stack!\n");
        double tmp = stack[sp];
        stack[sp] = stack[sp-1];
        stack[sp-1] = tmp;
    }
}
double atof(char s[])
{
    int i, j, sign = 1, fPower = 1;
    double fRet = 0.0;

    for(i = 0; isspace(s[i]); i++)
        ;
    
    sign = (s[i] == '-') ? -1 : 1; 
    if(s[i] == '-' || s[i] == '+')
        i++;

    while(isdigit(s[i]))
        fRet = fRet * 10.0 + s[i++] - '0';
    
    if(s[i] == '.')
    {
        i++;
        while( isdigit(s[i]) )
        {
            fRet = fRet * 10 + s[i++] - '0'; 
            fPower *= 10;
        }
    }

    fRet = sign * fRet/fPower;
    if( s[i] == 'e' || s[i] == 'E' )
    {
        int tmp = 0;
        sign = s[++i] == '-' ? -1 : 1;
        i += s[i] == '-' || s[i] == '+' ? 1 : 0;
        while(isdigit(s[i]))
            tmp = tmp * 10 + s[i++] - '0';
        while(tmp--)
        {
            if (sign == -1)
            {
                fRet /= 10;
            }else{
                fRet *= 10;
            }
        }
    }
    return fRet;
}

int main(int argc,char *argv[])
{
    int type = 0;
    double op = 0, op2 = 0;
    char s[MAX_LENGTH_OF_OP] = {0,};

    while ((type = getop(s)) != EOF)
    {
        switch(type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case 'p':
                printTopStack();
                break;
            case 'd':
                duplicateTopStack();
                break;
            case 's':
                swapTopTwoElement();
                break;
            case 'c':
                cleanStack();
                break;
            case '%':
                op = pop(); 
                op2 = pop();
                if( op == 0 )
                {
                    printf("Error: zero divisor!\n");
                }
                else if( op < 0 || op2 < 0)
                {
                    printf("%% is not support negetive!\n");
                }
                else
                {
                    push( (int)op2 % (int)op );
                }
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op = pop();
                push(pop() - op);
                break;
            case '/':
                op = pop();
                if(op == 0)
                {
                    printf("error: zero divisor!\n");
                }
                push(pop()/op);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '\n':
                printf("the result of the eqution is %f.\n", pop());
                break;
            default:
                printf("The eqution is error!\n");
                break;
        }
    }
    return 0;
}
