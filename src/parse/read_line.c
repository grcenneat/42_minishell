/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 20:49:05 by hjung             #+#    #+#             */
/*   Updated: 2021/01/05 20:52:04 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int
	previous_is_eof(t_minishell *minishell)
{
	char		*bef_line;
	char		*new_line;

	new_line = 0;
	if ((minishell->ret = get_next_line(0, &new_line)) < 0)
		fatal_error_exit();
	bef_line = minishell->eof ? minishell->line : "";
	if (!(minishell->line = ft_strjoin(bef_line, new_line)))
		fatal_error_exit();
	if (minishell->eof)
		free(bef_line);
	free(new_line);
	if (minishell->ret > 0)
		minishell->eof = 0;
	if (minishell->ret == 0)
	{
		ft_putstr_fd("  \b\b", 1);
		return (0);
	}
	return (1);
}

static int
	current_line_handle(t_minishell *minishell)
{
	minishell->ret = get_next_line(0, &(minishell->line));
	if (minishell->ret == -1)
		fatal_error_exit();
	if ((minishell->ret == 0 && ft_strlen(minishell->line)))
	{
		ft_putstr_fd("  \b\b", 1);
		return (0);
	}
	if (minishell->ret == 0 && !ft_strlen(minishell->line))
	{
		ft_putstr_fd("  \b\b", 1);
		eof_exit();
	}
	return (1);
}

int
	read_line(t_minishell *minishell)
{
	if (minishell->eof)
	{
		if (!previous_is_eof(minishell))
			return (0);
	}
	else
	{
		if (!current_line_handle(minishell))
			return (0);
	}
	minishell->tokens = lexing(minishell->line);
	if (!minishell->tokens)
		fatal_error_exit();
	return (1);
}
