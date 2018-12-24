#include "../incl/42sh.h"

int		quit(t_env *env, char **opts)
{
	(void)opts;
	env->status.running = 0;
	return (SUCCESS);
}