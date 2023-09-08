#include "main.h"

/* .........................NUM 14 BTW.........................*/

/**
 * exchCharDaf - swaps
 *
 * @input: input
 * @i: type
 * @chkn: type
 * Return: swapped
 */

char *exchCharDaf(char *input, int i, int chkn)
{
	int chkngn;

	if (chkn == 1)
	{
		for (i = 0; input[i]; i++)
		{
			if (input[i] == '|')
			{
				chkngn = 1;
				input = exchCharDafNest(input, i, chkngn);
			}
			if (input[i] == '&')
			{
				chkngn = 2;
				input = exchCharDafNest(input, i, chkngn);
			}
		}
	}
	else
	{
		for (i = 0; input[i]; i++)
		{
			chkngn = 3;
			input = exchCharDafNest(input, i, chkngn);
		}
	}
	return (input);
}

/* .........................NUM 14 BTW.........................*/

/*..................33333............................*/



/**
 * exchCharDafNest - swaps
 *
 * @input: inpu
 * @i: type
 * @chkngn: type
 * Return: swapped
 */

char *exchCharDafNest(char *input, int i, int chkngn)
{
	if (chkngn == 1)
	{
		if (input[i + 1] != '|')
			input[i] = exchangeRetInt(1);
		else
			i++;
	}
	else if (chkngn == 2)
	{
		if (input[i + 1] != '&')
			input[i] = exchangeRetInt(2);
		else
			i++;
	}
	else
	{
		input[i] = (input[i] == 16 ? '|' : input[i]);
		input[i] = (input[i] == 12 ? '&' : input[i]);
	}
	return (input);
}

/* ......................... NEW.........................*/
/**
 * exchangeRetInt - swaps
 * @chkn: type
 * Return: swapped
 */

int exchangeRetInt(int chkn)
{
	if (chkn == 1)
		return (16);
	else
		return (12);
}
/* ......................... NEW.........................*/

/* .........................NUM 14 END.........................*/

/* .........................NUM 15 START.......................*/

/**
 * undoStrRev - reverses
 * @s: input
 */

void undoStrRev(char *s)
{
	int count = 0, i, j = 0;
	char *str, temp = 'A';

	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}
	str = s;

	for (i = 0; i < (count - 1); i++)
	{
		undoStrRevDaf(i, j, str, temp);
	}
}

/* .........................NUM 15 BTW.........................*/

/**
 * undoStrRevDaf - reverses
 * @i: input
 * @j: input
 * @str: input
 * @temp: input
 */

void undoStrRevDaf(int i, int j, char *str, char temp)
{
	for (j = i + 1; j > 0; j--)
	{
		undoStrRevDafNest(j, str, temp);
	}
}

/* .........................NUM 15 BTW.........................*/


