/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 16:57:58 by nahkim            #+#    #+#             */
/*   Updated: 2021/01/02 22:32:49 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		ft_strnlen(char *str)
{
	int	count;

	count = 0;
	while (*str != 0)
	{
		count++;
		str++;
	}
	return (count);
}


char	*ft_strnjoin(char *s1, char *s2)
{
	char	*p;
	int		i;

	i = 0;
	if ((p = (char *)malloc(ft_strnlen(s1) + ft_strnlen(s2) + 1)) == 0)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (*s2 != 0)
	{
		p[i] = *(s2);
		i++;
		s2++;
	}
	p[i] = '\0';
	return (p);
}

void	ft_strcpy(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	return ;
}

char	*ft_strndup(char *str, int size)
{
	char	*res;

	if (str == NULL)
		return (0);
	if (!(res = (char *)malloc(size + 1)))
		return (NULL);
	res[size] = '\0';
	ft_strcpy(res, str, size);
	return (res);
}

char	*ft_strnchr(char *s, char target)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == target)
			return (s + i);
		i++;
	}
	return (0);
}
