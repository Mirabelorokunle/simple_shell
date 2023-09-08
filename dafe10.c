#include "main.h"

/**
 * for_command_execution - executes
 *
 * @datshell: data
 * Return: 1
 */

int for_command_execution(dataSHLL *datshell)
{
	pid_t pd, wpy;
	int stt, exc;
	char *dir;
	(void)wpy;

	exc = test_executionee(datshell);
	if (exc == -1)
		return (1);
	if (exc == 0)
	{
		dir = locteOrigCmd(datshell->args[0], datshell->dtenviron);
		if (confirm_for_error(dir, datshell) == 1)
			return (1);
	}
	pd = fork();
	if (pd == 0)
	{
		if (exc == 0)
			dir = locteOrigCmd(datshell->args[0], datshell->dtenviron);
		else
			dir = datshell->args[0];
		execve(dir + exc, datshell->args, datshell->dtenviron);
	}
	else if (pd < 0)
	{
		perror(datshell->av[0]);
		return (1);
	}
	else
	{
		do {
			wpy = waitpid(pd, &stt, WUNTRACED);
		} while (!WIFEXITED(stt) && !WIFSIGNALED(stt));
	}
	datshell->status = stt / 256;
	return (1);
}

/**
 * unsetenviron - deletes
 *
 * @datshell: data
 *
 * Return: 1
 */

int unsetenviron(dataSHLL *datshell)
{
	char **reallocdten, *varenD, *nameec;
	int i, j, k, l;

	if (datshell->args[1] == NULL)
	{
		getErr(datshell, -1);
		return (1);
	}
	k = l = -1;
	for (i = 0; datshell->dtenviron[i]; i++)
	{
		varenD = nameec = NULL;
		k = unsetenvironDaf(datshell, varenD, nameec, i, l);
	}
	if (k == -1)
	{
		getErr(datshell, -1);
		return (1);
	}
	reallocdten = malloc(sizeof(char *) * (i));
	for (i = j = 0; datshell->dtenviron[i]; i++)
	{
		if (i != k)
		{
			reallocdten[j] = datshell->dtenviron[i];
			j++;
		}
	}
	reallocdten[j] = NULL;
	free(datshell->dtenviron[k]);
	free(datshell->dtenviron);
	datshell->dtenviron = reallocdten;
	return (1);
}

/* .........................NUM 12 BTW.........................*/
/**
 * unsetenvironDaf - delete
 * @datshell: data
 * @varenD: data
 * @nameec: data
 * @i: data
 * @k: data
 * Return: 1 on success.
 */

int unsetenvironDaf(dataSHLL *datshell, char *varenD, char *nameec,
		    int i, int k)
{
	varenD = _strdup(datshell->dtenviron[i]);
	nameec = stringtok(varenD, "=");
	if (stringcompr(nameec, datshell->args[1]) == 0)
	{
		k = i;
	}
	freeCharMemDaf(varenD);

	return (k);
}

/* .........................NUM 17 START.......................*/
/**
 * aut_asst_current_dir - Hlp
 */

void aut_asst_current_dir(void)
{
	char *hlp = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	aut_asst_current_dirDaf(hlp);
}

/* .........................NUM 17 BTW.........................*/
/**
 * aut_asst_current_dirDaf - Hlp
 * @hlp: str
 */

void aut_asst_current_dirDaf(char *hlp)
{
	write(STDOUT_FILENO, hlp, string_length(hlp));
	hlp = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, hlp, string_length(hlp));
}

/*..................jjjjj............................*/

