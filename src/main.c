/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 18:51:05 by hjung             #+#    #+#             */
/*   Updated: 2021/01/05 03:15:12 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_write(char *str)
{
	int len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

void	prompt_msg(void)
{
	ft_putstr_fd("MINISHELL$ ", 1);
}

char	*get_cmd(char *str)
{
	int i;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		    break;
        i++;
	}
	if (i > 0)
		return (ft_strndup(str, i));
	return (ft_strdup(""));
}

/*
** 환경변수와 shell의 실제 path를 초기화하고 prompt 대기
*/
#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
	(void)argc;
    (void)argv;
    t_minishell minishell;

	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
    init_env(&minishell, envp);

	while (1)
    {
        prompt_msg();
        if(!read_line(&minishell))
            continue;
        if (!init_cmd_list(&minishell, minishell.tokens))
        {
			free_cmd(&minishell);
			continue ;
		}
        exec_command(&minishell);
        free_cmd(&minishell);
    }
	return (0);
}