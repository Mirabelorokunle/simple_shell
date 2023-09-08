#include "main.h"

/* .........................NUM 11 START.......................*/
/**
 * locteOrigCmd - locates
 *
 * @cmd: command
 * @dtenviron: environment
 * Return: location
 */

char *locteOrigCmd(char *cmd, char **dtenviron)
{
	char *path, *ptrPth, *tknPth, *dir;
	int len_dir, cmdLen, i;
	struct stat st;

	path = getenviron("PATH", dtenviron);
	if (path)
	{
		ptrPth = _strdup(path);
		cmdLen = string_length(cmd);
		tknPth = stringtok(ptrPth, ":");
		i = 0;
		while (tknPth != NULL)
		{
			if (test_CurrentDir(path, &i))
				if (stat(cmd, &st) == 0)
					return (cmd);
			len_dir = string_length(tknPth);
			dir = malloc(len_dir + cmdLen + 2);
			stringCopy(dir, tknPth);
			stringConcate(dir, "/");
			stringConcate(dir, cmd);
			stringConcate(dir, "\0");
			if (stat(dir, &st) == 0)
			{
				freeCharMemDaf(ptrPth);
				return (dir);
			}
			freeCharMemDaf(dir);
			tknPth = stringtok(NULL, ":");
		}
		freeCharMemDaf(ptrPth);
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/')
		if (stat(cmd, &st) == 0)
			return (cmd);
	return (NULL);
}

/* .........................NUM 11 BTW.........................*/
/**
 * freeCharMemDaf - frees
 * @temp: head
 */

void freeCharMemDaf(char *temp)
{
	free(temp);
}

/* .........................NUM 11 BTW.........................*/
/**
 * freeIntMemDaf - frees
 * @temp: head of the linked list.
 */

void freeIntMemDaf(int *temp)
{
	free(temp);
}

/* .........................NUM 11 END.........................*/

/**
 * test_executionee - determines
 *
 * @datshell: data
 * Return: 0
 */

int test_executionee(dataSHLL *datshell)
{
	struct stat st;
	int i;
	char *input;

	input = datshell->args[0];
	for (i = 0; input[i]; i++)
	{
		if (input[i] == '.')
		{
			if (input[i + 1] == '.')
				return (0);
			if (input[i + 1] == '/')
				continue;
			else
				break;
		}
		else if (input[i] == '/' && i != 0)
		{
			if (input[i + 1] == '.')
				continue;
			i++;
			break;
		}
		else
			break;
	}
	if (i == 0)
		return (0);
	if (stat(input + i, &st) == 0)
	{
		return (i);
	}
	getErr(datshell, 127);
	return (-1);
}

/**
 * confirm_for_error - verifies
 *
 * @dir: destinatio
 * @datshell: data
 * Return: 1
 */
int confirm_for_error(char *dir, dataSHLL *datshell)
{
	if (dir == NULL)
	{
		getErr(datshell, 127);
		return (1);
	}
	if (stringcompr(datshell->args[0], dir) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			getErr(datshell, 126);
			freeCharMemDaf(dir);
			return (1);
		}
		freeCharMemDaf(dir);
	}
	else
	{
		if (access(datshell->args[0], X_OK) == -1)
		{
			getErr(datshell, 126);
			return (1);
		}
	}
	return (0);
}

/*..................ggggg............................*/



