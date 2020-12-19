/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:01:04 by hjung             #+#    #+#             */
/*   Updated: 2020/04/15 04:17:11 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_cmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	}
	return (1);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;

	i = 0;
	if (*to_find == '\0')
		return (char *)(str);
	while (str[i] && (i < n))
	{
		if (n - i < ft_strlen(to_find))
			return (char *)(NULL);
		if (ft_cmp(&str[i], to_find) == 1)
			return ((char *)&str[i]);
		i++;
	}
	return (char*)(NULL);
}
