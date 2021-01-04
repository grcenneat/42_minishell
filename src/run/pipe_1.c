/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 00:18:20 by hjung             #+#    #+#             */
/*   Updated: 2021/01/05 02:25:54 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lstcmd
	*piping(t_minishell *minishell, t_lstcmd *cmd)
{
	int pipes[count_pipes(cmd) * 2];
	int nb;
	int i;
	int btin_nb;
	int cpid[count_pipes(cmd) + 1];

	nb = count_pipes(cmd);
	create_pipes(pipes, nb);
	i = 0;
	while (i < (nb + 1))
	{
		if ((cpid[i] = fork()) == 0)
		{
			dup2_and_close_pipe(pipes, i, nb);
			if ((btin_nb = is_built_in(cmd->argv[0])) != -1)
				exit(exec_built_in(minishell, btin_nb, cmd));
			exec_non_built_in(cmd);
		}
		else if (cpid[i] == -1)
			fatal_error_exit();
		cmd = cmd->next;
		i++;
	}
	close_pipe_and_wait(minishell, pipes, nb, cpid);
	return (cmd);
}
