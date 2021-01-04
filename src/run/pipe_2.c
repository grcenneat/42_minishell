/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 01:32:49 by hjung             #+#    #+#             */
/*   Updated: 2021/01/05 02:26:19 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int
	count_pipes(t_lstcmd *begin)
{
	int i;

	i = 0;
	while (begin)
	{
		if (begin->is_pipe)
			i++;
		else
			break ;
		begin = begin->next;
	}
	return (i);
}

void
	create_pipes(int pipes[], int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		if (pipe(pipes + (i * 2)) == -1)
			fatal_error_exit();
		i++;
	}
}

void
	close_all(int pipes[], int nb)
{
	int i;

	i = 0;
	while (i < 2 * nb)
		close(pipes[i++]);
}

void
	close_pipe_and_wait(t_minishell *minishell, int pipes[], int nb, int cpid[])
{
	int status;
	int	i;

	close_all(pipes, nb);
	i = 0;
	while (i < nb + 1)
	{
		waitpid(cpid[i], &status, 0);
		i++;
	}
	get_exit_code(minishell, status, NO_EXCODE);
}

void
	dup2_and_close_pipe(int pipes[], int i, int nb)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (i < nb)
		dup2(pipes[i * 2 + 1], 1);
	if (i > 0)
		dup2(pipes[(i - 1) * 2], 0);
	close_all(pipes, nb);
}
