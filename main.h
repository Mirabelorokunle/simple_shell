#ifndef _MAINE_H_
#define _MAINE_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/* Points to an array of pointers to strings called the "environment" */
extern char **environ;


/**
 * struct data - struct that contains all relevant data on runtime
 * @av: argument vector
 * @input: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @dtenviron: environment variable
 * @pid: process ID of the shell
 */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **dtenviron;
	char *pid;
} dataSHLL;

/**
 * struct strct_list_real - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct strct_list_real
{
	char separator;
	struct strct_list_real *next;
} strctList;

/**
 * struct srtctLine_strcture - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct srtctLine_strcture
{
	char *line;
	struct srtctLine_strcture *next;
} srtctLine;

/**
 * struct i_varList - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct i_varList
{
	int len_var;
	char *val;
	int len_val;
	struct i_varList *next;
} strct_var;

/**
 * struct builtin_strct - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct builtin_strct
{
	char *name;
	int (*f)(dataSHLL *datash);
} builtin_cmds;

/* ................................ START................................*/

/**
 * struct atoistruct - struct
 * @cntst: argument
 * @szst: command
 */
struct atoistruct
{
	unsigned int cntst;
	unsigned int szst;
};
typedef struct atoistruct atoitype;


int theAtoi(char *s);
atoitype theAtoiDaf_count(char *s, unsigned int count, unsigned int size,
					unsigned int pn, unsigned int m);
void authenticate_asst_Ext(void);
void authenticate_asst_ExtDaf(char *hlp);
void authenticator_asst(void);
void authenticator_asstDaf(char *hlp);
void authenticator_asst_alias(void);
void authenticator_asst_aliasDaf(char *hlp);
int error_separator_OP(char *input, int i, char last);
int error_separator_OPDaf(char *input, int i, char last, int count, int chk);
void dis_stx_error(dataSHLL *datash, char *input, int i, int bool);
char *dis_stx_errorDaf(char *input, int i, int chk);
int confirm_stx_error(dataSHLL *datash, char *input);
void empty_dif_list(strctList **head);
void free_strct_list_MemDaf(strctList *temp);
void empty_LiN_list(srtctLine **head);
void free_srtctLine_MemDaf(srtctLine *temp);
void emptY_Revar_list(strct_var **head);
void free_strct_variable_MemDaf(strct_var *temp);
srtctLine *include_LN_node_extr(srtctLine **head, char *line);
strct_var *include_Revar_node(strct_var **head,
		int lvar, char *var, int lval);
int test_CurrentDir(char *path, int *i);
int test_CurrentDirDaf(int *i);
char *locteOrigCmd(char *cmd, char **dtenviron);
int test_executionee(dataSHLL *datash);
int confirm_for_error(char *dir, dataSHLL *datash);
int for_command_execution(dataSHLL *datash);
int environ_ident(const char *nenv, const char *name);
char *getenviron(const char *name, char **dtenviron);
int shEnv(dataSHLL *datash);
void prepareEnvron(char *name, char *value, dataSHLL *datash);
int setenviron(dataSHLL *datash);
int unsetenviron(dataSHLL *datash);
int unsetenvironDaf(dataSHLL *datash, char *varshEnv,
					char *nameshEnv, int i, int k);
void confirmdtenvironmente(strct_var **h, char *in, dataSHLL *data);
int confirm_variable(strct_var **h, char *in, char *st, dataSHLL *data);
char *rest_input(strct_var **head, char *input,
		char *new_input, int nlen);
char *rest_variable(char *input, dataSHLL *datash);
char *remove_command(char *in);
void aut_asst_current_dir(void);
void aut_asst_current_dirDaf(char *hlp);
char *autIToAlph(int n);
strctList *inc_dif_node_extr(strctList **head, char sep);
void memorycopy(void *newptr, const void *ptr, unsigned int size);
char *stringtok(char str[], const char *delim);
int is_digitFunc(const char *s);
int (*getBuiltinFunc(char *cmd))(dataSHLL *datash);
int getErr(dataSHLL *datash, int eval);
int getAsst2(dataSHLL *datash);
void showLine(char **lineptr, size_t *n, char *buffer, size_t j);
void showLineDaf(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t getLine3(char **lineptr, size_t *n, FILE *stream);
char *scanLine(int *i_eof);
void fetchSig(int sig);
char *errorMissing(dataSHLL *datash);
char *error_extShell(dataSHLL *datash);
char *errordtenvironMsg(dataSHLL *datash);
char *errRD126(dataSHLL *datash);
void SH_loop(dataSHLL *datash);
char *exchChar(char *input, int bool);
char *exchCharDaf(char *input, int i, int chk);
char *exchCharDafNest(char *input, int i, int chkgn);
void undoStrRev(char *s);
void undoStrRevDaf(int i, int j, char *str, char temp);
void undoStrRevDafNest(int j, char *str, char temp);
void change_dirFtp(dataSHLL *datash);
void change_dirLoc(dataSHLL *datash);
void change_dir_last(dataSHLL *datash);
void change_dirLoc_2(dataSHLL *datash);
int change_dirSH(dataSHLL *datash);
int duplicateChar(char *input, int i);
int baseChar(char *input, int *i);
void *my_realloc(void *ptr, unsigned int old_size,
		unsigned int new_size);
char **my_realloc_hdp(char **ptr, unsigned int old_size,
		unsigned int new_size);
int fetch_lengthe(int n);
void include_nodes(strctList **head_s, srtctLine **head_l,
		char *input);
void next_command_arg(strctList **list_s, srtctLine **list_l,
		dataSHLL *datash);
int separate_command_args(dataSHLL *datash, char *input);
int executecute_line(dataSHLL *datash);
char *m_detail(char *name, char *value);
int quit_shell_op(dataSHLL *datash);
char *strcartenate_current_dir(dataSHLL *, char *, char *, char *);
char *error_getcurrent_dir(dataSHLL *datash);
char *print_message(char option);
void aut_asstantEnvirone(void);
void aut_asstantEnvironeDaf(char *hlp);
void aut_asstsetenvironee(void);
void aut_asstsetenvironeeDaf(char *hlp);
void aut_asstunsetenvironddd(void);
void aut_asstunsetenvirondddDaf(char *hlp);
void autAsstantGeneral(void);
void autAsstantGeneralDaf(char *hlp);
char *stringConcate(char *dest, const char *src);
char *stringCopy(char *dest, char *src);
int stringcompr(char *s1, char *s2);
char *string_locateCharacter(char *s, char c);
int string_substr_pref_len(char *s, char *accept);
char *_strdup(const char *s);
int string_length(const char *s);
int compare_chars(char str[], const char *delim);
char **separate_line(char *input);
void dis_stx_errorDafIn2(dataSHLL *datshell, char *msges, char *msges2,
					char *msges3, int length, char *counter);
void dis_stx_errorDafIn(dataSHLL *datshell, char *msges, char *msges2,
					char *msges3, char *error, char *counter);


void freeIntMemDaf(int *temp);
void freeCharMemDaf(char *temp);
void change_dirLastarg(dataSHLL *datshell);
/* ....................... NEW.......................*/
char string_charDaf(char *dest, const char *src, int i, int j);
void prntcmtz(int chk);
int exchangeRetInt(int chk);
unsigned int autRespDaf(int n, int chk);
/* ....................... NEW.......................*/



#endif
