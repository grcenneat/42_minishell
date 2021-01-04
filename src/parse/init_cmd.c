/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 20:11:24 by hjung             #+#    #+#             */
/*   Updated: 2021/01/04 20:12:04 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static void
	lst_add_ispipe_cmd(t_cmd *cmd)
{
	t_cmd *last;

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
	lst_add_argv_cmd(t_cmd *cmd, char *arg)
{
	t_cmd	*last;
	int		cnt;
	char	**new_arr;
	int		i;

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

int	init_cmd_list(char **tokens)
{
	t_minish	*minish;
	int			i;
	int			fnew;

	if (!ck_tokens(tokens))
		return (0);
	minish = get_minish();
	minish->cmd = 0;
	i = 0;
	fnew = 1;
	while (tokens[i])
	{
		if (fnew && !(fnew = 0))
			minish->cmd = lst_add_cmd(minish->cmd, tokens[i]);
		else if (ft_strequ(tokens[i], "|") && (fnew = 1))
			lst_add_ispipe_cmd(minish->cmd);
		else if (is_redir(tokens[i]) && (i++))
			lst_add_redir_cmd(minish->cmd, tokens[i - 1], tokens[i]);
		else if (ft_strequ(tokens[i], ";") && (fnew = 1) && (i++))
			continue;
		else
			lst_add_argv_cmd(minish->cmd, tokens[i]);
		i++;
	}
	return (1);
}
