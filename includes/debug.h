#ifndef DEBUG_H
# define DEBUG_H

void	print_split(char **split);
void	print_tokens(t_token *tokens, int words);
void	print_redirs(t_redir *redirs, int args);
void	print_debug(void);

#endif