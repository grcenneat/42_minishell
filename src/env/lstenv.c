/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 20:05:14 by hjung             #+#    #+#             */
/*   Updated: 2021/01/03 20:11:24 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lstenv
	*lst_new_env(char *key, char *value)
{
	t_lstenv	*new;

	new = malloc(sizeof(t_lstenv));
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	new->next = NULL;
	return (new);
}

t_lstenv
	*lst_last_env(t_lstenv *begin)
{
	while (begin->next)
		begin = begin->next;
	return (begin);
}

t_lstenv
	*lst_add_env(t_lstenv *begin, char *key, char *value)
{
	t_lstenv	*last;

	last = lst_last_env(begin);
	last->next = lst_new_env(key, value);
	return (begin);
}
/*
void
	lst_remove_env(char *key)
{
	t_lstenv *bef;
	t_lstenv *now;
	t_lstenv *nxt;

	bef = 0;
	now = get_minish()->env;
	while (now)
	{
		nxt = now->next;
		if (ft_strequ(now->key, key))
		{
			if (bef)
				bef->next = nxt;
			else
				get_minish()->env = nxt;
			free(now->key);
			if (now->value)
				free(now->value);
			free(now);
			break ;
		}
		bef = now;
		now = nxt;
	}
}

void
	lst_check_and_add_env(char *key, char *value)
{
	t_lstenv	*env;
	t_lstenv	*last;

	env = get_minish()->env;
	while (env)
	{
		if (ft_strequ(env->key, key))
		{
			if (env->value && value)
				free(env->value);
			if (value)
				env->value = ft_strdup(value);
			return ;
		}
		last = env;
		env = env->next;
	}
	last->next = lst_new_env(key, value);
}
*/