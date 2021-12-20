#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>

#define MAXCOMMAND 100 
#define clear() printf("\033[H\033[J")


int takeParams(char *userInput);

void execArgs(char **parsedParams);

int execCommand(char **parsedParams);

void handleCommands(char **commands, char **parsedParams);

void splitWithSpace(char *str, char** parsedParams);

void splitCommands(char *str, char **commands);


int main()
{
    
    char userInput[1000];
    char *commands[MAXCOMMAND];
    char *parsedParams[MAXCOMMAND];
    
    while (1)
    {
        if (takeParams(userInput))
            continue;

        splitCommands(userInput, commands); // Split according to '|'
        
        handleCommands(commands, parsedParams);  // 
    }
    
    return 0;
}

int takeParams(char *userInput)
{
    char *buffer;    
    buffer = readline("\nmyshell>>> ");
    if (strlen(buffer) != 0) // While read string not empty
    {
        add_history(buffer);  // I add it to the history which user can select again with up and down buttons. 
        strcpy(userInput, buffer); // And i copy it to input.
        return 0;
    }
    else
    {
        return 1;
    }
}

void execArgs(char **parsed)  
{
    int pid = fork();  
    int i;

    if (pid == -1)
    {
        printf("\nFailed forking child..");
        return;
    }
    else if (pid == 0)
    {
        i = execv(parsed[0], parsed);  // Execute file with its name and parameters.

        if (i < 0)
        {
            printf("\n Could Not Execute Command...");
        }
        
        exit(0);
    }
    else
    {
        wait(&i); 			// Wait until its terminate.
    }
}

int execCommand(char **parsedParams)
{
    pid_t p2;
    
    int commandCount = 8, i, caseIndex = -1;
    char *commands[commandCount];

    // Add shell commands. 
    commands[0] = "exit";
    commands[1] = "cd";
    commands[2] = "cat";
    commands[3] = "clear";
    commands[4] = "operation";
    commands[5] = "repeat";
    commands[6] = "ls";
    commands[7] = "bash";

    // Find the user command index.
    for (i = 0; i < commandCount; i++)
    {
        if (strcmp(parsedParams[0], commands[i]) == 0)
        {
            caseIndex = i;
            break;
        }
    }

    // Execute it.
    switch (caseIndex)
    {
	    case 0:
		printf("\nGoodbye\n");
		exit(0);
	    case 1:
		chdir(parsedParams[1]);
		return 1;
	    case 2:
		printf("cat: %s\n", parsedParams[1]); 
		return 1;
	    case 3:
		clear();
		return 1;
	    case 4:
		execArgs(parsedParams);
		return 1;
	    case 5:
		execArgs(parsedParams);
		return 1;
	    case 6:
	    	p2 = fork();
		if (p2 == 0)
		    execv("/bin/ls", parsedParams);
		return 1;
	    case 7:
		p2 = fork();
		if (p2 == 0)
		    execv("/bin/bash", parsedParams);
		
		wait(&p2);
		return 1;
	    default:
		break;
    }

    return 0;
}

void handleCommands(char **commands, char **parsedParams)
{
    for (int i = 0; i < MAXCOMMAND; i++)
    {
    	if (commands[i] != NULL)
    	{
    		splitWithSpace(commands[i], parsedParams); // Split command with space
    		if (!execCommand(parsedParams)) 		// Execute it.
    			printf("Wrong Operation Entered...\n");
        }
        else break;
    }
}

void splitWithSpace(char *str, char** parsedParams)
{
    int i = 0;
    while( (parsedParams[i] = strsep(&str, " ")) != NULL )
    {
    	i++;
    }
}

void splitCommands(char *str, char **commands)
{
    int i = 0;
    while( (commands[i] = strsep(&str, "|")) != NULL )
    {
    	i++;
    }
}
