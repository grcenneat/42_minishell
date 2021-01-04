/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 22:01:02 by hjung             #+#    #+#             */
/*   Updated: 2021/01/04 23:32:06 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int
	is_redir(char *s)
{
	if (!ft_strncmp(s, "<", 1))
		return (1);
	if (!ft_strncmp(s, ">", 1))
		return (1);
	if (!ft_strncmp(s, ">>", 1))
		return (1);
	return (0);
}


static int
	check_redir(char **tokens)
{
	int i;
	int fredi;

	fredi = 0;
	i = 0;
	while (tokens[i])
	{
		if (is_redir(tokens[i]))
		{
			fredi++;
			if (fredi == 2)
				return (syntax_error(tokens[i], 0));
		}
		else if (fredi == 1 &&
			((!ft_strncmp(tokens[i], "|", 1))
			|| (!ft_strncmp(tokens[i], ";", 1))))
			return (syntax_error(tokens[i], 0));
		else
			fredi = 0;
		i++;
	}
	if (i != 0 && is_redir(tokens[i - 1]))
		return (syntax_error("newline", 0));
	return (1);
}

static int
	check_pipe(char **tokens)
{
	int fpip;
	int i;

	fpip = 0;
	i = 0;
	while (tokens[i])
	{
		if ((!ft_strncmp(tokens[i], "|", 1)))
		{
			if (i == 0)
				return (syntax_error("|", 0));
			fpip++;
			if (fpip == 2)
				return (syntax_error("|", 0));
		}
		else if (fpip == 1 &&
			(is_redir(tokens[i]) || (!ft_strncmp(tokens[i], ";", 1))))
			return (syntax_error(tokens[i], 0));
		else
			fpip = 0;
		i++;
	}
	if (i != 0 && (!ft_strncmp(tokens[i - 1], "|", 1)))
		return (syntax_error("|", 0));
	return (1);
}

static int
	check_semi(char **tokens)
{
	int i;
	int fsemi;

	i = 0;
	fsemi = 0;
	while (tokens[i])
	{
		if (!ft_strncmp(tokens[i], ";", 1))
		{
			if (i == 0)
				return (syntax_error(";", 0));
			fsemi++;
			if (fsemi == 2)
				return (syntax_error(";", 0));
		}
		else
			fsemi = 0;
		i++;
	}
	return (1);
}

int
	ck_tokens(char **tokens)
{
	if (check_redir(tokens)
		&& check_pipe(tokens)
		&& check_semi(tokens))
		return (1);
	return (0);
}
