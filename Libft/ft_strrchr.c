/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:06:16 by hjung             #+#    #+#             */
/*   Updated: 2020/04/05 20:04:46 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			tmp = (char *)s + i;
		i++;
	}
	if (c == 0)
		return (char *)(s + i);
	return (tmp);
}
