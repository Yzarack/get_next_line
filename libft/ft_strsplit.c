/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 12:45:36 by jthierce          #+#    #+#             */
/*   Updated: 2018/11/23 19:13:05 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static size_t	ft_word(char const *s, char c)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (s[i])
	{
		while ((s[i] == c && s[i] != '\0') || i == 0)
		{
			if ((s[i + 1] != c && s[i + 1] != '\0') || (i == 0 && s[0] != c))
				word++;
			i++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (word);
}

static char		**ft_malloc_tab(char const *s, char c, size_t word, char **tab)
{
	size_t	i;
	size_t	j;
	size_t	i_word;

	i = 0;
	j = 0;
	i_word = 0;
	while (s[i] && i_word != word)
	{
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
			{
				j++;
				i++;
			}
			if (!(tab[i_word] = (char *)malloc(sizeof(char) * (j + 1))))
				return (NULL);
			j = 0;
			i_word++;
		}
		i++;
	}
	return (tab);
}

static char		**ft_place_word(char const *s, char c, size_t word, char **tab)
{
	size_t	i;
	size_t	j;
	size_t	i_word;

	i = 0;
	j = 0;
	i_word = 0;
	while (s[i] && i_word != word)
	{
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
			{
				tab[i_word][j] = s[i];
				j++;
				i++;
			}
			tab[i_word][j] = '\0';
			i_word++;
			j = 0;
		}
		i++;
	}
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	word;
	char	**tab;

	if (s == NULL)
		return (NULL);
	word = ft_word(s, c);
	if (!(tab = (char**)malloc(sizeof(char *) * (word + 1))))
		return (NULL);
	tab = ft_malloc_tab(s, c, word, tab);
	if (tab == NULL)
		return (NULL);
	tab[word] = NULL;
	tab = ft_place_word(s, c, word, tab);
	return (tab);
}
