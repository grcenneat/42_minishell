/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 20:16:02 by hjung             #+#    #+#             */
/*   Updated: 2021/01/04 21:53:14 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void
	free_tokens(t_minishell *minishell)
{
	char	**tokens;
	int		i;

	tokens = minishell->tokens;
	if (tokens)
	{
		i = 0;
		while (tokens[i])
			free(tokens[i++]);
		free(tokens);
		minishell->tokens = 0;
	}
}

void
	free_line(t_minishell *minishell)
{
	if (minishell->line)
		free(minishell->line);
	minishell->line = NULL;
}

static void
	free_rdir(t_lstcmd *cmd)
{
	t_rdir *tmp;

	tmp = cmd->in;
	while (cmd->in)
	{
		free(cmd->in->file);
		tmp = cmd->in->next;
		free(cmd->in);
		cmd->in = tmp;
	}
	tmp = cmd->out;
	while (cmd->out)
	{
		free(cmd->out->file);
		tmp = cmd->out->next;
		free(cmd->out);
		cmd->out = tmp;
	}
}

void
	free_cmd(t_minishell *minishell)
{
	t_lstcmd	*cmd;
	t_lstcmd	*tmp;
	int			i;

	free_line(minishell);
	free_tokens(minishell);
	cmd = minishell->cmd;
	while (cmd)
	{
		tmp = cmd->next;
		if (cmd->argv)
		{
			i = -1;
			while (cmd->argv[++i])
				free(cmd->argv[i]);
			free(cmd->argv);
		}
		free_rdir(cmd);
		free(cmd);
		cmd = tmp;
	}
	minishell->cmd = 0;
}
