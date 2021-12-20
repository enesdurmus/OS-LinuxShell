#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int subtraction(int a, int b);

int isNumber(char a[]);

int main(int argc, char *argv[])
{
    int i = 0;
    if (isNumber(argv[0]) && isNumber(argv[1]))
    {

        int first = atoi(argv[0]);
        int second = atoi(argv[1]);
        return subtraction(first, second);
    }
    else{
        printf("There Is An Undigit Char");
    }

    return 0;
}

int subtraction(int a, int b)
{
    int result = 0;
    result = a - b;
    return result;
}

int isNumber(char a[])
{
    int i ;
    int length = 0;
    length = strlen(a);
    for (i = 0; i < length; i++)
    {
        if (!isdigit(a[i]))
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}
