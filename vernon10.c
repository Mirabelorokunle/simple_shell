#include "main.h"

/* .........................NUM 2 BTW.........................*/
/**
 * authenticate_asst_ExtDaf - Hlp
 * @hlp: input
 */
void authenticate_asst_ExtDaf(char *hlp)
{
	write(STDOUT_FILENO, hlp, string_length(hlp));
	hlp = "Exits the shell with a status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, hlp, string_length(hlp));
	hlp = "statusis that of the lastarg command executed\n";
	write(STDOUT_FILENO, hlp, string_length(hlp));
}
/* .........................NUM 2 END...........................*/

/* .........................NUM 3 START.........................*/
/**
 * authenticator_asst - Hlp
 */

void authenticator_asst(void)
{
	char *hlp = "hlp: hlp [-dms] [pattern ...]\n";

	authenticator_asstDaf(hlp);
}
/* .........................NUM 3 BTW.........................*/

/*..................bbbbb............................*/



/* .........................NUM 12 END.........................*/
/**
 * autIToAlph - functio
 * @n: type int
 * Return: String.
 */

char *autIToAlph(int n)
{
	unsigned int n1;
	int lenght = fetch_lengthe(n);
	char *buffer;

	buffer = malloc(sizeof(char) * (lenght + 1));
	if (buffer == 0)
		return (NULL);

	*(buffer + lenght) = '\0';

	if (n < 0)
	{
		/* ....................... NEW.......................*/
		n1 = autRespDaf(n, 1);
		/* n1 = n * -1; */
		/* ....................... NEW.......................*/
		buffer[0] = '-';
	}
	else
	{
		/* ....................... NEW.......................*/
		n1 = autRespDaf(n, 2);
		/* n1 = n; */
		/* ....................... NEW.......................*/
	}

	lenght--;
	do {
		*(buffer + lenght) = (n1 % 10) + '0';
		n1 = n1 / 10;
		lenght--;
	} while (n1 > 0);
	return (buffer);
}

/**
 * autRespDaf - functio
 * @n: type int
 * @chkn: type int
 * Return: String.
 */

unsigned int autRespDaf(int n, int chkn)
{
	if (chkn == 1)
		return (n * -1);
	else
		return (n);
}

/**
 * inc_dif_node_extr - adds
 * @head: head
 * @sep1: separato
 * Return: address
 */

strctList *inc_dif_node_extr(strctList **head, char sep1)
{
	strctList *new, *temp;

	new = malloc(sizeof(strctList));
	if (new == NULL)
		return (NULL);

	new->separator = sep1;
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
