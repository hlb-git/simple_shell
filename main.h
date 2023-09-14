#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* Global enviroment variable */
extern char **environ;

char *find_path(char *cmd);
void pretty(void);
void execute_command(char *args[]);
void handle_user_input(void);

#endif
