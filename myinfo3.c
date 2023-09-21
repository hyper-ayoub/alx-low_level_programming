#include "shell.h"

void clear_myinfo(info_t *myinfo)
{
	memset(myinfo, 0, sizeof(info_t));
}

void set_myinfo(info_t *myinfo, char **myav)
{
	myinfo->fname = myav[0];
	if (myinfo->arg)
	{
		myinfo->argv = _strtow(myinfo->arg, " \t");
		if (!myinfo->argv)
		{
			myinfo->argv = malloc(sizeof(char *) * 2);
			if (myinfo->argv)
			{
				myinfo->argv[0] = _strdup(myinfo->arg);
				myinfo->argv[1] = NULL;
			}
		}
		myinfo->argc = (myinfo->argv) ? count_elements(myinfo->argv) : 0;
		replace_alias(myinfo);
		replace_vars(myinfo);
	}
}

void free_myinf1(info_t *myinfo, int myall)
{
	afree(myinfo->argv);
	myinfo->argv = NULL;
	if (myall)
	{
		free(myinfo->cmd_buf);
		free_list1(&(myinfo->env));
		free_list1(&(myinfo->history));
		free_list1(&(myinfo->alias));
		afree((void **)myinfo->environ);
		myinfo->environ = NULL;
		afree((void **)myinfo->cmd_buf);
		if (myinfo->readfd > 2)
			close(myinfo->readfd);
		f_putchar(BUF_FLUSH);
	}
}

