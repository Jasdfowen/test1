#include <stdio.h>

int i=0;

int main(void)
{
    int i=1;
    printf("i=%d\n", i); //i=1
    {
        int i=2;
        printf("i=%d\n", i);//i=2
        {
            i++;
            printf("i=%d\n", i);//i=3
        }
        printf("i=%d\n", i);//i=3
    }
    printf("i=%d\n", i);//i=1
    
    return(0);
}