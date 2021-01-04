/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 02:35:44 by hjung             #+#    #+#             */
/*   Updated: 2021/01/05 02:40:52 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char
	*lst_find_env(t_minishell *minishell, char *key)
{
	t_lstenv	*env;

	env = minishell->env;
	while (env)
	{
		if (!ft_strcmp(env->key, key))
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

int
	count_arg(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int
	exec_cd(t_minishell *minishell, t_lstcmd *cmd)
{
	char	cwd[PATH_MAX];
	int		cnt;
	char	*value;

	cnt = count_arg(cmd->argv);
	if (cnt == 1)
		chdir("/");
	else if (cnt > 3)
		return (too_many_arg_error(cmd->argv[0], EXIT_FAILURE));
	else if (ft_strlen(cmd->argv[1]) > PATH_MAX)
		return (file_too_long(cmd->argv[0], cmd->argv[1], EXIT_FAILURE));
	else
	{
		if (ft_strequ(cmd->argv[1], "~"))
			value = lst_find_env(minishell, "HOME");
		else
			value = cmd->argv[1];
		if (chdir(value) == -1)
			return (no_file_error(cmd->argv[0], cmd->argv[1], EXIT_FAILURE));
		else
			lst_check_and_add_env("PWD", getcwd(cwd, sizeof(cwd)));
	}
	return (EXIT_SUCCESS);
}
