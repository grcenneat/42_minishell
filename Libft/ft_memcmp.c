/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:02:14 by hjung             #+#    #+#             */
/*   Updated: 2020/04/05 19:53:48 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*arr1;
	unsigned char	*arr2;

	arr1 = (unsigned char *)s1;
	arr2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (arr1[i] == arr2[i])
			i++;
		else
			return (arr1[i] - arr2[i]);
	}
	return (0);
}
