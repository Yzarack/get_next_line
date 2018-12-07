/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:54:36 by jthierce          #+#    #+#             */
/*   Updated: 2018/11/21 18:20:48 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *meule_de_foin, const char *aiguille)
{
	size_t i;
	size_t j;
	size_t save;

	j = 0;
	i = 0;
	if (aiguille[0] == '\0')
		return ((char *)meule_de_foin);
	while (meule_de_foin[i])
	{
		save = i;
		while (meule_de_foin[i] == aiguille[j])
		{
			i++;
			j++;
			if (!(aiguille[j]))
				return ((char *)(meule_de_foin) + save);
		}
		j = 0;
		i = save;
		i++;
	}
	return (NULL);
}
