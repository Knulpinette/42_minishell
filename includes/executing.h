#ifndef EXECUTING_H
# define EXECUTING_H

/* EXECUTOR */
int		execute(t_minishell *minishell);

/* EXECUTE REDIRECTIONS */
int		exec_redirs(t_cmd_table *cmd);

/* EXECUTE COMMANDS */
int		is_builtin(char *cmd_name);
int		exec_builtin(t_minishell *minishell, t_cmd_table *cmd);
void    exec_system(t_minishell *minishell, t_cmd_table *cmd);

#endif