/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 21:19:42 by hjung             #+#    #+#             */
/*   Updated: 2021/01/02 20:32:46 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <string.h>
# include <errno.h>

# include "../Libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "minishell_struct.h"

int     ft_write(char *str);
char    *get_cmd(char *str);

char    *ft_strndup(char *str, int size);

/*
** SIGNAL HANDLER
*/
void	sigquit_handler(int nb);
void	sigint_handler(int nb);


#endif