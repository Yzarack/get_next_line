/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:38:33 by jthierce          #+#    #+#             */
/*   Updated: 2018/11/13 15:28:06 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (src[i] && i != n)
	{
		dest[i] = src[i];
		i++;
	}
	if (i != n)
	{
		while (i != n)
		{
			dest[i] = '\0';
			i++;
		}
	}
	return (dest);
}
