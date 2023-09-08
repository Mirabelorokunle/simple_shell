#include "main.h"

/* .........................NUM 6 BTW...........................*/
/**
 * dis_stx_errorDafIn - prints
 * @datshell: data
 * @msges: input
 * @msges_two: data
 * @msges_three: input
 * @error: index
 * @counter: a
 */
void dis_stx_errorDafIn(dataSHLL *datshell, char *msges, char *msges_two,
					char *msges_three, char *error, char *counter)
{
	stringCopy(error, datshell->av[0]);
	stringConcate(error, ": ");
	stringConcate(error, counter);
	stringConcate(error, msges_two);
	stringConcate(error, msges);
	stringConcate(error, msges_three);
	stringConcate(error, "\0");
}
/* .........................NUM 6 BTW...........................*/

/**
 * dis_stx_errorDaf - print
 * @input: inpu
 * @i: dat
 * @chkn: inpu
 * Return: char
 */
char *dis_stx_errorDaf(char *input, int i, int chkn)
{
	char *In_msg;

	if (chkn == 1)
		In_msg = (input[i + 1] == ';' ? ";;" : ";");
	else if (chkn == 1)
		In_msg = (input[i - 1] == ';' ? ";;" : ";");
	else if (chkn == 1)
		In_msg = (input[i + 1] == '|' ? "||" : "|");
	else
		In_msg = (input[i + 1] == '&' ? "&&" : "&");
	return (In_msg);
}

/* .........................NUM 6 END...........................*/

/**
 * confirm_stx_error - intermediate
 *
 * @datshell: data
 * @input: input
 * Return: 1
 */

int confirm_stx_error(dataSHLL *datshell, char *input)
{
	int begng = 0, f_char = 0, i = 0;

	f_char = baseChar(input, &begng);
	if (f_char == -1)
	{
		dis_stx_error(datshell, input, begng, 0);
		return (1);
	}

	i = error_separator_OP(input + begng, 0, *(input + begng));
	if (i != 0)
	{
		dis_stx_error(datshell, input, begng + i, 1);
		return (1);
	}
	return (0);
}


/*..................ddddd............................*/



/* .........................NUM 7 START.........................*/

/**
 * empty_dif_list - free
 * @head: head
 */

void empty_dif_list(strctList **head)
{
	strctList *temp;
	strctList *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free_strct_list_MemDaf(temp);
		}
		*head = NULL;
	}
}

/* .........................NUM 7 BTW...........................*/
/**
 * free_strct_list_MemDaf - frees
 * @temp: hea
 */

void free_strct_list_MemDaf(strctList *temp)
{
	free(temp);
}
/* .........................NUM 7 END...........................*/




/* .........................NUM 8 START.........................*/

