/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 03:09:32 by hjung             #+#    #+#             */
/*   Updated: 2021/01/05 20:52:50 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void
	free_env(t_minishell *minishell)
{
	t_lstenv *env;
	t_lstenv *tmp;

	env = minishell->env;
	while (env)
	{
		tmp = env->next;
		free(env->key);
		free(env->value);
		free(env);
		env = tmp;
	}
}

void
	free_all(t_minishell *minishell)
{
	free_cmd(minishell);
	free_env(minishell);
}
