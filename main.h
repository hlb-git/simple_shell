#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

/* Global enviroment variable */
extern char **environ;

char *getline_cmd(void);
char **get_token(char *input);
void exit_cmd(char *argv, char **arg, char *input, int _exit);
void my_getenv(char **env);
int find_path(char **arg, char **env);
char *get_env(char **env);
int fork_it(char **arg, char **av, char **env, char *input, int np, int c);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
size_t _strncmp(char *s1, char *s2, size_t n);
char *_strtok(char *str, const char *delim);

#endif
