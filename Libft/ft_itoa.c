/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 21:55:36 by hjung             #+#    #+#             */
/*   Updated: 2020/04/06 00:21:50 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_num_len(int n)
{
	int		len;

	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_minus(char *res, int n, int len)
{
	while (n < 0)
	{
		res[--len] = '0' + ((n % 10) * (-1));
		n /= 10;
	}
	res[--len] = '-';
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;

	len = ft_num_len(n) + 2;
	res = (char *)malloc(len);
	if (!res)
		return (NULL);
	res[--len] = '\0';
	if (n < 0)
		res = ft_minus(res, n, len);
	else if (n == 0)
		res[--len] = '0';
	else
	{
		res[--len] = '\0';
		while (n > 0)
		{
			res[--len] = '0' + (n % 10);
			n /= 10;
		}
	}
	return (res);
}
