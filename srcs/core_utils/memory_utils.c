#include "minishell.h"

void	free_minishell(t_minishell *minishell)
{
	if (minishell)
		free(minishell);
	if (minishell->cmd_table)
		free_table(minishell->cmd_table);
	return ;
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_table(t_cmd_table **cmd_table)
{
	int	i;

	i = 0;
	while (cmd_table[i])
	{
		free(cmd_table[i]);
		i++;
	}
	free(cmd_table);
}
