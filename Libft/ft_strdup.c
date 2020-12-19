/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:54:36 by hjung             #+#    #+#             */
/*   Updated: 2020/04/05 20:04:11 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*box;
	int		i;

	i = ft_strlen(src);
	box = (char *)malloc(i + 1);
	if (!box)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		box[i] = src[i];
		i++;
	}
	box[i] = '\0';
	return (box);
}
