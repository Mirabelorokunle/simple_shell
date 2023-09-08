#include "main.h"

/**
 * string_length - Returns
 * @s: Type
 * Return: Always 0.
 */

int string_length(const char *s)
{
	int len;

	for (len = 0; s[len] != 0; len++)
	{
	}
	return (len);
}

/**
 * compare_chars - compare
 * @str: input
 * @delimmta: delimit
 *
 * Return: 1 if are equals
 */

int compare_chars(char str[], const char *delimmta)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delimmta[j]; j++)
		{
			if (str[i] == delimmta[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}

/**
 * separate_line - tokenizes
 *
 * @input: input
 * Return: string
 */
char **separate_line(char *input)
{
	size_t besize12;
	size_t x;
	char **tokens, *token;

	besize12 = TOK_BUFSIZE;

	tokens = malloc(sizeof(char *) * (besize12));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}
	token = stringtok(input, TOK_DELIM);
	tokens[0] = token;
	for (x = 1; token != NULL; x++)
	{
		if (x == besize12)
		{
			besize12 += TOK_BUFSIZE;
			tokens = my_realloc_hdp(tokens, x, sizeof(char *) * besize12);
			if (tokens == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = stringtok(NULL, TOK_DELIM);
		tokens[x] = token;
	}
	return (tokens);
}

/*..................lllll............................*/



/**
 * authenticator_asstDaf - Hlp
 * @hlp: lastarg
 */

void authenticator_asstDaf(char *hlp)
{
	write(STDOUT_FILENO, hlp, string_length(hlp));
	hlp = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, hlp, string_length(hlp));
	hlp = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, hlp, string_length(hlp));
}

/* .........................NUM 3 END...........................*/

/* .........................NUM 4 START.........................*/
/**
 * authenticator_asst_alias - Hlp
 */

void authenticator_asst_alias(void)
{
	char *hlp = "alias: alias [-p] [name[=value]...]\n";

	 authenticator_asst_aliasDaf(hlp);
}
/* .........................NUM 4 BTW.........................*/
