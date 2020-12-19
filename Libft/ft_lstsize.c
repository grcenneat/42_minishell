/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 11:41:32 by hjung             #+#    #+#             */
/*   Updated: 2020/04/14 21:19:55 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		cnt;

	cnt = 0;
	if (lst == NULL)
		return (0);
	else
	{
		while (lst->next != NULL)
		{
			cnt++;
			lst = lst->next;
		}
		cnt++;
		return (cnt);
	}
}
