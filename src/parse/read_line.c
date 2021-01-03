/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 20:49:05 by hjung             #+#    #+#             */
/*   Updated: 2021/01/03 23:08:39 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	current_line_handle(t_minishell *minishell)
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

int	read_line(t_minishell *minishell)
{
	if (!current_line_handle(minishell))
		return (0);
	// minishell->tokens = lexing(minishell->line);
	// if (!minishell->tokens)
	// 	fatal_error_exit();
	return (1);
}
