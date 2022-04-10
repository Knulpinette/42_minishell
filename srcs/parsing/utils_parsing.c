#include "minishell.h"

/*
** 🦕🌴
**
**	Those are utilities functions for the various parsing steps.
**
**	is_not_exception
**	Will verify that the given character is not a special character
**	that should be consider as the end of a word. Conditions differ
**	if the given type is ENV_VAR or REDIR.
**
**	pass_space && pass_redir
**	As their name indicates, they return the increment amount to pass
**	the spaces or the redir following the given pointer.
**
**	handle_special_case_echo & text_is_all_n
**	This function and its helper are meant to handle when the command
**	of the instruction line is echo as it will only accept the -n
**	of '-nnnnnnnnnnnnnn' flag. The rest will always be considered as an
**	argument and printed - regardless of if it is a flag or else.
**
** 🌴🥥
*/

bool			is_not_exception(char letter, t_token_type type)
{
	if (letter == SPACE)
		return (false);
	else if (type == ENV_VAR && letter == '$')
		return (false);
	else if (type == ENV_VAR && letter == DBL_QUOTE)
		return (false);
	else if (letter == '>')
		return (false);
	else if (letter == '<')
		return (false);
	else
		return (true);
}

int				pass_space(char *text)
{
	int	count;

	count = 0;
	while (text[count] && text[count] == SPACE)
		count++;
	return (count);
}

int				pass_redir(char *instruction)
{
	int		count;
	char	redir;
	char	quote;

	count = 0;
	quote = 0;
	redir = instruction[count++];
	if (instruction[count] && instruction[count] == redir)
		count++;
	count += pass_space(instruction + count);
	while (instruction[count] && ((!quote &&
			is_not_exception(instruction[count], REDIR)) || quote))
	{
		quote = check_quote(instruction[count], quote);
		count++;
	}
	return (count);
}

bool			text_is_all_n(char *text)
{
	int	i;

	i = 0;
	while (text[i])
	{
		if (text[i] != 'n')
			return (false);
		i++;
	}
	return (true);
}

t_token_type	handle_special_case_echo(t_token *tokens, int i)
{
	if (i == 1 && (tokens[i].text[0] == '-' && text_is_all_n(tokens[i].text + 1)))
		return (FLAG);
	return (WORD);
}
