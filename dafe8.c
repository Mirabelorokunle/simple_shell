#include "main.h"

/* .........................NUM 12 END.........................*/

/**
 * confirmdtenvironmente - checks
 *
 * @h: head
 * @in: input
 * @data: data
 */

void confirmdtenvironmente(strct_var **h, char *in, dataSHLL *data)
{
	int row, chr, j, lval;
	char **EnvrT;

	EnvrT = data->dtenviron;
	for (row = 0; EnvrT[row]; row++)
	{
		for (j = 1, chr = 0; EnvrT[row][chr]; chr++)
		{
			if (EnvrT[row][chr] == '=')
			{
				lval = string_length(EnvrT[row] + chr + 1);
				include_Revar_node(h, j, EnvrT[row] + chr + 1, lval);
				return;
			}
			if (in[j] == EnvrT[row][chr])
				j++;
			else
				break;
		}
	}
	for (j = 0; in[j]; j++)
	{
		if (in[j] == ' ' || in[j] == '\t' || in[j] == ';' || in[j] == '\n')
			break;
	}
	include_Revar_node(h, j, NULL, 0);
}

/**
 * confirm_variable - check
 *
 * @h: head
 * @in: input
 * @st: lastar
 * @data: data structure
 * Return: int
 */

int confirm_variable(strct_var **h, char *in, char *st, dataSHLL *data)
{
	int i, lsth, lpdj;

	lsth = string_length(st);
	lpdj = string_length(data->pid);

	for (i = 0; in[i]; i++)
	{
		if (in[i] == '$')
		{
			if (in[i + 1] == '?')
				include_Revar_node(h, 2, st, lsth), i++;
			else if (in[i + 1] == '$')
				include_Revar_node(h, 2, data->pid, lpdj), i++;
			else if (in[i + 1] == '\n')
				include_Revar_node(h, 0, NULL, 0);
			else if (in[i + 1] == '\0')
				include_Revar_node(h, 0, NULL, 0);
			else if (in[i + 1] == ' ')
				include_Revar_node(h, 0, NULL, 0);
			else if (in[i + 1] == '\t')
				include_Revar_node(h, 0, NULL, 0);
			else if (in[i + 1] == ';')
				include_Revar_node(h, 0, NULL, 0);
			else
				confirmdtenvironmente(h, in + i, data);
		}
	}
	return (i);
}


/*..................iiiii............................*/



/**
 * rest_input - replace
 *
 * @head: head
 * @input: input
 * @n1_input: new
 * @nlen1: new
 * Return: replaced
 */

char *rest_input(strct_var **head, char *input, char *n1_input, int nlen1)
{
	strct_var *indx25;
	int i, j, k;

	indx25 = *head;
	for (j = i = 0; i < nlen1; i++)
	{
		if (input[j] == '$')
		{
			if (!(indx25->len_var) && !(indx25->len_val))
			{
				n1_input[i] = input[j];
				j++;
			}
			else if (indx25->len_var && !(indx25->len_val))
			{
				for (k = 0; k < indx25->len_var; k++)
					j++;
				i--;
			}
			else
			{
				for (k = 0; k < indx25->len_val; k++)
				{
					n1_input[i] = indx25->val[k];
					i++;
				}
				j += (indx25->len_var);
				i--;
			}
			indx25 = indx25->next;
		}
		else
		{
			n1_input[i] = input[j];
			j++;
		}
	}
	return (n1_input);
}

/**
 * rest_variable - calls
 *
 * @input: input string
 * @datshell: data structure
 * Return: replaced string
 */

char *rest_variable(char *input, dataSHLL *datshell)
{
	strct_var *head, *indx25;
	char *status, *n1_input;
	int olen, nlen1;

	status = autIToAlph(datshell->status);
	head = NULL;

	olen = confirm_variable(&head, input, status, datshell);

	if (head == NULL)
	{
		freeCharMemDaf(status);
		return (input);
	}

	indx25 = head;
	nlen1 = 0;

	while (indx25 != NULL)
	{
		nlen1 += (indx25->len_val - indx25->len_var);
		indx25 = indx25->next;
	}

	nlen1 += olen;

	n1_input = malloc(sizeof(char) * (nlen1 + 1));
	n1_input[nlen1] = '\0';

	n1_input = rest_input(&head, input, n1_input, nlen1);

	freeCharMemDaf(input);
	freeCharMemDaf(status);
	emptY_Revar_list(&head);

	return (n1_input);
}

/**
 * remove_command - deletes
 *
 * @in: input
 * Return: input
 */
char *remove_command(char *in)
{
	int i, up2;

	up2 = 0;
	for (i = 0; in[i]; i++)
	{
		if (in[i] == '#')
		{
			if (i == 0)
			{
				freeCharMemDaf(in);
				return (NULL);
			}
			if (in[i - 1] == ' ' || in[i - 1] == '\t' || in[i - 1] == ';')
				up2 = i;
		}
	}
	if (up2 != 0)
	{
		in = my_realloc(in, i, up2 + 1);
		in[up2] = '\0';
	}
	return (in);
}


