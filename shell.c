#include "shell.h"
/**
 * main- allows user to write and execute commands
 * Return: Always 0
 */

int main(void)
{
char command[120];

while (true)
{
	show_prompt();
	read_input(command, sizeof(command));
	execute_command(command);
}
return (0);
}
