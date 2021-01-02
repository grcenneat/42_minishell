/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 21:19:42 by hjung             #+#    #+#             */
/*   Updated: 2021/01/02 22:33:17 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define BUFFSIZE 128

# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <string.h>
# include <errno.h>

# include "../Libft/libft.h"
# include "minishell_struct.h"

int     ft_write(char *str);
char    *get_cmd(char *str);

/*
** GET_NEXT_LINE
*/
int		ft_strnlen(char *str);
char	*ft_strnjoin(char *s1, char *s2);
char	*ft_strndup(char *str, int size);
char	*ft_strnchr(char *s, char target);
void	ft_strcpy(char *dest, char *src, int size);

int		to_line(char **line, char *nl, char **fd_set, char *tmp_buff);
int		get_next_line(int fd, char **line);

/*
** SIGNAL HANDLER
*/
void	sigquit_handler(int nb);
void	sigint_handler(int nb);


#endif