/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 02:30:52 by hjung             #+#    #+#             */
/*   Updated: 2021/01/05 02:31:13 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void
	open_redirection(t_lstcmd *cmd)
{
	t_rdir *last;

	if (cmd->in)
	{
		last = lst_last_rdir(cmd->in);
		last->std = dup(0);
		dup2(last->fd, 0);
	}
	if (cmd->out)
	{
		last = lst_last_rdir(cmd->out);
		last->std = dup(1);
		dup2(last->fd, 1);
	}
}

void
	close_redirection(t_lstcmd *cmd)
{
	t_rdir	*last;

	if (cmd->in)
	{
		last = lst_last_rdir(cmd->in);
		dup2(last->std, 0);
		close(last->std);
	}
	if (cmd->out)
	{
		last = lst_last_rdir(cmd->out);
		dup2(last->std, 1);
		close(last->std);
	}
}
