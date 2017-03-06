/***********************************************************/
//     File Name   : 3.1.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Wed 15 Feb 2017 06:51:43 AM PST
/**********************************************************/

#include <stdio.h>

int BinSearch(int target, int arr[], int cnt)
{
    int high = cnt - 1, low = 0;
    int mid = (high + low) / 2;

    while ( (high >= low) && (arr[mid] != target) )
    {
        if(target > arr[mid])
        {
            low = mid + 1; 
        }
        else
        {
            high = mid - 1;
        }
        mid = (high + low) / 2;
    }
    return (arr[mid] == target ? mid : -1);
}

int main(int argc,char *argv[])
{
    int target = 0;
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    scanf( "%d", &target );
    printf("the location of input in the array is %d.\n", BinSearch(target, arr, 10));
    return 0;
}
