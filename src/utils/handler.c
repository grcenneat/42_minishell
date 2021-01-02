/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 00:08:41 by hjung             #+#    #+#             */
/*   Updated: 2021/01/02 22:33:28 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	sigquit_handler(int nb)
{
	(void)nb;
	ft_putstr_fd("\b\b  \b\b", STDOUT_FILENO);
	return ;
}

void	sigint_handler(int nb)
{
	(void)nb;
	if (write(STDOUT_FILENO, "\b\b  \n", 5) < 0)
		return ;
	ft_putstr_fd("minishell$ ", STDOUT_FILENO);
}
