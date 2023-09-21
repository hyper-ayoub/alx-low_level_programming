#include "shell.h"

/**
 * my_history1 - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @myinfo: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int my_history(info_t *myinfo)
{
	print_ls1(myinfo->history);
	return (0);
} 
/**
 * set_myalias_str - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_myalias_str(info_t *myinfo, char *str)
{
	char *p, c;
	int ret;

	p = strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = dlt_node1_in_index(&(myinfo->alias),
		get_node1_index(myinfo->alias, node1_starts(myinfo->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_myalias - sets alias to string
 * @myinfo: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_myalias(info_t *myinfo, char *str)
{
	char *p;

	p = strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return unset_alias((myinfo, str));

	unset_alias(myinfo, str);
	return (myadd_node1_end(&(myinfo->alias), str, 0) == NULL);
}

/**
 * print_myalias - prints an alias string
 * @node1: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_myalias(list_t *node1)
{
	char *p = NULL, *a = NULL;

	if (node1)
	{
		p = strchr(node1->str, '=');
		for (a = node1->str; a <= p; a++)
			putchar(*a);
		putchar('\'');
		puts(p + 1);
		puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * my_alias - mimics the alias builtin (man alias)
 * @myinfo: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int my_alias(info_t *myinfo)
{
	int i = 0;
	char *p = NULL;
	list_t *node1 = NULL;

	if (myinfo->argc == 1)
	{
		node1 = myinfo->alias;
		while (node1)
		{
			print_myalias(node1);
			node1 = node1->next;
		}
		return (0);
	}
	for (i = 1; myinfo->argv[i]; i++)
	{
		p = strchr(myinfo->argv[i], '=');
		if (p)
			set_myalias(myinfo, myinfo->argv[i]);
		else
			print_myalias(node1_starts(myinfo->alias, myinfo->argv[i], '='));
	}

	return (0);
}
