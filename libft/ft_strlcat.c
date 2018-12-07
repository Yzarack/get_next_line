/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:10:06 by jthierce          #+#    #+#             */
/*   Updated: 2018/11/30 19:48:31 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	unsigned int i;
	unsigned int buff;
	unsigned int srclen;

	buff = ft_strlen(dest);
	i = 0;
	srclen = 0;
	while (src[i] && buff + i + 1 < n)
	{
		dest[buff + i] = src[i];
		i++;
	}
	dest[buff + i] = '\0';
	srclen = ft_strlen(src);
	if (n < buff)
		return (srclen + n);
	return (buff + srclen);
}
