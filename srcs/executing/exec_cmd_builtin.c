#include "minishell.h"

int is_builtin(char *cmd_name)
{
    if (ft_strncmp(cmd_name, "cd", 2) == 0
        || ft_strncmp(cmd_name, "pwd", 3) == 0
        || ft_strncmp(cmd_name, "env", 3) == 0
        || ft_strncmp(cmd_name, "echo", 4) == 0
        || ft_strncmp(cmd_name, "export", 6) == 0
        || ft_strncmp(cmd_name, "unset", 5) == 0
        || ft_strncmp(cmd_name, "exit", 4) == 0)
        return (1);
    return (0);
}

int exec_builtin(t_minishell *minishell, t_cmd_table *cmd)
{
    if (ft_strncmp(cmd->cmd_name, "cd", 2) == 0)
       return (cd(cmd));
    if (ft_strncmp(cmd->cmd_name, "pwd", 3) == 0)
        return (pwd(cmd));
    if (ft_strncmp(cmd->cmd_name, "env", 3) == 0)
        return (env(cmd, minishell));
    if (ft_strncmp(cmd->cmd_name, "echo", 4) == 0)
        return (echo(cmd));
    if (ft_strncmp(cmd->cmd_name, "export", 6) == 0)
        return (export(cmd, minishell));
    if (ft_strncmp(cmd->cmd_name, "unset", 5) == 0)
        return (unset(cmd, minishell));
    if (ft_strncmp(cmd->cmd_name, "exit", 4) == 0)
    {
        printf("EXIT is still not done 😅\n");
        return (0);
    }
    return (-1);
}