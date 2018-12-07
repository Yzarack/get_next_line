/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:44:13 by jthierce          #+#    #+#             */
/*   Updated: 2018/11/27 16:26:49 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *meule, const char *aiguille, size_t len)
{
	size_t i;
	size_t j;
	size_t save;

	j = 0;
	i = 0;
	if (aiguille[0] == '\0')
		return ((char *)meule);
	while (meule[i] && i < len)
	{
		save = i;
		while (meule[i] == aiguille[j] && i < len)
		{
			i++;
			j++;
			if (aiguille[j] == '\0')
				return ((char *)(meule + save));
		}
		i = save;
		j = 0;
		i++;
	}
	return (NULL);
}
