/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 00:07:18 by hjung             #+#    #+#             */
/*   Updated: 2020/04/15 03:23:29 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_move(unsigned char *dst, unsigned char *src, size_t n)
{
	size_t			i;

	i = 0;
	if (src < dst)
	{
		while (i < n)
		{
			dst[n - i - 1] = src[n - i - 1];
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	dst_ptr = ft_move(dst_ptr, src_ptr, n);
	return (dst);
}
