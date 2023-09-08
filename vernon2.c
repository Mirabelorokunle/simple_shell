#include "main.h"

/*..................11111............................*/



/* .........................NUM 20 BTW.........................*/
/**
 * autAsstantGeneralDaf - Entr
 * @hlp: str
 */

void autAsstantGeneralDaf(char *hlp)
{
	write(STDOUT_FILENO, hlp, string_length(hlp));
	hlp = "These commands are defined internally.Type 'hlp' to see the list";
	write(STDOUT_FILENO, hlp, string_length(hlp));
	hlp = "Type 'hlp name' to find out more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, hlp, string_length(hlp));
	hlp = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, hlp, string_length(hlp));
	hlp = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, hlp, string_length(hlp));
	hlp = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, hlp, string_length(hlp));
	hlp = "unsetenv [variable]\n";
	write(STDOUT_FILENO, hlp, string_length(hlp));
}

/* .........................NUM 20 END.........................*/

/* .........................NUM 12 START.......................*/
/* .........................NUM 12 BTW.........................*/
/* .........................NUM 12 END.........................*/

/**
 * stringConcate - concatenate
 * @dest: char
 * @src: const
 * Return: the de
 */

char *stringConcate(char *dest, const char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = string_charDaf(dest, src, i, j);
		i++;
	}

	dest[i] = '\0';
	return (dest);
}

/*............................new 1............................*/
/**
 * string_charDaf - concatenate
 * @dest: char
 * @src: const
 * @i: const
 * @j: const
 * Return: the de
 */

char string_charDaf(char *dest, const char *src, int i, int j)
{
	dest[i] = src[j];
	return (dest[i]);
}
/*............................new 1............................*/

/**
 * *stringCopy - Copies
 * @dest: Type
 * @src: Type
 * Return: the de
 */

char *stringCopy(char *dest, char *src)
{

	size_t a;

	for (a = 0; src[a] != '\0'; a++)
	{
		/*............................new 1............................*/
		dest[a] = string_charDaf(dest, src, a, a);
		/*............................new 1............................*/
		/* dest[a] = src[a]; */
	}
	dest[a] = '\0';

	return (dest);
}

/**
 * stringcompr - Function
 * @s1: type
 * @s2: type
 * Return: Always 0.
 */

int stringcompr(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;

	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

