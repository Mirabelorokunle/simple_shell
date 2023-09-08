#include "main.h"

/**
 * environ_ident - compares
 * @newenvi: name
 * @name: name
 *
 * Return: 0
 */

int environ_ident(const char *newenvi, const char *name)
{
	int i, ress;

	for (i = 0; newenvi[i] != '='; i++)
	{
		if (newenvi[i] != name[i])
		{
			return (0);
		}
	}
	ress = i + 1;
	return (ress);
}

/**
 * getenviron - get
 * @name: name
 * @dtenviron: environment
 *
 * Return: value
 */

char *getenviron(const char *name, char **dtenviron)
{
	char *ptrEnvrmnt;
	int i, movenmt;

	ptrEnvrmnt = NULL;
	movenmt = 0;
	for (i = 0; dtenviron[i]; i++)
	{
		movenmt = environ_ident(dtenviron[i], name);
		if (movenmt)
		{
			ptrEnvrmnt = dtenviron[i];
			break;
		}
	}
	return (ptrEnvrmnt + movenmt);
}

/**
 * shEnv - print
 *
 * @datshell: data
 * Return: 1
 */

int shEnv(dataSHLL *datshell)
{
	int i, j;

	for (i = 0; datshell->dtenviron[i]; i++)
	{
		for (j = 0; datshell->dtenviron[i][j]; j++)
			;

		write(STDOUT_FILENO, datshell->dtenviron[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datshell->status = 0;

	return (1);
}

/**
 * prepareEnvron - sets
 *
 * @name: name
 * @value: value
 * @datshell: data
 */

void prepareEnvron(char *name, char *value, dataSHLL *datshell)
{
	int i;
	char *varEnvf, *nameEnvy;

	for (i = 0; datshell->dtenviron[i]; i++)
	{
		varEnvf = _strdup(datshell->dtenviron[i]);
		nameEnvy = stringtok(varEnvf, "=");
		if (stringcompr(nameEnvy, name) == 0)
		{
			free(datshell->dtenviron[i]);
			datshell->dtenviron[i] = m_detail(nameEnvy, value);
			free(varEnvf);
			return;
		}
		free(varEnvf);
	}
	datshell->dtenviron = my_realloc_hdp(datshell->dtenviron, i,
										sizeof(char *) * (i + 2));
	datshell->dtenviron[i] = m_detail(name, value);
	datshell->dtenviron[i + 1] = NULL;
}

/*..................hhhhh............................*/



/**
 * setenviron - compar
 * @datshell: data
 * Return: 1
 */

int setenviron(dataSHLL *datshell)
{
	if (datshell->args[1] == NULL || datshell->args[2] == NULL)
	{
		getErr(datshell, -1);
		return (1);
	}
	prepareEnvron(datshell->args[1], datshell->args[2], datshell);
	return (1);
}

/* .........................NUM 12 START.......................*/
