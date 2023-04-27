#include "shell.h"

/**
 * my_env - prints the current environ
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int my_env(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * get_env - gets the value of an environment variable
 * @info: Structure containing potential arguments.
 * @name: envinronment variable name
 * Return: the value is returned
 */
char *get_env(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * myset_env - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments.
 *  Return: Always 0
 */
int myset_env(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (set_env(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * myunset_env - Remove an environment variable
 * @info: Structure containing potential arguments.
 *  Return: Always 0
 */
int myunset_env(info_t *info)
{
	int e;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (e = 1; e <= info->argc; e++)
		unset_env(info, info->argv[e]);

	return (0);
}

/**
 * populate_envlist - populates env linked list
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int populate_envlist(info_t *info)
{
	list_t *node = NULL;
	size_t e;

	for (e = 0; environ[e]; e++)
		add_node_end(&node, environ[e], 0);
	info->env = node;
	return (0);
}

