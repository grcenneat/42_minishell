/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 00:08:41 by hjung             #+#    #+#             */
/*   Updated: 2021/01/05 23:21:05 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigquit_handler(int nb)
{
	(void)nb;
	ft_putstr_fd("\b\b  \b\b", STDOUT_FILENO);
	return ;
}

void	sigint_handler(int nb)
{
	(void)nb;
	if (g_minish->executed == 1)
	{
		ft_putstr_fd("\n", 1);
		g_minish->executed = 0;
	}
	else
	{
		write(STDOUT_FILENO, "\b\b  \n", 5);
		g_minish->eof = 0;
		prompt_msg();
		g_minish->excode = 1;
	}
}
