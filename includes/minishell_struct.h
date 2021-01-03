/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 00:17:46 by hjung             #+#    #+#             */
/*   Updated: 2021/01/03 20:21:26 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCT_H
# define MINISHELL_STRUCT_H

typedef	struct		s_lstenv
{
	char			*key;
	char			*value;
	struct s_lstenv	*next;
}					t_lstenv;

typedef struct	s_minishell
{
	char			*name;				//에러메시지 출력할 때 필요해서 저장해둠.
	char			*command_line;		//명령어가 저장되는 변수
	char			*path;
	char			**bin_paths;
	// t_lstcommands	*commands;			//파이프 쓸 때 명령어가 차례로 저장되는 연결리스트 
	t_lstenv		*env;		//환경변수가 차례로 저장되는 연결리스트
}				t_minishell;

char		*g_name;					//에러메세지 출력에 필요. ./minishell을 저장함
// t_lstenv_v	*g_envv;
pid_t		g_pid;
int			g_lastreturn;

#endif