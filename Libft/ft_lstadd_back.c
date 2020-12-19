/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 13:46:34 by hjung             #+#    #+#             */
/*   Updated: 2020/04/14 21:23:18 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*pnode;

	pnode = (*lst);
	if (pnode == NULL)
		(*lst) = new;
	else
	{
		while (pnode->next != NULL)
			pnode = pnode->next;
		pnode->next = new;
	}
}
