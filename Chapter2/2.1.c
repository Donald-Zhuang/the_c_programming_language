#include <stdio.h>

int main(int argc, char **argv)
{
    int     sint = 0;
    char    schr = 0;
    short   ssht = 0;
    long    slng = 0;

    printf("---- the max of unsigned value ----\n");
    printf("unsigned int   is %u\n", (unsigned int)(~0)  );
    printf("unsigned short is %u\n", (unsigned short)(~0));
    printf("unsigned char  is %u\n", (unsigned char)(~0) );
    printf("unsigned long  is %lu\n",(unsigned long)(~0) );
    
    printf("---- the area of unsigned value ----\n");
    printf("int   is %d ~ %d\n",  (((unsigned int)(~0) >> 1) + 1),   ((unsigned int)(~0)   >> 1)); 
    printf("short is %d ~ %d\n",  (((unsigned short)(~0) >> 1) + 1), ((unsigned short)(~0) >> 1)); 
    printf("char  is %d ~ %d\n",  (((unsigned char)(~0) >> 1) + 1),  ((unsigned char)(~0)  >> 1)); 
    printf("long  is %ld ~ %ld\n",(((unsigned long)(~0) >> 1) + 1),  ((unsigned long)(~0)  >> 1)); 
    return 0;
}

