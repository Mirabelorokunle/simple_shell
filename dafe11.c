#include "main.h"

/**
 * undoStrRevDafNest - reverses
 * @j: input
 * @str: input
 * @temp: input
 */

void undoStrRevDafNest(int j, char *str, char temp)
{
	temp = *(str + j);
	*(str + j) = *(str + (j - 1));
	*(str + (j - 1)) = temp;
}

/**
 * include_nodes - ad
 *
 * @head_s: hea
 * @head_l: hea
 * @input: inpu
 */

void include_nodes(strctList **head_s, srtctLine **head_l, char *input)
{
	int x;
	char *line;

	input = exchChar(input, 0);

	for (x = 0; input[x]; x++)
	{
		if (input[x] == ';')
			inc_dif_node_extr(head_s, input[x]);

		if (input[x] == '|' || input[x] == '&')
		{
			inc_dif_node_extr(head_s, input[x]);
			x++;
		}
	}

	line = stringtok(input, ";|&");
	do {
		line = exchChar(line, 1);
		include_LN_node_extr(head_l, line);
		line = stringtok(NULL, ";|&");
	} while (line != NULL);
}

/* .........................NUM 17 START.......................*/
/**
 * aut_asstantEnvirone - Hl
 */

void aut_asstantEnvirone(void)
{
	char *hlp = "env: env [option] [name=value] [command [args]]\n\t";

	aut_asstantEnvironeDaf(hlp);
}

/* .........................NUM 17 BTW.........................*/
/**
 * aut_asstantEnvironeDaf - Hlp
 * @hlp: str
 */

void aut_asstantEnvironeDaf(char *hlp)
{
	write(STDOUT_FILENO, hlp, string_length(hlp));
	hlp = "Print the enviroment of the shell.\n";
	write(STDOUT_FILENO, hlp, string_length(hlp));
}

/* .........................NUM 17 END.........................*/


/*..................88888............................*/



/* .........................NUM 18 START.......................*/
/**
 * aut_asstsetenvironee - Hlp
 */

void aut_asstsetenvironee(void)
{

	char *hlp = "setenv: setenv (const char *name, const char *value,";

	aut_asstsetenvironeeDaf(hlp);
}

