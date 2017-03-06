#include <stdio.h>

unsigned long htoi_dup( char ch[], int length )
{
    int i = 0, aft = 0;
    unsigned long num = 0;
    if( (ch[i] == '0') && ((ch[i+1] == 'x')||(ch[i+1] == 'X')) )
    {
        i += 2;
    }
    while(length > i)
    {
        aft = i;
        num = ((ch[i] >= 'A') && (ch[i] <= 'F')) ? (num << 4)+(ch[i++] - 'A' + 10) : num; 
        num = ((ch[i] >= '0') && (ch[i] <= '9')) ? (num << 4)+(ch[i++] - '0')      : num; 
        num = ((ch[i] >= 'a') && (ch[i] <= 'f')) ? (num << 4)+(ch[i++] - 'a' + 10) : num;
        if(aft == i)
        {
            break;
        }
    }

    return (i < length ? 0L : num); //if the num is illegal, the result is 0.
}

int main( int argc, char **argv )
{
    char ch, num_in[255] = {0};
    unsigned int i = 0;
    while( ((ch = getchar()) != '\n') && (num_in[i++] = ch) )
        ;
    printf( "the final result is %ld\n", htoi_dup(num_in, i) );
    return 0;
}
