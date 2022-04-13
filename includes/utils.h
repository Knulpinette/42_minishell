#ifndef UTILS_H
# define UTILS_H

/* Minishell utils */
t_minishell		*get_minishell(t_minishell *minishell);
t_minishell		*init_minishell(char **envp);

/* ENV List */
t_env			*new_env_content(char *var);
t_list			*init_env_lst(char **envp);
t_list	        *copy_env_lst(t_list *original);
void			del_env_content(void *env_var);

/* ENV List getters and setters */
char			*get_env_lst_name(t_list *env_lst);
char			*get_env_lst_value(t_list *env_lst);
t_list			*get_env_lst(t_list *env_lst, char *name);
char			*get_env_value(t_list *env_lst, char *name);
void			set_env_value(t_list *env_lst, char *name, char *value);

/* Array utils */
int		        get_array_len(char **split);

/* Merge Sort Linked Lists */
void	        merge_sort(t_list **list);

/* Parsing utils - inside the parsing folder TODO check */
t_cmd_table		*init_cmd_table(int nb_cmds);
int				get_nb_tokens(const char *s, char c);
int				get_nb_redirs(char *instructions);
int				quote_len(const char *s, char c, char quote, int i);
char			*skip_space(char *line);
char			**get_cmd_paths(char **envp);
char			**finish_paths_by_slash(char **raw_paths);

/* Env Vars ($) - inside the parsing folder TODO check */
int				get_env_var_len(char *text, char delim);
char			*get_env_var(char *text, int env_var_count, char delim);

/* Free Memory utils */
void			free_minishell(t_minishell *minishell);
void			free_split(char **split);
void			free_table(t_cmd_table *cmd_table, int nb_cmds);
void			free_tokens(t_token *tokens, int nb_tokens);
void			free_redirs(t_redir *redirs, int nb_redirs);

/* Error and/or Exit utils */
int				error_and_exit(t_error code);
void			error_message(t_error code);
int				open_or_exit(char *file_path, mode_t mode);
void			*calloc_or_exit(size_t size, int count);

#endif
