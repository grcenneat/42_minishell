/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeunset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 02:54:38 by hjung             #+#    #+#             */
/*   Updated: 2021/01/05 02:55:07 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_unset(t_minishell *minishell, t_lstcmd *cmd)
{
	int i;

	i = 1;
	while (cmd->argv[i])
	{
		lst_remove_env(minishell, cmd->argv[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
