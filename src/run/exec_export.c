/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 02:46:41 by hjung             #+#    #+#             */
/*   Updated: 2021/01/05 02:57:32 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void
	print_export(t_lstenv *env)
{
	while (env)
	{
		ft_putstr_fd(env->key, 1);
		if (env->value != NULL)
		{
			ft_putstr_fd("=", 1);
			ft_putstr_fd(env->value, 1);
		}
		ft_putstr_fd("\n", 1);
		env = env->next;
	}
}

static int
	idententifier_error(char *ident)
{
	ft_putstr_fd("minishell: export: '", 2);
	ft_putstr_fd(ident, 2);
	ft_putstr_fd("': not a valid identifier", 2);
	ft_putstr_fd("\n", 2);
	return (EXIT_FAILURE);
}

static void
	check_arg_and_export(t_minishell *minishell, t_lstcmd *cmd, int i, int *ret)
{
	int end;
	int copy;

	end = 0;
	copy = 1;
	if (cmd->argv[i][0] == '\0')
		*ret = idententifier_error(cmd->argv[i]);
	else if (ft_strchr(cmd->argv[i], '='))
	{
		if (cmd->argv[i][0] == '=' && !(copy = 0))
			*ret = idententifier_error(cmd->argv[i]);
		while (cmd->argv[i][end] != '=')
			if (ft_haschr("\"\' ", cmd->argv[i][end++]) && !(copy = 0))
			{
				*ret = idententifier_error(cmd->argv[i]);
				break ;
			}
		if (copy)
		{
			cmd->argv[i][end] = '\0';
			lst_chk_and_add_env(minishell, cmd->argv[i], &cmd->argv[i][++end]);
		}
	}
	else
		lst_chk_and_add_env(minishell, cmd->argv[i], NULL);
}

int	exec_export(t_minishell *minishell, t_lstcmd *cmd)
{
	int i;
	int ret;

	i = 0;
	ret = EXIT_SUCCESS;
	if (!cmd->argv[1])
		print_export(minishell->env);
	while (cmd->argv[++i])
		check_arg_and_export(minishell, cmd, i, &ret);
	return (ret);
}
