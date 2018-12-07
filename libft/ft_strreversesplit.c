/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreversesplit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 00:07:39 by marvin            #+#    #+#             */
/*   Updated: 2018/11/29 15:43:01 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_tabinstr(char **tab, char *str, char *separator)
{
	int i;

	i = 0;
	while (tab[i])
	{
		str = ft_strcat(str, tab[i]);
		if (tab[i + 1] != NULL && ft_strlen(separator) != 0)
		{
			str = ft_strcat(str, separator);
		}
		i++;
	}
	return (str);
}

char		*ft_strreversesplit(char **tab, char *separator)
{
	size_t	i;
	size_t	j;
	size_t	length;
	char	*str;

	length = 0;
	i = 0;
	if (tab == NULL || separator == NULL)
		return (NULL);
	while (tab[i])
	{
		while (tab[i][j])
		{
			j++;
			length++;
		}
		j = 0;
		i++;
	}
	j = ft_strlen(separator);
	if (!(str = (char *)malloc(sizeof(char) * (i * j + length + 1))))
		return (NULL);
	str = ft_tabinstr(tab, str, separator);
	return (str);
}
