#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int i;
    int f = fork();
    //int filedes[2];
    //pipe(filedes);

    if (f == 0) // If its child process
    {

        //close(filedes[0]);
        //write(filedes[1], argv[2], (strlen(argv[2])+1));
        i = execl(argv[1], argv[2], argv[3]); // Run file with its name.
    }
    else
    {
        if(wait(&i)){ // wait for the terminate then write result.
		if (strcmp("subtraction", argv[1]) == 0)
		{
		    printf("%s - %s = %d\n", argv[2], argv[3], WEXITSTATUS(i));
		}
		else if (strcmp("addition", argv[1]) == 0)
		{
		    printf("%s + %s = %d\n", argv[2], argv[3], WEXITSTATUS(i));
		}
		else
		{
		    printf("Wrong Operation Name...\n");
		}
    	}
    }

    return 0; 
}

