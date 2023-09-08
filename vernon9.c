#include "main.h"

/* .........................NUM 18 BTW.........................*/
/**
 * aut_asstsetenvironeeDaf - Hlp
 * @hlp: str
 */

void aut_asstsetenvironeeDaf(char *hlp)
{
	write(STDOUT_FILENO, hlp, string_length(hlp));
	hlp = "int replace)\n\t";
	write(STDOUT_FILENO, hlp, string_length(hlp));
	hlp = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, hlp, string_length(hlp));
}

/* .........................NUM 18 END.........................*/

/* .........................NUM 19 START.......................*/
/**
 * aut_asstunsetenvironddd - Hlp
 */

void aut_asstunsetenvironddd(void)
{
	char *hlp = "unsetenv: unsetenv (const char *name)\n\t";

	aut_asstunsetenvirondddDaf(hlp);
}

/* .........................NUM 19 BTW.........................*/
/**
 * aut_asstunsetenvirondddDaf - Hlp
 * @hlp: str
 */

void aut_asstunsetenvirondddDaf(char *hlp)
{
	write(STDOUT_FILENO, hlp, string_length(hlp));
	hlp = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, hlp, string_length(hlp));
}

/* .........................NUM 19 END.........................*/

/* .........................NUM 20 START.......................*/
/**
 * autAsstantGeneral - Entr
 */

void autAsstantGeneral(void)
{
	char *hlp = "^-^ bash, version 1.0(1)-release\n";

	autAsstantGeneralDaf(hlp);
}


/*..................99999............................*/



/* .........................NUM 1 START...........................*/

/**
 * theAtoi - atoi
 * @s: input
 * Return: integer
 */
int theAtoi(char *s)
{
	unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, x;
	struct atoistruct cnt;

	cnt = theAtoiDaf_count(s, count, size, pn, m);

	for (x = cnt.cntst - cnt.szst; x < count; x++)
	{
		oi = oi + ((*(s + x) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}

/* .........................NUM 1 BTW...........................*/

