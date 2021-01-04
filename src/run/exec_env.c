/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 16:15:01 by hjung             #+#    #+#             */
/*   Updated: 2021/01/05 03:04:29 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void
	print_env(t_lstenv *env)
{
	while (env)
	{
		if (env->value != NULL)
		{
			ft_putstr_fd(env->key, 1);
			ft_putstr_fd("=", 1);
			ft_putstr_fd(env->value, 1);
			ft_putstr_fd("\n", 1);
		}
		env = env->next;
	}
}

int
	exec_env(t_minishell *minishell, t_lstcmd *cmd)
{
	(void)cmd;
	print_env(minishell->env);
	return (EXIT_SUCCESS);
}
