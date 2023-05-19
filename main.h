#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int __strcmp(const char *s1, const char *s2);
int cd(char **arr);
char *_strtok(char *str, const char *delimit);
extern char **environ;
char **main_path(void);
char *searchexec(char **paths, char *file,  int *p_case);
char **paths(void);
char *_getenv(void);
void free_arr(char **arr);
void ourexit(char *exit1, char **mpath, char **arr, char *args);
void printem(char *shellname, char *program);
int wordcount(char *word);
char **getntok(char **mpath);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strcat(char *dest, char *src);

#endif
