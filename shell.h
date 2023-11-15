#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>


void show_prompt(void);
void myprint(const char *message);
void read_input(char *command, size_t size);
void execute_command(const char *command);


#endif /* SHELL_H */
