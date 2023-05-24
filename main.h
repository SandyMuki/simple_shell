#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int env(void);
int execute_inbuilt(char **arr, int *inbuilt_ran);
int __strcmp(const char *s1, const char *s2);
int cd(char **arr);
char *_strtok(char *str, const char *delimit);
extern char **environ;
char **main_path(void);
char *searchexec(char **paths, char *file,  int *p_case);
char **paths(void);
char *_getenv(void);
void free_arr(char **arr);
void ourexit(char *exit1, char **mpath, char **arr, char *args, int exit_stat);
void printem(char *shellname, int runstat, char *program);
int wordcount(char *word);
char **getntok(char **mpath, int exit_stat);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strcat(char *dest, char *src);

#endif
