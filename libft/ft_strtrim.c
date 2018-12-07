/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 11:50:01 by jthierce          #+#    #+#             */
/*   Updated: 2018/11/26 18:09:18 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static char	*ft_malloc_no_space(char const *s, size_t *size)
{
	char	*str;
	size_t	i;

	i = 0;
	while (s[i + 1])
		i++;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	if (!(str = (char *)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	*size = i;
	return (str);
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*str;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	str = ft_malloc_no_space(s + i, &size);
	if (str == NULL)
		return (NULL);
	while (j != size + 1)
	{
		str[j] = s[i + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
