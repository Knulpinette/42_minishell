#include "minishell.h"

/*
** Handles do_something_and_exit or handle_error functions.
*/

t_error	error_and_exit(t_error code)
{
	t_minishell *minishell;

	minishell = get_minishell(NULL);
	error_message(code);
	if (minishell)
		free_minishell(minishell);
	if (code == REDIR_NO_ARG)
		exit(SYNTAX_ERROR);
	if (code == WRONG_CMD)
		exit(EXIT_FILE_NOT_FOUND);
	exit(EXIT_FAILURE);
}

int	error_and_return(t_error code, int exit_code)
{
	error_message(code);
	return (exit_code);
}

void	error_message(t_error code)
{
	if (code == ERR_NO_PRINT)
		return ;
	ft_putstr_fd(""LIGHT_RED"Error \n"END_COLOR"", STDERR_FILENO);
	if (code == WRONG_ARGC)
		ft_putstr_fd("Wrong number of arguments.\n", STDERR_FILENO);
	else if (code == TERMCAP_ERROR)
		ft_putstr_fd("Termcaps have failed.\n", STDERR_FILENO);
	else if (code == NO_OLDPWD)
		ft_putstr_fd("OLDPWD not set.\n", STDERR_FILENO);
	else if (code == INVALID_IDENTIFIER)
		ft_putstr_fd("Not a valid identifier\n", STDERR_FILENO);
	else if (code == REDIR_NO_ARG)
		ft_putstr_fd("Syntax error next to a redirection (no argument).\n", STDERR_FILENO);
	else
	{
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		write(STDERR_FILENO, "\n", 1);
	}
}

t_error	open_or_exit(char *file_path, mode_t mode)
{
	int	fd;

	fd = open(file_path, mode, 00755);
	if (fd == -1)
		error_and_exit(OPEN_FAIL);
	return (fd);
}

void	*calloc_or_exit(size_t size, int count)
{
	void	*result;

	result = ft_calloc(size, count);
	if (!result)
		error_and_exit(MEMORY_FAIL);
	return (result);
}
