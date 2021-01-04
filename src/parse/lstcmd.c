/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstcmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 21:56:27 by hjung             #+#    #+#             */
/*   Updated: 2021/01/04 23:35:06 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lstcmd
	*lst_new_cmd(char *token)
{
	t_lstcmd	*new;

	new = malloc(sizeof(t_lstcmd));
	new->argv = malloc(sizeof(char*) * 2);
	new->argv[0] = ft_strdup(token);
	new->argv[1] = NULL;
	new->is_pipe = 0;
	new->is_rdir = 0;
	if (ft_strchr(new->argv[0], '/'))
		new->has_path = 1;
	else
		new->has_path = 0;
	new->in = NULL;
	new->out = NULL;
	new->next = NULL;
	return (new);
}

t_lstcmd
	*lst_add_cmd(t_lstcmd *begin, char *token)
{
	t_lstcmd	*tmp;

	if (!begin)
		return (lst_new_cmd(token));
	else
	{
		tmp = begin;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = lst_new_cmd(token);
	}
	return (begin);
}

t_lstcmd
	*lst_last_cmd(t_lstcmd *cmd)
{
	t_lstcmd	*last;

	last = cmd;
	while (last->next)
		last = last->next;
	return (last);
}