/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 00:13:56 by hjung             #+#    #+#             */
/*   Updated: 2021/01/05 03:19:42 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char
	**get_built_in(void)
{
	static char *built_in[8] = {
		"echo",
		"cd",
		"pwd",
		"export",
		"unset",
		"env",
		"exit",
		NULL
	};

	return (built_in);
}

int
	is_built_in(char *arg)
{
	char		**btin_arr;
	int			i;

	btin_arr = get_built_in();
	i = 0;
	while (btin_arr[i])
	{
		if (!ft_strcmp(btin_arr[i], arg))
			return (i);
		i++;
	}
	return (-1);
}

int
	exec_built_in(t_minishell *minishell, int btin_nb, t_lstcmd *cmd)
{
	int			ret;

	ret = -1;
	if (!check_dollar(minishell, cmd))
		return (EXIT_FAILURE);
	open_redirection(cmd);
	if (btin_nb == 0)
		ret = exec_echo(cmd);
	else if (btin_nb == 1)
		ret = exec_cd(minishell, cmd);
	else if (btin_nb == 2)
		ret = exec_pwd(cmd);
	else if (btin_nb == 3)
		ret = exec_export(minishell, cmd);
	else if (btin_nb == 4)
		ret = exec_unset(minishell, cmd);
	else if (btin_nb == 5)
		ret = exec_env(minishell, cmd);
	else if (btin_nb == 6)
		ret = exec_exit(minishell, cmd);
	close_redirection(cmd);
	return (ret);
}

static void
	non_built_in_fork_and_wait(t_minishell *minishell, t_lstcmd *cmd)
{
	pid_t		child_pid;
	int			status;

	if ((child_pid = fork()) == -1)
		fatal_error_exit();
	else if (child_pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		exec_non_built_in(minishell, cmd);
	}
	else if (child_pid > 0)
	{
		wait(&status);
		get_exit_code(minishell, status, NO_EXCODE);
	}
}

void
	exec_command(t_minishell *minishell)
{
	t_lstcmd	*cmd;
	int			btin_nb;

	cmd = minishell->cmd;
	minishell->executed = 1;
	while (cmd)
	{
		if (cmd->is_pipe)
		{
			cmd = piping(minishell, cmd);
			continue ;
		}
		if ((btin_nb = is_built_in(cmd->argv[0])) != -1)
			get_exit_code(minishell, NO_STATUS, \
						exec_built_in(minishell, btin_nb, cmd));
		else
			non_built_in_fork_and_wait(minishell, cmd);
		cmd = cmd->next;
	}
	minishell->executed = 0;
}
