/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:59:15 by jthierce          #+#    #+#             */
/*   Updated: 2018/11/29 15:51:53 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new;

	if (ptr == NULL || size == 0)
		return (NULL);
	if (!(new = (void *)malloc(size)))
		return (NULL);
	ft_memcpy(new, ptr, size);
	free(ptr);
	return (new);
}
