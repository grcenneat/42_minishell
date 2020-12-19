/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:21:29 by hjung             #+#    #+#             */
/*   Updated: 2020/04/06 00:09:34 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen >= size)
		return (srclen + size);
	else
	{
		i = 0;
		j = dstlen;
		while (size - dstlen - 1 > 0 && src[i] != '\0')
		{
			dst[j] = src[i];
			j++;
			i++;
			size--;
		}
		dst[j] = '\0';
		return (dstlen + srclen);
	}
}
