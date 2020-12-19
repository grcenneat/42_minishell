/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:42:35 by hjung             #+#    #+#             */
/*   Updated: 2020/04/05 20:01:25 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			total_size;
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	total_size = count * size;
	ptr = (unsigned char *)malloc(total_size);
	if (!ptr)
		return (void *)(NULL);
	while (i < total_size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (void *)(ptr);
}
