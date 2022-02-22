#ifndef MINISHELL_H
# define MINISHELL_H

/* Write DEBUG(print_tokens(get_minishell(NULL));) and that line
 * will only be happening if you "make debug"
 */
# ifdef DEBUG_MODE
#  define DEBUG(x) x
# else
#  define DEBUG(x)
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <limits.h>
# include <string.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../42_00_libft/libft.h"
# include "colors.h"
# include "struct_def.h"
# include "utils.h"
# include "debug.h"

void	parse(char *line);

#endif

