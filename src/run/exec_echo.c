/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 02:33:22 by hjung             #+#    #+#             */
/*   Updated: 2021/01/05 02:34:52 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void
	print_arg(char **argv, int i, int cnt)
{
	while (argv[i])
	{
		ft_putstr(argv[i]);
		if (i < cnt - 1)
			ft_putstr(" ");
		i++;
	}
}

int
	exec_echo(t_lstcmd *cmd)
{
	int cnt;

	cnt = count_arg(cmd->argv);
	if (cnt > 2 && !ft_strcmp(cmd->argv[1], "-n"))
		print_arg(cmd->argv, 2, cnt);
	else
	{
		print_arg(cmd->argv, 1, cnt);
		ft_putstr_fd("\n", 1);
	}
	return (EXIT_SUCCESS);
}
