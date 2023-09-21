#include "shell.h"
#include "list.h"

/**
 * Assuming list_to_strings is a function that converts a list to a char **
 * and is declared like this:
 * char **list_to_strings(list_t *list);
 */

/**
 * _getmyenv - returns the string array copy of our environ
 * @myinfo: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **_getmyenv(info_t *myinfo)
{
    if (!myinfo->env || myinfo->env_changed)
    {
        // Assuming list_to_strings returns char **
        myinfo->env = list_to_strings(myinfo->env);
        myinfo->env_changed = 0;
    }

    return (myinfo->env);
}

/**
 * Assuming mystarts_with is a function that checks if a string starts with a prefix
 * and is declared like this:
 * char *mystarts_with(const char *str, const char *prefix);
 */

/**
 * dlt_setenv - delete an environment variable
 * @myinfo: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: 1 on delete, 0 otherwise
 * @myvar: the string env var property
 */
int dlt_setenv(info_t *myinfo, char *var)
{
    list_t *node1 = myinfo->env;
    size_t i = 0;
    char *p;

    if (!node1 || !var)
        return (0);

    while (node1)
    {
        // Assuming mystarts_with is used to check if a string starts with a prefix
        p = mystarts_with(node1->str, var);
        if (p && *p == '=')
        {
            myinfo->env_changed = dlt_node1_in_index(&(myinfo->env), i);
            i = 0;
            node1 = myinfo->env;
            continue;
        }
        node1 = node1->next;
        i++;
    }
    return (myinfo->env_changed);
}

/**
 * set_myenv - Initialize a new environment variable,
 *             or modify an existing one
 * @myinfo: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @myvar: the string env var property
 * @myvalue: the string env var value
 * Return: Always 0
 */
int set_myenv(info_t *myinfo, char *myvar, char *myvalue)
{
    char *buf = NULL;
    list_t *node1;
    char *p;

    if (!myvar || !myvalue)
        return (0);

    buf = malloc(strlen(myvar) + strlen(myvalue) + 2);
    if (!buf)
        return (1);
    strcpy(buf, myvar);
    strcat(buf, "=");
    strcat(buf, myvalue);
    node1 = myinfo->env;
    while (node1)
    {
        // Assuming mystarts_with is used to check if a string starts with a prefix
        p = mystarts_with(node1->str, myvar);
        if (p && *p == '=')
        {
            free(node1->str);
            node1->str = buf;
            myinfo->env_changed = 1;
            return (0);
        }
        node1 = node1->next;
    }
    myadd_node1_end(&(myinfo->env), buf, 0);
    free(buf);
    myinfo->env_changed = 1;
    return (0);
}

