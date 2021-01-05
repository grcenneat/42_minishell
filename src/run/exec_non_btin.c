/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_non_btin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 03:18:26 by hjung             #+#    #+#             */
/*   Updated: 2021/01/05 20:46:04 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char
	**create_path_arr(t_minishell *minishell)
{
	t_lstenv	*env;
	char		*path_env;
	char		**path_arr;

	env = minishell->env;
	path_env = 0;
	while (env)
	{
		if (!ft_strcmp(env->key, "PATH"))
			path_env = env->value;
		env = env->next;
	}
	if (!path_env)
		return (0);
	path_arr = ft_split(path_env, ':');
	return (path_arr);
}

static void
	free_path_arr(char **path_arr)
{
	int i;

	i = 0;
	while (path_arr[i])
	{
		free(path_arr[i]);
		i++;
	}
	free(path_arr);
}

static void
	free_tmp_env(char **env)
{
	int i;

	i = 0;
	if (env)
	{
		while (env[i])
			free(env[i++]);
		free(env);
	}
}

static void
	exec_with_path(t_minishell *minishell, t_lstcmd *cmd, char **path_arr)
{
	char	*path_cmd1;
	char	*path_cmd2;
	char	**tmp_env;
	int		i;

	i = 0;
	while (path_arr[i])
	{
		path_cmd1 = ft_strjoin(path_arr[i], "/");
		path_cmd2 = ft_strjoin(path_cmd1, cmd->argv[0]);
		tmp_env = lst_env_to_char(minishell->env);
		execve(path_cmd2, cmd->argv, tmp_env);
		free_tmp_env(tmp_env);
		free(path_cmd1);
		free(path_cmd2);
		i++;
	}
}

void
	exec_non_built_in(t_minishell *minishell, t_lstcmd *cmd)
{
	char	**path_arr;

	if (!check_dollar(minishell, cmd))
		exit(EXIT_FAILURE);
	open_redirection(cmd);
	if (!cmd->has_path && (path_arr = create_path_arr(minishell)))
	{
		exec_with_path(minishell, cmd, path_arr);
		free_path_arr(path_arr);
		exit(no_command_error(cmd->argv[0], 127));
	}
	else
	{
		execve(cmd->argv[0], cmd->argv, lst_env_to_char(minishell->env));
		exit(no_file_error(cmd->argv[0], NULL, 1));
	}
}
