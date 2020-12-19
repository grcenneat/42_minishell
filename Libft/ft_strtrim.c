/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 22:28:38 by hjung             #+#    #+#             */
/*   Updated: 2020/04/18 23:59:24 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check(char const *set, char const letter)
{
	int		i;

	i = 0;
	while (set[i] != '\0')
	{
		if (letter == set[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_res_len(char const *s1, char const *set)
{
	int		head;
	int		tail;
	int		i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_check(set, s1[i]))
			i++;
		else
			break ;
	}
	head = i;
	i = (int)(ft_strlen(s1)) - 1;
	if (head == i + 1)
		return (0);
	while (i >= 0)
	{
		if (ft_check(set, s1[i]))
			i--;
		else
			break ;
	}
	tail = i;
	return (tail - head + 1);
}

char	*ft_input(char const *s1, char const *set)
{
	int		res_len;
	int		i;

	i = 0;
	res_len = ft_res_len(s1, set) + 1;
	if (res_len == 1)
		return (ft_strdup(""));
	else
	{
		while (s1[i] != '\0')
		{
			if (ft_check(set, s1[i]))
				i++;
			else
				break ;
		}
		return (ft_substr(s1, i, res_len - 1));
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;

	if (s1 == NULL || set == NULL)
		return (NULL);
	res = ft_input(s1, set);
	return (res);
}
