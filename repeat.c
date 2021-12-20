#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i = 0;                       
    int repeatCount = atoi(argv[2]);

    while (i < repeatCount)
    {
        printf("%s\n", argv[1]);
        i++;
    }
    return 0;
}
