#include "../incl/42sh.h"

int		init_shell(t_env **env)
{
	if (!((*env)->vars = new_list()))
		return (FAILURE);
	if (!(*env = (t_env*)memalloc(sizeof(t_env))))
		return (FAILURE);
	(*env)->status.running = 1;
	return (SUCCESS);
}