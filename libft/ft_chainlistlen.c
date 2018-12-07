/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chainlistlen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 01:31:49 by marvin            #+#    #+#             */
/*   Updated: 2018/11/29 15:38:44 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_chainlistlen(t_list *lst)
{
	t_list	*debut;
	size_t	len;

	len = 1;
	debut = lst;
	if (lst == NULL)
		return (0);
	lst = lst->next;
	while (lst != NULL && lst != debut)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
