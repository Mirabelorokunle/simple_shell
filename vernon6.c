#include "main.h"

/* .........................NUM 15 END.........................*/

/**
 * change_dirFtp - changes
 * @datshell: data
 */

void change_dirFtp(dataSHLL *datshell)
{
	char pwd[PATH_MAX], *dir, *cpyPdir, *cpyStrTokPwd;

	getcwd(pwd, sizeof(pwd));
	cpyPdir = _strdup(pwd);
	prepareEnvron("OLDPWD", cpyPdir, datshell);
	dir = datshell->args[1];
	if (stringcompr(".", dir) == 0)
	{
		prepareEnvron("PWD", cpyPdir, datshell);
		freeCharMemDaf(cpyPdir);
		return;
	}
	if (stringcompr("/", cpyPdir) == 0)
	{
		freeCharMemDaf(cpyPdir);
		return;
	}
	cpyStrTokPwd = cpyPdir;
	undoStrRev(cpyStrTokPwd);
	cpyStrTokPwd = stringtok(cpyStrTokPwd, "/");
	if (cpyStrTokPwd != NULL)
	{
		cpyStrTokPwd = stringtok(NULL, "\0");

		if (cpyStrTokPwd != NULL)
			undoStrRev(cpyStrTokPwd);
	}
	if (cpyStrTokPwd != NULL)
	{
		chdir(cpyStrTokPwd);
		prepareEnvron("PWD", cpyStrTokPwd, datshell);
	}
	else
	{
		chdir("/");
		prepareEnvron("PWD", "/", datshell);
	}
	datshell->status = 0;
	freeCharMemDaf(cpyPdir);
}

/*..................44444............................*/



/**
 * change_dirLoc - changes
 * @datshell: data
 */

void change_dirLoc(dataSHLL *datshell)
{
	char pwd[PATH_MAX];
	char *dir, *cpyPdir, *copy_direc;

	getcwd(pwd, sizeof(pwd));

	dir = datshell->args[1];
	if (chdir(dir) == -1)
	{
		getErr(datshell, 2);
		return;
	}

	cpyPdir = _strdup(pwd);
	prepareEnvron("OLDPWD", cpyPdir, datshell);

	copy_direc = _strdup(dir);
	prepareEnvron("PWD", copy_direc, datshell);

	freeCharMemDaf(cpyPdir);
	freeCharMemDaf(copy_direc);

	datshell->status = 0;

	chdir(dir);
}

/**
 * change_dirLastarg - changes
 * @datshell: data
 */

void change_dirLastarg(dataSHLL *datshell)
{
	char pwd[PATH_MAX];
	char *ppwd, *pOldPwd, *cpyPdir, *cpOldPwd;

	getcwd(pwd, sizeof(pwd));
	cpyPdir = _strdup(pwd);

	pOldPwd = getenviron("OLDPWD", datshell->dtenviron);

	if (pOldPwd == NULL)
		cpOldPwd = cpyPdir;
	else
		cpOldPwd = _strdup(pOldPwd);

	prepareEnvron("OLDPWD", cpyPdir, datshell);

	if (chdir(cpOldPwd) == -1)
		prepareEnvron("PWD", cpyPdir, datshell);
	else
		prepareEnvron("PWD", cpOldPwd, datshell);

	ppwd = getenviron("PWD", datshell->dtenviron);

	write(STDOUT_FILENO, ppwd, string_length(ppwd));
	write(STDOUT_FILENO, "\n", 1);

	freeCharMemDaf(cpyPdir);
	if (pOldPwd)
		freeCharMemDaf(cpOldPwd);

	datshell->status = 0;

	chdir(ppwd);
}

/**
 * change_dirLoc_2 - changes
 *
 * @datshell: data
 */

void change_dirLoc_2(dataSHLL *datshell)
{
	char *ppwd, *home;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	ppwd = _strdup(pwd);

	home = getenviron("HOME", datshell->dtenviron);

	if (home == NULL)
	{
		prepareEnvron("OLDPWD", ppwd, datshell);
		freeCharMemDaf(ppwd);
		return;
	}

	if (chdir(home) == -1)
	{
		getErr(datshell, 2);
		freeCharMemDaf(ppwd);
		return;
	}

	prepareEnvron("OLDPWD", ppwd, datshell);
	prepareEnvron("PWD", home, datshell);
	freeCharMemDaf(ppwd);
	datshell->status = 0;
}

/**
 * change_dirSH - changes
 *
 * @datshell: data
 * Return: 1 on success
 */

int change_dirSH(dataSHLL *datshell)
{
	char *dir;
	int izhome, izhome2, izddash;

	dir = datshell->args[1];

	if (dir != NULL)
	{
		izhome = stringcompr("$HOME", dir);
		izhome2 = stringcompr("~", dir);
		izddash = stringcompr("--", dir);
	}

	if (dir == NULL || !izhome || !izhome2 || !izddash)
	{
		change_dirLoc_2(datshell);
		return (1);
	}

	if (stringcompr("-", dir) == 0)
	{
		change_dirLastarg(datshell);
		return (1);
	}

	if (stringcompr(".", dir) == 0 || stringcompr("..", dir) == 0)
	{
		change_dirFtp(datshell);
		return (1);
	}

	change_dirLoc(datshell);

	return (1);
}
