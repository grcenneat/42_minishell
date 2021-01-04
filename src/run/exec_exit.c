/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:53:24 by hjung             #+#    #+#             */
/*   Updated: 2021/01/05 03:29:02 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int
	check_str_digit(char *s)
{
	while (s && *s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int
	exec_exit(t_minishell *minishell, t_lstcmd *cmd)
{
	int		cnt;
	int		fdigit;
	char	ret;

	cnt = count_arg(cmd->argv);
	fdigit = check_str_digit(cmd->argv[1]);
	if (cmd->argv[1])
	{
		if (!fdigit)
		{
			ft_putstr_fd("exit\n", 1);
			exit(numeric_arg_error(minishell, cmd->argv[0], cmd->argv[1], 2));
		}
		if (cnt > 2)
		{
			ft_putstr_fd("exit\n", 1);
			return (too_many_arg_error(cmd->argv[0], 1));
		}
		ret = (char)ft_atoi(cmd->argv[1]);
		free_all(minishell);
		exit(ret);
	}
	free_all(minishell);
	exit(EXIT_SUCCESS);
}
