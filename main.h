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
void execute_command(char *str, char *args[]);
void handle_user_input(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *dupstr(char *source);
#endif
