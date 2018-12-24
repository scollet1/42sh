#include "../incl/42sh.h"

void		putvars(void *data)
{
	t_var *var;

	var = (t_var*)data;
	print(3, var->var, "=", var->val);
}

int		shell_env(t_env *env, char **opts)
{
	(void)opts;
	if (!dump_queue(&env->vars, putvars, false))
		return (FAILURE);
	return (SUCCESS);
}

int		shell_unsetenv(t_env *env, char **opts)
{
	t_node	*tmp;
	t_node	*head;

	head = env->vars->head;
	while (head)
	{
		if (!strcmp((char *)head->data, opts[0]))
		{
			tmp = head;
			head->prev->next = head->next;
			head->next->prev = head->prev;
			free(tmp);
			tmp = NULL;
			return (SUCCESS);
		}
		head = head->next;
	}
	return (FAILURE);
}

int		shell_setenv(t_env *env, char **opts)
{
	int res;
	t_var var;

	var = *(t_var*)memalloc(sizeof(t_var));
	var.var = opts[0];
	var.val = opts[1];
	res = enqueue(&env->vars, &var, sizeof(t_var));
	return (res);
}