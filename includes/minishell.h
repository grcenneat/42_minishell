/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 21:19:42 by hjung             #+#    #+#             */
/*   Updated: 2021/01/04 23:29:21 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define BUFFSIZE 128
# define SEP_SPACE " \t<>|;"
# define SEP "<>|;"
# define SPACE " \t"

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
** lst_env
*/
void		init_env(t_minishell *minishell, char **envp);
// void		lst_remove_env(char *key);
// void		lst_check_and_add_env(char *key, char *value);
t_lstenv	*lst_last_env(t_lstenv *begin);
t_lstenv	*lst_add_env(t_lstenv *begin, char *key, char *value);
t_lstenv	*lst_new_env(char *key, char *value);

/*
** GET_NEXT_LINE
*/
int			ft_strnlen(char *str);
char		*ft_strnjoin(char *s1, char *s2);
char		*ft_strndup(char *str, int size);
char		*ft_strnchr(char *s, char target);
void		ft_strcpy(char *dest, char *src, int size);

int			to_line(char **line, char *nl, char **fd_set, char *tmp_buff);
int			get_next_line(int fd, char **line);

/*
** READ_LINE
*/
int			read_line(t_minishell *minishell);
char		**lexing(char *line);
int			jmp_quotes(char *line, int i);
int			check_sep(char *line, int i, int use);
int			jump_space(char *line, int i, int jmp);

/*
** lst_cmd
*/
int			init_cmd_list(t_minishell *minishell, char **tokens);
t_lstcmd	*lst_new_cmd(char *token);
t_lstcmd	*lst_add_cmd(t_lstcmd *begin, char *token);
t_lstcmd	*lst_last_cmd(t_lstcmd *cmd);

/*
** PARSE
**/
int			ck_tokens(char **tokens);
int			is_redir(char *s);
void		lst_add_redir_cmd(t_lstcmd *cmd, char *redir, char *file);
t_rdir		*lst_last_rdir(t_rdir *begin);

/*
** UTILS
*/
void		sigquit_handler(int nb);
void		sigint_handler(int nb);
void		eof_exit(void);
void		fatal_error_exit(void);
int			ft_haschr(const char *s, char c);

/*
** ERROR
*/
int			syntax_error(char *token, int ret);

/*
** FREE
*/
void		free_cmd(t_minishell *minishell);
void		free_line(t_minishell *minishell);
	

#endif