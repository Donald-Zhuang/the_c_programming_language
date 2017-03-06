#include <stdio.h>

#define STR_MAX_LENGTH (255)

void squeeze_d(char s1[], const char s2[])
{
    int i, j, k;
    for( k= 0; s2[k]; k++ )
    {
        for(j = i = 0; s1[i]; i++ )
        {
            if(s1[i] != s2[k])
            {
                s1[j++] = s1[i];
            }
        }
        s1[j] = '\0';
    }
}

int main(int argc, char **argv)
{
    int i, ch = 0;
    char str_in1[STR_MAX_LENGTH] = {0},  str_in2[STR_MAX_LENGTH]= {0}; 
    for(i = 0; ( (ch = getchar()) != '\n') && ( str_in1[i] = ch) && (i < (STR_MAX_LENGTH - 1)) ; i++ )
        ;
    
    for(i = 0; ( (ch = getchar()) != '\n') && ( str_in2[i] = ch) && (i < (STR_MAX_LENGTH - 1)) ; i++ )
        ;

    squeeze_d(str_in1, str_in2);
    printf("%s\n", str_in1);
    return 0;
}
