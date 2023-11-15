#include "shell.h"

/**
 * show_prompt - Prompts the user to enter input
 * Description: it prompts the user to input a command.
 */

void show_prompt(void)
{
	myprint("my_shell$ ");
}


/**
 * read_input - Reads user input
 * @command: char pointer object
 * @size: size_t variable
 */

void read_input(char *command, size_t size)
{
	if (fgets(command, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			myprint("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			myprint("Error Reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	command[strcspn(command, "\n")] = '\0';
}


/**
 *myprint- prints string to the output stream
 *@string: char pointer to string
 */
void myprint(const char *string)
{
	write(STDOUT_FILENO, string, strlen(string));
}

/**
 * execute_command- tokenizes and executes string as a command
 * @command: char pointer to inut string
 */

void execute_command(const char *command)
{
	pid_t child = fork();

	if (child == -1)
	{
		myprint("Error forking process.\n");
		exit(EXIT_FAILURE);
	}

	else if (child == 0)
	{
		/* child process */
		/* Tokenize input into:command and its arguments*/
		char *args[120]; /* Maximum 120 char */
	int arg_count = 0;
	char *token = strtok((char *)command, " ");

	while (token != NULL)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " ");
	}
	args[arg_count] = NULL; /*Null-terminate the arguments array*/
	/* execute the command */
	execvp(args[0], args);
	/* If execvp fails, print an error message */
	myprint("Error executing command.\n");
	exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
