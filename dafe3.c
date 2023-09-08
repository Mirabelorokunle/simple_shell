#include "main.h"

/* .........................NUM 5 BTW...........................*/
/**
 * error_separator_OPDaf - finds
 *
 * @input: input
 * @i: index
 * @lastarg: lastarg
 * @count: lastarg
 * @chkn: lastarg
 * Return: index
 */
int error_separator_OPDaf(char *input, int i, char lastarg,
							int count, int chkn)
{
	int a = 0, b = 0, c;

	if (chkn == 1)
	{
		if (lastarg == ';' || lastarg == '&')
			return (i);

		if (lastarg == '|')
		{
			count = duplicateChar(input, 0);
			if (count == 0 || count > 1)
				a = 4;
		}
	}

	else
	{
		if (lastarg == ';' || lastarg == '|')
			return (i);

		if (lastarg == '&')
		{
			count = duplicateChar(input, 0);
			if (count == 0 || count > 1)
				b = 8;
		}
	}
	c = a + b;
	c = i;
	return (c);
}

/* .........................NUM 5 END...........................*/

/*..................ccccc............................*/



/* .........................NUM 6 START.........................*/
/**
 * dis_stx_error - prints
 * @datshell: data
 * @input: input
 * @i: data
 * @bool: input
 */
void dis_stx_error(dataSHLL *datshell, char *input, int i, int bool)
{
	char *msges = NULL, *msges_two = NULL, *msges_three = NULL,
			*error, *counter = NULL;
	int length = 0, chkn;

	if (input[i] == ';')
	{
		if (bool == 0)
		{
			chkn = 1;
			dis_stx_errorDaf(input, i, chkn);
		}
		else
		{
			chkn = 2;
			dis_stx_errorDaf(input, i, chkn);
		}
	}
	if (input[i] == '|')
	{
		chkn = 3;
		dis_stx_errorDaf(input, i, chkn);
	}
	if (input[i] == '&')
	{
		chkn = 4;
		dis_stx_errorDaf(input, i, chkn);
	}
	dis_stx_errorDafIn2(datshell, msges, msges_two,
					msges_three, length, counter);
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		freeCharMemDaf(counter);
		return;
	}
	dis_stx_errorDafIn(datshell, msges, msges_two,
					msges_three, error, counter);
	write(STDERR_FILENO, error, length);
	freeCharMemDaf(error);
	freeCharMemDaf(counter);
}

/* .........................NUM 6 BTW...........................*/
/**
 * dis_stx_errorDafIn2 - prints
 * @datshell: data
 * @msges: input
 * @msges_two: data
 * @msges_three: input
 * @length: data
 * @counter: input
 */
void dis_stx_errorDafIn2(dataSHLL *datshell, char *msges, char *msges_two,
					char *msges_three, int length, char *counter)
{
	msges_two = print_message('s');
	msges_three = print_message('u');
	counter = autIToAlph(datshell->counter);
	length = string_length(datshell->av[0]) + string_length(counter);
	length += string_length(msges) + string_length(msges_two)
					+ string_length(msges_three) + 2;
}
