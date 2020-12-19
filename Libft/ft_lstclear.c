/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 20:19:29 by hjung             #+#    #+#             */
/*   Updated: 2020/04/14 22:17:47 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*delnode;

	delnode = (*lst);
	(*lst) = (*lst)->next;
	del(delnode->content);
	free(delnode);
	while (*lst)
	{
		delnode = (*lst);
		(*lst) = (*lst)->next;
		del(delnode->content);
		free(delnode);
	}
}
