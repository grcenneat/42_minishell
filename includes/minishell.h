/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 21:19:42 by hjung             #+#    #+#             */
/*   Updated: 2021/01/05 03:35:15 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define BUFFSIZE 128
# define WHITE_SPACE " tnvfr"
# define SEP_SPACE " \t<>|;"
# define SEP "<>|;"
# define SPACE " \t"
# define PATH_MAX 1024
# define LINE_MAX 100024
# define NO_EXCODE -1
# define NO_STATUS -1

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
void		lst_remove_env(t_minishell *minishell, char *key);
void		lst_chk_and_add_env(t_minishell *minishell, char *key, char *value);
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
** RUN
*/
void		exec_command(t_minishell *minishell);
int			is_built_in(char *arg);
int			exec_built_in(t_minishell *minishell, int btin_nb, t_lstcmd *cmd);
void		open_redirection(t_lstcmd *cmd);
void		close_redirection(t_lstcmd *cmd);
void		exec_non_built_in(t_minishell *minishell, t_lstcmd *cmd);

/*
**	dollar symbol
*/
int			check_dollar(t_minishell *minishell, t_lstcmd *cmd);
char		*check_quote(t_minishell *minishell, char *tk, int i);
int			check_outrdir_dollar(t_minishell *minishell, t_rdir *out);
int			check_inrdir_dollar(t_minishell *minishell, t_rdir *in);

/*
** BUILT_IN
*/
int			exec_echo(t_lstcmd *cmd);
int			exec_cd(t_minishell *minishell, t_lstcmd *cmd);
int			count_arg(char **argv);
char		*lst_find_env(t_minishell *minishell, char *key);
int			exec_pwd(t_lstcmd *cmd);
int			exec_export(t_minishell *minishell, t_lstcmd *cmd);
int			exec_unset(t_minishell *minishell, t_lstcmd *cmd);
int			exec_env(t_minishell *minishell, t_lstcmd *cmd);
int			exec_exit(t_minishell *minishell, t_lstcmd *cmd);

/*
** PIPE
*/
t_lstcmd	*piping(t_minishell *minishell, t_lstcmd *cmd);
int			count_pipes(t_lstcmd *begin);
void		create_pipes(int pipes[], int nb);
void		close_all(int pipes[], int nb);
void		close_pipe_and_wait(t_minishell *minishell, int pipes[], int nb, int cpid[]);
void		dup2_and_close_pipe(int pipes[], int i, int nb);

/*
** UTILS
*/
void		sigquit_handler(int nb);
void		sigint_handler(int nb);
void		eof_exit(void);
void		fatal_error_exit(void);
void		get_exit_code(t_minishell *minishell, int status, int excode);
int			ft_haschr(const char *s, char c);
int			ft_strcmp(const char *s1, const char *s2);
char		**lst_env_to_char(t_lstenv *env);

/*
** ERROR
*/
int			syntax_error(char *token, int ret);
int			no_command_error(char *cmd, int ret);
int			too_many_arg_error(char *cmd, int ret);
int			no_file_error(char *cmd, char *file, int ret);
int			numeric_arg_error(t_minishell *minishell, 
						char *cmd, char *file, int ret);
int			file_too_long(char *cmd, char *file, int ret);

/*
** FREE
*/
void		free_cmd(t_minishell *minishell);
void		free_line(t_minishell *minishell);
void		free_all(t_minishell *minishell);

#endif