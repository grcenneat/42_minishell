/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 23:24:21 by hjung             #+#    #+#             */
/*   Updated: 2021/01/04 23:33:12 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_rdir
	*lst_new_rdir(char *file, int is_dbl)
{
	t_rdir *new;

	new = malloc(sizeof(t_rdir));
	new->file = ft_strdup(file);
	new->std = -1;
	new->is_dbl = is_dbl;
	new->next = NULL;
	return (new);
}

t_rdir
	*lst_last_rdir(t_rdir *begin)
{
	while (begin->next)
		begin = begin->next;
	return (begin);
}

static t_rdir
	*lst_add_rdir(t_rdir *begin, char *file, int is_dbl)
{
	t_rdir *last;

	if (!begin)
		return (lst_new_rdir(file, is_dbl));
	last = lst_last_rdir(begin);
	last->next = lst_new_rdir(file, is_dbl);
	return (begin);
}

void
	lst_add_redir_cmd(t_lstcmd *cmd, char *redir, char *file)
{
	t_lstcmd *last;

	last = lst_last_cmd(cmd);
	last->is_rdir = 1;
	if (!ft_strncmp(redir, "<", 1))
		last->in = lst_add_rdir(last->in, file, 0);
	else if (!ft_strncmp(redir, ">", 1))
		last->out = lst_add_rdir(last->out, file, 0);
	else if (!ft_strncmp(redir, ">>", 1))
		last->out = lst_add_rdir(last->out, file, 1);
}
