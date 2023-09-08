#include "main.h"

/**
 * memorycopy - copies
 * @nptr: destination
 * @ptr: source
 * @size: size
 */

void memorycopy(void *nptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_nptr = (char *)nptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_nptr[i] = char_ptr[i];
}

/**
 * stringtok - splits
 * @str: input
 * @delimmta: delimiter.
 * Return: char
 */

char *stringtok(char str[], const char *delimmta)
{
	static char *splith, *str_edt;
	char *str_strt21;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (compare_chars(str, delimmta))
			return (NULL);
		splith = str;
		i = string_length(str);
		str_edt = &str[i];
	}
	str_strt21 = splith;
	if (str_strt21 == str_edt)
		return (NULL);

	for (bool = 0; *splith; splith++)
	{

		if (splith != str_strt21)
			if (*splith && *(splith - 1) == '\0')
				break;

		for (i = 0; delimmta[i]; i++)
		{
			if (*splith == delimmta[i])
			{
				*splith = '\0';
				if (splith == str_strt21)
					str_strt21++;
				break;
			}
		}
		if (bool == 0 && *splith)
			bool = 1;
	}
	if (bool == 0)
		return (NULL);
	return (str_strt21);
}

/**
 * is_digitFunc - define
 * @s: inpu
 * Return: 1
 */

int is_digitFunc(const char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
	}
	return (1);
}

/*..................kkkkk............................*/



/**
 * string_substr_pref_len - gets
 * @s: initial
 * @accept: accepted
 * Return: the
 */

int string_substr_pref_len(char *s, char *accept)
{
	int i, j, bool;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		bool = 1;
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(s + i) == *(accept + j))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (i);
}

/**
 * _strdup - duplicates
 * @s: Type
 * Return: duplicated
 */

char *_strdup(const char *s)
{
	char *new;
	size_t len;

	len = string_length(s);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	memorycopy(new, s, len + 1);
	return (new);
}
