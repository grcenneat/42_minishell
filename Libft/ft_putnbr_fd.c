/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:28:20 by hjung             #+#    #+#             */
/*   Updated: 2020/04/06 15:34:57 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	caseofmin(int nb, int fd)
{
	int		i;
	char	arr[11];

	i = 10;
	arr[0] = '-';
	while (i > 0)
	{
		arr[i] = '0' - (nb % 10);
		nb /= 10;
		i--;
	}
	i = 0;
	while (i < 11)
	{
		ft_putchar_fd(arr[i], fd);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		caseofmin(n, fd);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd('0' + n % 10, fd);
	}
	else
		ft_putchar_fd('0' + n, fd);
}
