#include "shell.h"

/**
 * _exit - exits the shell
 * @comm: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if comm.argv[0] != "exit"
 */
int _exit(comm_t *comm)
{
	int exitcheck;

	if (comm->argv[1])  
	{
		exitcheck = _erratoi(comm->argv[1]);
		if (exitcheck == -1)
		{
			comm->status = 2;
			print_error(comm, "Illegal number: ");
			_eputs(comm->argv[1]);
			_eputchar('\n');
			return (1);
		}
		comm->err_num = _erratoi(comm->argv[1]);
		return (-2);
	}
	comm->err_num = -1;
	return (-2);
}
/**
 * _mycd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _cd(comm_t *comm)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!comm->argv[1])
	{
		dir = _getenv(comm, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(comm, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(comm->argv[1], "-") == 0)
	{
		if (!_getenv(comm, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(comm, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(comm, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(comm->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(comm, "can't cd to ");
		_eputs(comm->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(comm, "OLDPWD", _getenv(comm, "PWD="));
		_setenv(comm, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _help(comm_t *comm)
{
	char **arg_array;

	arg_array = comm->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
