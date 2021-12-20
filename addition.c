#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int addition(int a, int b);

int isNumber(char a[]);


int main(int argc, char *argv[])
{
    //int filedes[2], nbytes;
    //char readbuffer[80]; 
    //pipe(filedes);
    
    //read(filedes[0], readbuffer, sizeof(readbuffer));
    //printf("Read string: %s", readbuffer);
    
    int i = 0;
    
    if (isNumber(argv[0]) && isNumber(argv[1]))  // If parameters are integer.
    {
        int first = atoi(argv[0]);
        int second = atoi(argv[1]);
        return addition(first, second);
    }
    else
    {
        printf("There Is An Undigit Char...");
        return -1;
    }

    return 0;
}

int addition(int a, int b)
{
    int result = 0;
    result = a + b;
    return result;
}


int isNumber(char a[])
{
    int i;
    int length = 0;
    length = strlen(a);
    for (i = 0; i < length; i++)
    {
        if (!isdigit(a[i]))  //Check every letter of parameter.
            return 0;
    }
    
    return 1;
}
