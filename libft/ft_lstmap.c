/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:33:04 by jthierce          #+#    #+#             */
/*   Updated: 2018/11/27 15:31:51 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*cpy;
	t_list	*save;
	t_list	*first;

	if (f == NULL || lst == NULL)
		return (NULL);
	save = f(lst);
	if (!(cpy = ft_lstnew(save->content, save->content_size)))
		return (NULL);
	first = cpy;
	lst = lst->next;
	while (lst != NULL)
	{
		save = f(lst);
		if (!(cpy->next = ft_lstnew(save->content, save->content_size)))
			return (NULL);
		lst = lst->next;
		cpy = cpy->next;
	}
	cpy->next = NULL;
	return (first);
}
