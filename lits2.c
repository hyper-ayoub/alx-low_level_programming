#include "shell.h"

/**
 * list1len - determines length of linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t list1len(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}



/**
 * print_ls1 - prints all elements of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_ls1(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		puts(cnv_number(h->num, 20, 0));
		fputchar(':');
		fputchar(' ');
		puts(h->str ? h->str : "(nil)");
		puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * node1_starts - returns node whose string starts with prefix
 * @mynode: pointer to list head
 * @myprefix: string to match
 * @r: the next character after prefix to match
 *
 * Return: match node1 or null
 */
list_t *node1_starts(list_t *mynode, char *myprefix, char r)
{
	char *p1 = NULL;

	while (mynode)
	{
		p1 = my_strcat(mynode->str, myprefix);
		if (p1 && ((r == -1) || (*p1 == r)))
			return (mynode);
		mynode = mynode->next;
	}
	return (NULL);
}

/**
 * get_node1 - gets the index of a node
 * @h: pointer to list head
 * @mynode: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node1(list_t *h, list_t *mynode)
{
	size_t i = 0;

	while (h)
	{
		if (h == mynode)
			return (i);
		h = h->next;
		i++;
	}
	return (-1);
}

/**
 * list1_str - returns an array of strings of the list->str
 * @h: pointer to first node
 *
 * Return: array of strings
 */
char **list1_str(list_t *h)
{
	list_t *node1 = h;
	size_t i = list1len(h), k;
	char **strs;
	char *str;

	if (!h || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node1; node1 = node1->next, i++)
	{
		str = malloc(strlen(node1->str) + 1);
		if (!str)
		{
			for (k = 0; k < i; k++)
				free(strs[k]);
			free(strs);
			return (NULL);
		}

		str = strcpy(str, node1->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}
