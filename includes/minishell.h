#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include "../Libft/libft.h"
# include "../get_next_line/get_next_line.h"

int     ft_write(char *str);
void    sig_handle(int signo);
char    *get_cmd(char *str);

char    *ft_strndup(char *str, int size);
size_t  ft_strlen(const char *str);
char    *ft_strdup(const char *src);
char    *ft_strjoin(char const *s1, char const *s2);
char    **ft_split(char const *s, char c);

#endif