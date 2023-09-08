#include "main.h"

/**
 * error_extShell - generic
 * @datshell: data
 *
 * Return: Error
 */

char *error_extShell(dataSHLL *datshell)
{
	int length;
	char *error;
	char *verStrC;

	verStrC = autIToAlph(datshell->counter);
	length = string_length(datshell->av[0]) + string_length(verStrC);
	length += string_length(datshell->args[0])
				+ string_length(datshell->args[1]) + 23;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		freeCharMemDaf(verStrC);
		return (NULL);
	}
	stringCopy(error, datshell->av[0]);
	stringConcate(error, ": ");
	stringConcate(error, verStrC);
	stringConcate(error, ": ");
	stringConcate(error, datshell->args[0]);
	stringConcate(error, ": Illegal number: ");
	stringConcate(error, datshell->args[1]);
	stringConcate(error, "\n\0");
	freeCharMemDaf(verStrC);

	return (error);
}

/*..................22222............................*/



/**
 * errordtenvironMsg - error
 * @datshell: data
 * Return: error
 */

char *errordtenvironMsg(dataSHLL *datshell)
{
	int length;
	char *error;
	char *verStrC;
	char *msges;

	verStrC = autIToAlph(datshell->counter);
	msges = ": Unable to add/remove from environment\n";
	length = string_length(datshell->av[0]) + string_length(verStrC);
	length += string_length(datshell->args[0]) + string_length(msges) + 4;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		freeCharMemDaf(error);
		freeCharMemDaf(verStrC);
		return (NULL);
	}

	stringCopy(error, datshell->av[0]);
	stringConcate(error, ": ");
	stringConcate(error, verStrC);
	stringConcate(error, ": ");
	stringConcate(error, datshell->args[0]);
	stringConcate(error, msges);
	stringConcate(error, "\0");
	free(verStrC);

	return (error);
}

/**
 * errRD126 - error
 * @datshell: data
 *
 * Return: The
 */

char *errRD126(dataSHLL *datshell)
{
	int length;
	char *verStrC;
	char *error;

	verStrC = autIToAlph(datshell->counter);
	length = string_length(datshell->av[0]) + string_length(verStrC);
	length += string_length(datshell->args[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		freeCharMemDaf(error);
		freeCharMemDaf(verStrC);
		return (NULL);
	}
	stringCopy(error, datshell->av[0]);
	stringConcate(error, ": ");
	stringConcate(error, verStrC);
	stringConcate(error, ": ");
	stringConcate(error, datshell->args[0]);
	stringConcate(error, ": Permission denied\n");
	stringConcate(error, "\0");
	freeCharMemDaf(verStrC);
	return (error);
}

/**
 * SH_loop - Loop
 * @datshell: data
 */

void SH_loop(dataSHLL *datshell)
{
	int loop, i_eof;
	char *input;

	loop = 1;
	while (loop == 1)
	{
		prntcmtz(2);
		input = scanLine(&i_eof);
		if (i_eof != -1)
		{
			input = remove_command(input);
			if (input == NULL)
				continue;

			if (confirm_stx_error(datshell, input) == 1)
			{
				datshell->status = 2;
				freeCharMemDaf(input);
				continue;
			}
			input = rest_variable(input, datshell);
			loop = separate_command_args(datshell, input);
			datshell->counter += 1;
			freeCharMemDaf(input);
		}
		else
		{
			loop = 0;
			freeCharMemDaf(input);
		}
	}
}

/* .........................NUM 14 START.......................*/

/**
 * exchChar - swaps
 *
 * @input: inpu
 * @bool: type
 * Return: swapped
 */

char *exchChar(char *input, int bool)
{
	int i = 0, chkn;

	if (bool == 0)
	{
		chkn = 1;
		input = exchCharDaf(input, i, chkn);
	}
	else
	{
		chkn = 2;
		input = exchCharDaf(input, i, chkn);
	}
	return (input);
}
