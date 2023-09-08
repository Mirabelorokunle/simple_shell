#include "main.h"

/**
 * getBuiltinFunc - builtin
 * @cmd: command
 * Return: function
 */

int (*getBuiltinFunc(char *cmd))(dataSHLL *)
{
	builtin_cmds builtin[] = {
	    {"env", shEnv},
	    {"exit", quit_shell_op},
	    {"setenv", setenviron},
	    {"unsetenv", unsetenviron},
	    {"cd", change_dirSH},
	    {"hlp", getAsst2},
	    {NULL, NULL}};
	int i;

	for (i = 0; builtin[i].name; i++)
	{
		if (stringcompr(builtin[i].name, cmd) == 0)
			break;
	}
	return (builtin[i].f);
}

/**
 * getErr - calls
 * @datshell: data
 * @eval: error
 * Return: error
 */

int getErr(dataSHLL *datshell, int eval)
{
	char *error;

	switch (eval)
	{
	case -1:
		error = errordtenvironMsg(datshell);
		break;
	case 126:
		error = errRD126(datshell);
		break;
	case 127:
		error = errorMissing(datshell);
		break;
	case 2:
		if (stringcompr("exit", datshell->args[0]) == 0)
			error = error_extShell(datshell);
		else if (stringcompr("cd", datshell->args[0]) == 0)
			error = error_getcurrent_dir(datshell);
		break;
	}
	if (error)
	{
		write(STDERR_FILENO, error, string_length(error));
		free(error);
	}
	datshell->status = eval;
	return (eval);
}

/**
 * getAsst2 - function
 * @datshell: dat
 * Return: Return 0
 */

int getAsst2(dataSHLL *datshell)
{
	if (datshell->args[1] == 0)
		autAsstantGeneral();
	else if (stringcompr(datshell->args[1], "setenv") == 0)
		aut_asstsetenvironee();
	else if (stringcompr(datshell->args[1], "env") == 0)
		aut_asstantEnvirone();
	else if (stringcompr(datshell->args[1], "unsetenv") == 0)
		aut_asstunsetenvironddd();
	else if (stringcompr(datshell->args[1], "hlp") == 0)
		authenticator_asst();
	else if (stringcompr(datshell->args[1], "exit") == 0)
		authenticate_asst_Ext();
	else if (stringcompr(datshell->args[1], "cd") == 0)
		aut_asst_current_dir();
	else if (stringcompr(datshell->args[1], "alias") == 0)
		authenticator_asst_alias();
	else
		write(STDERR_FILENO, datshell->args[0],
		      string_length(datshell->args[0]));

	datshell->status = 0;
	return (1);
}

/* .........................NUM 13 START.......................*/

/**
 * showLine - assigns
 * @lneptr1: Buffer
 * @buffer: str that
 * @n: size
 * @j: size
 */
void showLine(char **lneptr1, size_t *n, char *buffer, size_t j)
{
	if (*lneptr1 == NULL)
	{
		showLineDaf(lneptr1, n, buffer, j);
	}
	else if (*n < j)
	{
		showLineDaf(lneptr1, n, buffer, j);
	}
	else
	{
		stringCopy(*lneptr1, buffer);
		free(buffer);
	}
}

/* .........................NUM 13 BTW.........................*/

/**
 * showLineDaf - assigns
 * @lneptr1: Buffer
 * @buffer: str
 * @n: size
 * @j: size
 */
void showLineDaf(char **lneptr1, size_t *n, char *buffer, size_t j)
{
	if (j > BUFSIZE)
		*n = j;

	else
		*n = BUFSIZE;
	*lneptr1 = buffer;
}
