#include "shell.h"

/**
 * my_exit - exits the shell
 * @inform: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int my_exit(inform_t *inform)
{
	int ext_chk;

	if (inform->argv[1])  /* If there is an exit arguement */
	{
		ext_chk = _erratoi(inform->argv[1]);
		if (ext_chk == -1)
		{
			inform->status = 2;
			print_error(inform, "wrong number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		inform->err_num = _erratoi(inform->argv[1]);
		return (-2);
	}
	inform->err_num = -1;
	return (-2);
}

/**
 * my_cd - changes the current directory of the process
 * @inform: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int my_cd(inform_t *inform)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!inform->argv[1])
	{
		dir = _getenv(inform, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(inform->argv[1], "-") == 0)
	{
		if (!_getenv(inform, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(inform, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(inform->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(inform, "can't cd to ");
		_eputs(inform->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(inform, "OLDPWD", _getenv(inform, "PWD="));
		_setenv(inform, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
