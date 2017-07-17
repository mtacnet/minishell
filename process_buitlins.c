#include "minishell.h"

static void		process_setenv(char **env)
{
	view_tab(env);
}


static void		process_unset(char **env)
{
	view_tab(env);
}


void	process_cd(char **env)
{
	view_tab(env);
}

void	process_echo(char **env)
{
	view_tab(env);
}

void	process_exit(char **env)
{
	view_tab(env);
}

void	process_env(char **env, int value)
{
	view_tab(env);
}
