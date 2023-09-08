#include "main.h"

/**
 * duplicateChar - counts
 *
 * @input: input
 * @i: index
 * Return: repetitions
 */

int duplicateChar(char *input, int i)
{
	if (*(input - 1) == *input)
		return (duplicateChar(input - 1, i + 1));

	return (i);
}

/*..................55555............................*/



/**
 * baseChar - finds
 *
 * @input: input
 * @i: index
 * Return: 1
 */

int baseChar(char *input, int *i)
{
	for (*i = 0; input[*i]; *i += 1)
	{
		if (input[*i] == ' ' || input[*i] == '\t')
			continue;

		if (input[*i] == ';' || input[*i] == '|' || input[*i] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * my_realloc - reallocate
 * @ptr: pointe
 * @old_size: siz
 * @new_size: new siz
 *
 * Return: ptr.
 */

void *my_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *nptr;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		freeCharMemDaf(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	nptr = malloc(new_size);
	if (nptr == NULL)
		return (NULL);

	if (new_size < old_size)
		memorycopy(nptr, ptr, new_size);
	else
		memorycopy(nptr, ptr, old_size);

	freeCharMemDaf(ptr);
	return (nptr);
}

/**
 * my_realloc_hdp - reallocate
 * @ptr: double
 * @old_size: siz
 * @new_size: new size
 *
 * Return: ptr.
 */

char **my_realloc_hdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **nptr;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	nptr = malloc(sizeof(char *) * new_size);
	if (nptr == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		nptr[i] = ptr[i];

	free(ptr);

	return (nptr);
}

/**
 * fetch_lengthe - Get
 * @n: type
 * Return: Lenght
 */

int fetch_lengthe(int n)
{
	unsigned int n1 = 0;
	int lenght = 1;

	if (n < 0)
	{
		lenght++;
		n1 = n * -1;
	}
	else
	{
		n1 = n;
	}
	while (n1 > 9)
	{
		lenght++;
		n1 = n1 / 10;
	}

	return (lenght);
}

