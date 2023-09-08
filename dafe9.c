#include "main.h"

/**
 * authenticator_asst_aliasDaf - Hlp
 *  * @hlp: lastarg
 */

void authenticator_asst_aliasDaf(char *hlp)
{
	write(STDOUT_FILENO, hlp, string_length(hlp));
	hlp = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, hlp, string_length(hlp));
}

/* .........................NUM 4 END...........................*/


/* .........................NUM 5 START.........................*/

/**
 * error_separator_OP - finds
 *
 * @input: input
 * @i: index
 * @lastarg: lastarg
 * Return: index
 */
int error_separator_OP(char *input, int i, char lastarg)
{
	int count, chkn, ret;

	count = 0;
	if (*input == '\0')
		return (0);

	if (*input == ' ' || *input == '\t')
	{
		ret = error_separator_OP(input + 1, i + 1, lastarg);
		return (ret);
	}

	if (*input == ';')
		if (lastarg == '|' || lastarg == '&' || lastarg == ';')
			return (i);

	if (*input == '|')
	{
		chkn = 1;
		ret = error_separator_OPDaf(input, i, lastarg, count, chkn);
		return (ret);
	}

	if (*input == '&')
	{
		chkn = 2;
		ret = error_separator_OPDaf(input, i, lastarg, count, chkn);
		return (ret);
	}
	ret = error_separator_OP(input + 1, i + 1, *input);

	return (ret);
}

/**
 * empty_LiN_list - free
 * @head: head
 */

void empty_LiN_list(srtctLine **head)
{
	srtctLine *temp;
	srtctLine *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free_srtctLine_MemDaf(temp);
		}
		*head = NULL;
	}
}

/**
 * test_CurrentDir - checks
 * @path: type
 * @i: type
 * Return: 1
 */

int test_CurrentDir(char *path, int *i)
{
	if (path[*i] == ':')
		return (1);

	while (path[*i] != ':' && path[*i])
	{
		test_CurrentDirDaf(i);
	}

	if (path[*i])
		test_CurrentDirDaf(i);

	return (0);
}
/* .........................NUM 10 BTW.........................*/

/**
 * test_CurrentDirDaf - checks
 * @i: type
 * Return: 1
 */

int test_CurrentDirDaf(int *i)
{
	*i += 1;
	return (*i);
}
/* .........................NUM 10 END.........................*/

/*..................fffff............................*/
