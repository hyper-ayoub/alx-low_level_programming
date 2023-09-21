#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include "shell.h"


/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;
/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *					allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@arv: an array of strings generated from arg
 *@path: a string path for the current command
 *@arc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
typedef struct passinfo
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

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* string1.c */
int my_strlen(char *);
int my_strcmp(char *, char *);
char *mystrats_with(const char *, const char *);
char *my_strcat(char *, char *);

/* string2.c */
char *my_strcpy(char *, char *);
char *my_strdup(const char *);
void my_puts(char *);
int my_putchar(char);

/* string3.c */
char *my_strncpy(char *, char *, int);
char *my_strncat(char *, char *, int);
char *my_strchr(char *, char);

/* string4.c */
char **firststrtow(char *, char *);
char **secondstrtow(char *, char);

/* memoryfuc1.c */
char *my_memset(char *, char, unsigned int);
void myfree(char **);
void *my_realloc(void *, unsigned int, unsigned int);

/* memoryfuc2.c */
int afree(void **);

/* morefuc1.c */
int interactivemode (info_t *);
int my_delim(char, char *);
int my_alpha(int);
int my_atoi(char *);

/* morefuc2.c */
int my_erratoi1(char *);
void prt_error1(info_t *,char *);
int prt_d1(int, int);
char *cnv_number(long int, int, int);
void rmv_comments(char *);

/* list.c */
list_t *myadd_node1(list_t **, const char *, int);
list_t *myadd_node1_end(list_t **, const char *, int);
size_t print_ls_str(const list_t *);
int dlt_node1_in_index(list_t **, unsigned int);
void free_list1(list_t **);

/* list2.c */
size_t list1len(const list_t *);
char **list1_str(list_t *);
size_t print_ls1(const list_t *);
list_t *node1_starts(list_t *, char *, char);
ssize_t get_node1(list_t *, list_t *);
/* my error */
void rputs(char *);
int f_putchar(char);
int put_fd(char d, int myfd);
int puts_fd(char *str, int myfd);

/* my info */
void clear1_myinfo1(info_t *);
void set1_myinfo1(info_t *, char **);
void free1_myinfo1(info_t *, int);

/* my env */
char *get_env(info_t *, const char *);
int env(info_t *);
int set_env(info_t *);
int remove_setenv(info_t *);
int populate1_env_ls1(info_t *);

/* my env2 */
char **_getmyenv(info_t *);
int dlt_setenv(info_t *, char *);
int set_myenv(info_t *, char *, char *);

/* file_io_functions.c */
char *get_myhistoryfile(info_t *myinfo);
int write_myhistory(info_t *myinfo);
int read_myhistory(info_t *myinfo);
int build_myhistoryls(info_t *myinfo, char *buf, int mylinecount);
int refresh_sequence_numbers(info_t *myinfo);

/*  builtin 1 */
int my_exit1(info_t *);
int my_cd1(info_t *);
int my_help1(info_t *);

/* builtin 2 */
int my_history1(info_t *);
int my_alias(info_t *); 
int get_node1_index(list_t *list, int index);
int unset_alias(info_t *myinfo, char *str);

/* path.c */
int my_cmd(info_t *, char *);
char *dupli_mychars(char *, int, int);
char *find_mypath(info_t *, char *, char *);
/* mychain */
int my_chain(info_t *, char *, size_t *);
void checkk_mychain(info_t *, char *, size_t *, size_t, size_t);
int replace_myalias(info_t *);
int replace_str(char **, char *);
int rplc_myvars(info_t *);

/* mygetline */
ssize_t _get_input(info_t *);
int get_myline(info_t *, char **, size_t *);
void sigintHandler(int);
/* hsh.c*/
int _hsh(info_t *, char **);
int find_the_builtin(info_t *);
void find_the_cmd(info_t *);
void fork_the_cmd(info_t *);

#endif
