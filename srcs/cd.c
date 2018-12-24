#include "../incl/42sh.h"

int		cd(t_env *env, const char *path)
{
	DIR* dir;

	if ((dir = opendir(path)))
	{
		/* Directory exists. */
		closedir(dir);
		if (!chdir(path))
			return (SUCCESS);
	}
	else if (ENOENT == errno)
		/* Directory does not exist. */
		return (FAILURE);
	else
		/* opendir() failed for some other reason. */
		env->status.error.errcode = ERR_SYSTEM;
	/*
	 * check if path exists
	 * if true:
	 * 		cd to dir
	 * else:
	 * 		set error and print to user
	 * 	return env
	 */
	return (FAILURE);
}
