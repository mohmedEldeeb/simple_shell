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


extern char **environ;

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
void remove_comments(char *buf);
int _eputchar(char c);
void _eputs(char *str);
void remove_comments(char *buf);

/* file **** _string.c*/
int _strlen(char *s);
char *_strdup(const char *strn);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *starts_with(const char *, const char *);
void _puts(char *str);
int _putchar(char c);
char *_strncpy(char *dest, char *src, int n);
char *_strncat(char *dest, char *src, int n);

/* file invire *** inviro.c */
char *_togetenv(info_t *info, const char *name);
int populate_env_list(info_t *infos);

/*  file list.c */
list_t *node_end(list_t **head, const char *str, int num);
int delete_node_at_index(list_t **head, unsigned int index);
void free_list(list_t **head_ptr);

/* file memory.c*/
char *_memset(char *s, char b, unsigned int n);
int bfree(void **pt);

/* file history.c */
int read_history(info_t *infos);
int build_history_list(info_t *info, char *buf, int linecount);
char *get_history_file(info_t *info);
int renumber_history(info_t *info);

/* handel hsh file */
int to_hsh(info_t *info);

/* getinfo file */
void free_info(info_t *info, int all);
int interactive(info_t *info);
void clear_info(info_t *info);


/*get line file */
int _getline(info_t *info, char **ptr, size_t *length);
ssize_t get_input(info_t *info);
ssize_t input_buf(info_t *info, char **buf, size_t *len);
ssize_t read_buf(info_t *info, char *buf, size_t *i);


/* relocated file */
void ffree(char **pp);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);


/* exist file*/
char *_strchr(char *s, char c);

/* file var.c*/
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len);
int is_chain(info_t *info, char *buf, size_t *p);

/*  function file */
void sigintHandler(int);


#endif
