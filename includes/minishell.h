/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 21:19:42 by hjung             #+#    #+#             */
/*   Updated: 2020/12/30 00:18:13 by hjung            ###   ########.fr       */
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
# include <dirent.h>
# include <string.h>
# include <errno.h>

# include "../Libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "utils.h"

typedef struct	s_minishell
{
	pid_t			pid;
	char			*name;				//에러메시지 출력할 때 필요해서 저장해둠.
	char			*command_line;		//명령어가 저장되는 변수
	char			*path;
	char			**bin_paths;
	// t_lstcommands	*commands;			//파이프 쓸 때 명령어가 차례로 저장되는 연결리스트 
	// t_lstenv_v		*env_variables;		//환경변수가 차례로 저장되는 연결리스트
}				t_minishell;

char		*g_name;					//에러메세지 출력에 필요. ./minishell을 저장함
// t_lstenv_v	*g_envv;
pid_t		g_pid;
int			g_lastreturn;

int     ft_write(char *str);
void    sig_handle(int signo);
char    *get_cmd(char *str);

char    *ft_strndup(char *str, int size);


#endif