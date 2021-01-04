/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 02:04:14 by hjung             #+#    #+#             */
/*   Updated: 2021/01/05 03:25:20 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int
	get_key(char key[], char *arg)
{
	int i;

	i = 0;
	while (arg[i] && !ft_haschr(" $\"\'=\\", arg[i]))
	{
		key[i] = arg[i];
		i++;
	}
	key[i] = '\0';
	return (i);
}

static int
	change_env_to_value(t_minishell *minishell,
						char *arg, char *buff, int *j)
{
	char	key[100];
	char	*value;
	char	*tmp;
	int		ret;

	ret = 0;
	if (*arg == '$' && *(arg + 1) == '?')
	{
		ret = 1;
		tmp = ft_itoa(minishell->excode);
		*j = ft_strlcat(buff, tmp, LINE_MAX) - 1;
		free(tmp);
	}
	else if (*arg == '$' && (!*(arg + 1) || *(arg + 1) == ' '))
		buff[++*j] = *arg;
	else
	{
		ret = get_key(key, ++arg);
		value = lst_find_env(minishell, key);
		*j = ft_strlcat(buff, value, LINE_MAX) - 1;
	}
	return (ret);
}

static int
	check_backslash(char *tk, char *buff, int *j, int quotes)
{
	int ret;

	ret = 0;
	if (*tk == '\\' && quotes)
	{
		ret = 1;
		if (ft_haschr("$\'\"\\", tk[1]))
			buff[++*j] = *(++tk);
		else
		{
			buff[++*j] = *tk;
			buff[++*j] = *(++tk);
		}
	}
	else if (*tk == '\\')
	{
		ret = 1;
		buff[++*j] = *(++tk);
	}
	else
		buff[++*j] = *tk;
	return (ret);
}

char
	*check_quote(t_minishell *minishell, char *tk, int i)
{
	char	buff[LINE_MAX];
	int		j;

	j = -1;
	ft_memset(buff, 0, LINE_MAX);
	while (tk[++i])
		if (tk[i] == '\'')
			while (tk[++i] != '\'')
				buff[++j] = tk[i];
		else if (tk[i] == '\"')
			while (tk[++i] != '\"')
				if (tk[i] == '$')
					i += change_env_to_value(minishell, &tk[i], buff, &j);
				else
					i += check_backslash(&tk[i], buff, &j, 1);
		else
		{
			if (tk[i] == '$')
				i += change_env_to_value(minishell, &tk[i], buff, &j);
			else
				i += check_backslash(&tk[i], buff, &j, 0);
		}
	buff[++j] = '\0';
	return (ft_strdup(buff));
}

int
	check_dollar(t_minishell *minishell, t_lstcmd *cmd)
{
	char	*old_arg;
	int		i;

	i = -1;
	while (cmd->argv[++i])
	{
		old_arg = cmd->argv[i];
		cmd->argv[i] = check_quote(minishell, cmd->argv[i], -1);
		free(old_arg);
	}
	if (!check_outrdir_dollar(minishell, cmd->out))
		return (0);
	if (!check_inrdir_dollar(minishell, cmd->in))
		return (0);
	return (1);
}
