#include "../incl/42sh.h"

t_list	*open_quotes(char *str)
{
	char 	q;
	t_list	*tokens;

	tokens = NULL;
	q = lex(&tokens, str, 2, '\"', '\'');
	if (!q)
		return (NULL);
	else if (q == '\'' || q == '\"')
		return (quote_loop("quote> ", q, &tokens));
	return (tokens);
}

t_list	*quote_loop(const char *prmpt, char q, t_list **queue)
{
	char	*closeq;

	enqueue(queue, &(char*){"\n"}, 1);
	while (1)
	{
		closeq = prompt(prmpt);
		if (!strncmp(closeq, &q, 1))
			break;
		else
		{
			enqueue(queue, &closeq, strlen(closeq));
			enqueue(queue, &(char*){"\n"}, 1);
		}
	}
	return (*queue);
}

int		echo(t_env *env, char **opts) {
	char *str;
	t_list *echo_queue;

	echo_queue = new_list();
	if (!env || !opts)
		return (FAILURE);
	if (*(++opts)) {
		if (!(str = mini_join(opts, " ")))
			error(env, __FILE__, __func__, __LINE__, WHICH(str), "null string");
		if (!(echo_queue = open_quotes(str))) {
			env->status.error.errcode = ERR_PROCESS;
			error(env, __FILE__, __func__, __LINE__, WHICH(echo_queue), "lexing");
		}
		if (dump_queue(&echo_queue, (void *) putstr, true) == FAILURE)
			return (FAILURE);
	}
	print(1, "\n");
	return (SUCCESS);
}