#include "main.h"

/**
 * string_locateCharacter - locates
 * @s: string
 * @c: character
 * Return: th
 */

char *string_locateCharacter(char *s, char c)
{
	unsigned int i = 0;

	for (; *(s + i) != '\0'; i++)
		if (*(s + i) == c)
			return (s + i);
	if (*(s + i) == c)
		return (s + i);
	return ('\0');
}

/*..................aaaaa............................*/



/* .........................NUM 13 END.........................*/

/**
 * scanLine - reads
 *
 * @i_eof: return
 * Return: input
 */

char *scanLine(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);
	return (input);
}

/**
 * getLine3 - Read
 * @lneptr1: buffer
 * @n: size
 * @stream: stream
 * Return: The
 */

ssize_t getLine3(char **lneptr1, size_t *n, FILE *stream)
{
	int i;
	static ssize_t input;
	ssize_t retVal;
	char *buffer, t = 'z';

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * BUFSIZE);
	if (buffer == 0)
		return (-1);
	while (t != '\n')
	{
		i = read(STDIN_FILENO, &t, 1);
		if (i == -1 || (i == 0 && input == 0))
		{
			freeCharMemDaf(buffer);
			return (-1);
		}
		if (i == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUFSIZE)
			buffer = my_realloc(buffer, input, input + 1);
		buffer[input] = t;
		input++;
	}
	buffer[input] = '\0';
	showLine(lneptr1, n, buffer, input);
	retVal = input;
	if (i != 0)
		input = 0;
	return (retVal);
}

/**
 * prntcmtz - Reverses string
 * @chkn: str to rev
 */
void prntcmtz(int chkn)
{
	switch (chkn)
	{
		/*......new ......*/
		case 1:
			write(STDOUT_FILENO, "\n ", 2);
			break;
		case 2:
			write(STDIN_FILENO, "Enter command$ ", 17);
			break;
		/*......new ......*/
	}
}


/**
 * fetchSig - Handle
 * @sig: Signal handler
 */

void fetchSig(int sig)
{
	(void)sig;
	prntcmtz(1);
}

