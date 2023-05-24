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
