#include "main.h"

/**
 * strcartenate_current_dir - function
 * @datshell: data
 * @msges: message
 * @error: output
 * @verStrC: counter
 * Return: error
 */

char *strcartenate_current_dir(dataSHLL *datshell, char *msges,
								char *error, char *verStrC)
{
	char *ill_flag;

	stringCopy(error, datshell->av[0]);
	stringConcate(error, ": ");
	stringConcate(error, verStrC);
	stringConcate(error, ": ");
	stringConcate(error, datshell->args[0]);
	stringConcate(error, msges);
	if (datshell->args[1][0] == '-')
	{
		ill_flag = malloc(3);
		ill_flag[0] = '-';
		ill_flag[1] = datshell->args[1][1];
		ill_flag[2] = '\0';
		stringConcate(error, ill_flag);
		freeCharMemDaf(ill_flag);
	}
	else
	{
		stringConcate(error, datshell->args[1]);
	}

	stringConcate(error, "\n");
	stringConcate(error, "\0");
	return (error);
}

/* .........................NUM 16 START.......................*/

/**
 * error_getcurrent_dir - error
 * @datshell: data
 * Return: Error
 */

char *error_getcurrent_dir(dataSHLL *datshell)
{
	int length, len_id1;
	char *error, *verStrC, *msges;

	verStrC = autIToAlph(datshell->counter);
	if (datshell->args[1][0] == '-')
	{
		msges = print_message('i');
		len_id1 = 2;
	}
	else
	{
		msges = print_message('c');
		len_id1 = string_length(datshell->args[1]);
	}

	length = string_length(datshell->av[0]) + string_length(datshell->args[0]);
	length += string_length(verStrC) + string_length(msges) + len_id1 + 5;
	error = malloc(sizeof(char) * (length + 1));

	if (error == 0)
	{
		freeCharMemDaf(verStrC);
		return (NULL);
	}

	error = strcartenate_current_dir(datshell, msges, error, verStrC);

	freeCharMemDaf(verStrC);

	return (error);
}

