/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 20:11:24 by hjung             #+#    #+#             */
/*   Updated: 2021/01/04 23:19:38 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void
	lst_add_ispipe_cmd(t_lstcmd *cmd)
{
	t_lstcmd *last;

	last = lst_last_cmd(cmd);
	last->is_pipe = 1;
}

static int
	count_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

static void
	lst_add_argv_cmd(t_lstcmd *cmd, char *arg)
{
	t_lstcmd	*last;
	int			cnt;
	char		**new_arr;
	int			i;

	last = lst_last_cmd(cmd);
	cnt = count_arr(last->argv);
	new_arr = malloc(sizeof(char*) * (cnt + 2));
	i = 0;
	while (i < cnt)
	{
		new_arr[i] = last->argv[i];
		i++;
	}
	new_arr[i] = ft_strdup(arg);
	new_arr[cnt + 1] = NULL;
	free(last->argv);
	last->argv = new_arr;
}

int	init_cmd_list(t_minishell *minishell, char **tokens)
{
	int			i;
	int			fnew;

	if (!ck_tokens(tokens))
		return (0);
	minishell->cmd = 0;
	i = 0;
	fnew = 1;
	while (tokens[i])
	{
		if (fnew && !(fnew = 0))
			minishell->cmd = lst_add_cmd(minishell->cmd, tokens[i]);
		else if ((!ft_strncmp(tokens[i], "|", 1)) && (fnew = 1))
			lst_add_ispipe_cmd(minishell->cmd);
		else if (is_redir(tokens[i]) && (i++))
			lst_add_redir_cmd(minishell->cmd, tokens[i - 1], tokens[i]);
		else if ((!ft_strncmp(tokens[i], ";", 1)) && (fnew = 1) && (i++))
			continue;
		else
			lst_add_argv_cmd(minishell->cmd, tokens[i]);
		i++;
	}
	return (1);
}
