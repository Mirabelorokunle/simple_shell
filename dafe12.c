#include "main.h"

/**
 * errorMissing - generic
 * @datshell: data
 * Return: Error
 */

char *errorMissing(dataSHLL *datshell)
{
	int length;
	char *error, *verStrC;

	verStrC = autIToAlph(datshell->counter);
	length = string_length(datshell->av[0]) + string_length(verStrC);
	length += string_length(datshell->args[0]) + 16;
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
	stringConcate(error, ": not found\n");
	stringConcate(error, "\0");
	freeCharMemDaf(verStrC);
	return (error);
}

/**
 * theAtoiDaf_count - struct
 * @s: input
 * @count: input
 * @size: input
 * @pn: input
 * @m: input
 * Return: structure
 */
atoitype theAtoiDaf_count(char *s, unsigned int count, unsigned int size,
			 unsigned int pn, unsigned int m)
{
	atoitype cnt;

	cnt.cntst = count;
	cnt.szst = size;

	while (*(s + cnt.cntst) != '\0')
	{
		if (cnt.szst > 0 && (*(s + cnt.cntst) < '0' || *(s + cnt.cntst) > '9'))
			break;

		if (*(s + cnt.cntst) == '-')
			pn *= -1;

		if ((*(s + cnt.cntst) >= '0') && (*(s + cnt.cntst) <= '9'))
		{
			if (cnt.szst > 0)
				m *= 10;
			cnt.szst++;
		}
		cnt.cntst++;
	}
	return (cnt);
}

/* .........................NUM 1 END...........................*/

/* .........................NUM 2 START.........................*/

/**
 * authenticate_asst_Ext - Hlp
 */
void authenticate_asst_Ext(void)
{
	char *hlp = "exit: exit [n]\n Exit shell.\n";

	authenticate_asst_ExtDaf(hlp);
}

/* .........................NUM 16 BTW.........................*/
/**
 * print_message - error
 * @option: data
 * Return: Error
 */

char *print_message(char option)
{
	char *msges;

	if (option == 'i')
		msges = ": Invalid option ";
	else if (option == 'c')
		msges = ": can't cd to ";
	else if (option == 's')
		msges = ": Syntax error: \" ";
	else if (option == 'u')
		msges = "\" unexpected\n";
	return (msges);
}

/* .........................NUM 16 END.........................*/


