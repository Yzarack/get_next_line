/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewfd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:18:23 by marvin            #+#    #+#             */
/*   Updated: 2019/01/22 16:18:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list_fd	*ft_lstnew_fd(void const *content, size_t content_size, int fd)
{
	t_list_fd	*list;

	if (!(list = (t_list*)malloc(sizeof(t_list_fd))))
		return (NULL);
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else if (content_size != 0)
	{
		if (!(list->content = (void *)malloc(content_size)))
			return (NULL);
		ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
	}
	else
	{
		list->content = (void *)content;
		list->content_size = 0;
	}
	list->fd = fd;
	list->next = NULL;
	return (list);
}
