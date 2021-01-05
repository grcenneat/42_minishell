/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 18:51:05 by hjung             #+#    #+#             */
/*   Updated: 2021/01/06 01:09:25 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt_msg(void)
{
	ft_putstr_fd("MINISHELL$ ", 1);
}

int		main(int argc, char *argv[], char *envp[])
{
	t_minishell minishell;

	(void)argc;
	(void)argv;
	g_minish = &minishell;
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	init_env(&minishell, envp);
	minishell.line = ft_strdup("");
	while (1)
	{
		prompt_msg();
		if (!read_line(&minishell))
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
