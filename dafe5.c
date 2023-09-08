#include "main.h"

/* .........................NUM 8 BTW...........................*/
/**
 * free_srtctLine_MemDaf - frees
 * @temp: head
 */

void free_srtctLine_MemDaf(srtctLine *temp)
{
	free(temp);
}
/* .........................NUM 8 END...........................*/

/* .........................NUM 9 START.........................*/
/**
 * emptY_Revar_list - frees
 * @head: head
 */

void emptY_Revar_list(strct_var **head)
{
	strct_var *temp;
	strct_var *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}
/* .........................NUM 9 BTW...........................*/

/*..................eeeee............................*/



/**
 * free_strct_var_MemDaf - frees
 * @temp: head
 */

void free_strct_var_MemDaf(strct_var *temp)
{
	free(temp);
}
/* .........................NUM 9 END...........................*/

/**
 * include_LN_node_extr - adds
 * @head: head
 * @line: command
 * Return: address
 */
srtctLine *include_LN_node_extr(srtctLine **head, char *line)
{
	srtctLine *new, *temp;

	new = malloc(sizeof(srtctLine));
	if (new == NULL)
		return (NULL);

	new->line = line;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * include_Revar_node - add
 * @head: head
 * @lhvar: length
 * @val: value
 * @lval: length
 * Return: address
 */

strct_var *include_Revar_node(strct_var **head, int lhvar,
									char *val, int lval)
{
	strct_var *new, *temp;

	new = malloc(sizeof(strct_var));
	if (new == NULL)
		return (NULL);

	new->len_var = lhvar;
	new->val = val;
	new->len_val = lval;

	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/* .........................NUM 10 START.......................*/
