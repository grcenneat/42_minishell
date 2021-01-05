/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:02:46 by hjung             #+#    #+#             */
/*   Updated: 2021/01/05 20:53:23 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	eof_exit(void)
{
	ft_putstr_fd("\n", 1);
	exit(0);
}

void	fatal_error_exit(void)
{
	ft_putstr_fd("minishell: fatal error : ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void	get_exit_code(t_minishell *minishell, int status, int excode)
{
	if (excode == -1)
	{
		if (WIFEXITED(status))
			minishell->excode = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			minishell->excode = 128 + WTERMSIG(status);
	}
	else
		minishell->excode = excode;
}
