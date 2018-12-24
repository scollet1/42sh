#include "../incl/42sh.h"

t_dtab g_disp[] = {
		{ "exit", quit },
		{ "quit", quit },
		{ "echo", echo },
		{ "setenv", shell_setenv },
		{ "unsetenv", shell_unsetenv },
		{ "env", shell_env },
		{ NULL, NULL }
};

int 	dispatch(t_env *env, const char *input) {
	int i;
	size_t len;
	char **parsed;

	if ((parsed = parser(input))) {
		i = -1;
		len = strlen(parsed[0]);
		/*
		** iterate TAB and look for
		** the correct function to
		** execute our command(s)
		*/
		while (g_disp[++i].name)
			if (strncmp(parsed[0], g_disp[i].name, len) == SUCCESS)
				return (g_disp[i].func(env, parsed));
		env->status.error.errcode = ERR_INVALID;
		return (error(env, __FILE__, __func__, __LINE__, parsed[0], ""));
	}
	return (FAILURE);
}
