#include "minishell.h"

/*
** 🦕🌴
** 
**	get_minishell
**
**	This is a singleton. The concept is to create
**	an object once and then be able to access it
**	any time while not using global variable thanks
**	to a stored pointer.
**
** 🌴🥥
*/

t_minishell	*get_minishell(t_minishell *minishell)
{
	static t_minishell	*pointer_to_minishell = NULL;

	if (!pointer_to_minishell && minishell)
		pointer_to_minishell = minishell;
	return (pointer_to_minishell);
}
