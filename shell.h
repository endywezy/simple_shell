#ifndef SHELL_H
#define SHELL_H

#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>


/* to read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* to command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* to convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if system is using getline() */
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
 *struct passinfo - has make-pretend arguments for push inside a function
 *allowing uniform prototype for function pointer struct
 *@arg: a bunch of words made from getline with arguments
 *@argv: array of word strings made from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if turned on, count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: special changed copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the result status of last cmd that was executed
 *@cmd_buf: where pointer to cmd_buf is, if chaining is on
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd where line input is read from
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

/* endy_test_betty.c */
void printMessage(void);
int custom_main(void);
void __putchar(char c);

/* endy_history_instruct.c   */
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);

/* endy_parser_instruct.c */
char *find_path(info_t *, char *, char *);
char *dup_chars(char *, int, int);
int is_cmd(info_t *, char *);

/* endy_variable_envruntime.c */
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

/* endy_reader_envruntime.c */
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/* endy_err_controller.c */
int _eputchar(char);
int _putsfd(char *str, int fd);
void _eputs(char *);
int _putfd(char c, int fd);

/* endy_da_shelliterationloops.c */
int find_builtin(info_t *);
void find_cmd(info_t *);
int hsh(info_t *, char **);
void fork_cmd(info_t *);

/* endy_stringservice_utilities.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* endy_loophsh.c */
int loophsh(char **);

/* endy_stringmodifier.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* endy_customtokenizingfunction.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* endy_exit_endfunction.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* endy_num_valueconverter.c */
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* endy_extradynamicmomery.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* endy_memorymanager.c */
int bfree(void **);

/* endy_errservice_utilities.c */
int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* endy_da_shellinstructutilities.c */
int _myhistory(info_t *);
int _myalias(info_t *);

/* endy_da_shellinstrust.c */
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

/* endy_inputsourcereader.c */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);
/* endy_inforetriever.c */
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

/* endy_referlist.c*/
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* endy_listHelper.c */
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* endy_varmanager*/
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

/* endy_moreFunctions 
static int copy_word(char *str, int i, char *d, char **s);
static char **allocate_strings(int numwords);
static int count_words(char *str, char d);*/

/*Renamed*/
int free_and_null(void **ptr);
/*Main.c
void initialize_info(info_t *info);
int process_file_arguments(info_t *info, char *filename, int ac, char **av);
void setup_shell_environment(info_t *info);
int main(int ac, char **av);*/

#endif /*shell_h */
