/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:46:56 by hjung             #+#    #+#             */
/*   Updated: 2021/01/05 03:34:51 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_haschr(const char *s, char c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int
	count_env(t_lstenv *env)
{
	int i;

	i = 0;
	while (env)
	{
		if (env->value)
			i++;
		env = env->next;
	}
	return (i);
}

char
	**lst_env_to_char(t_lstenv *env)
{
	char	**res;
	char	*tmp;
	int		i;

	if (!(res = malloc(sizeof(char*) * (count_env(env) + 1))))
		return (NULL);
	i = 0;
	while (env)
	{
		if (!env->value)
		{
			env = env->next;
			continue ;
		}
		tmp = ft_strjoin(env->key, "=");
		res[i++] = ft_strjoin(tmp, env->value);
		free(tmp);
		env = env->next;
	}
	res[i] = 0;
	return (res);
}
