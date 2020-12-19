/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 21:58:56 by hjung             #+#    #+#             */
/*   Updated: 2020/04/14 21:52:04 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	clearall(t_list *lst, void (*del)(void *))
{
	while (lst)
	{
		del(lst->content);
		free(lst);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newnode;
	t_list	*tail;

	newlist = NULL;
	while (lst)
	{
		newnode = ft_lstnew((*f)(lst->content));
		if (!newnode)
		{
			clearall(newlist, del);
			return (NULL);
		}
		if (newlist == NULL)
			newlist = newnode;
		else
			tail->next = newnode;
		tail = newnode;
		lst = lst->next;
	}
	return (newlist);
}
