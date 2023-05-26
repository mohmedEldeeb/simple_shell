#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>


extern char **var_environ;

/**
 * struct liststring - to singly linked list
 * @num: number
 * @str: a string
 * @next: to the next node
 */

typedef struct liststring
{
	int num;
	char *str;
	struct liststring *next;
} list_t;


/**
 *struct passdata - contains arguements to pass into a function,
 *
 *@arg: tring generated from getline
 *@argv: array of strings arg
 *@path: string path for the command
 *@argc: argument count
 *@line_count: error count
 *@err_num: error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy  LL env
 *@history: node
 *@alias: alias node
 *@env_changed: on if environ was changed
 *@status: return status exec'd command
 *@cmd_buf: address of pointer to cmd_buf if chaining
 *@cmd_buf_type: CMD_type || or && or ;
 *@readfd: fd to read line input
 *@histcount: line number count
 */

typedef struct passdata
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;


char *_strcpy(char *dest, char *src);

/* to handel error ***  _error.c file*/

int _eputchar(char c);
void _eputs(char *str);


/* file **** _string.c*/

char *_strdup(const char *strn);


/* file invire *** inviro.c */

int populate_env_list(info_t *infos);

/*  file list.c */
list_t *node_end(list_t **head, const char *str, int num);

/* file memory.c*/
char *_memset(char *s, char b, unsigned int n);

#endif
