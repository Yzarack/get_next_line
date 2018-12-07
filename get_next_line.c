/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:17:26 by marvin            #+#    #+#             */
/*   Updated: 2018/12/07 18:55:38 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strchrint(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] != (char)c)
		return (NULL);
	return (i);
}

t_list	*ft_readinlst(const int fd, char **line)
{
	t_list	*tmp;
	t_list *debut;

	tmp = ft_lstnew("\0", BUFF_SIZE + 1);
	debut = tmp;
	ft_bzero(tmp->content, BUFF_SIZE);
	if ((tmp->content_size = read(fd, tmp->content, BUFF_SIZE)) == -1)
		return (NULL);
	while (ft_strchr(tmp->content, '\n') == NULL || tmp->content_size != 0)
	{
		tmp = tmp->next;
		if (!(tmp->content = (void *)malloc(sizeof(char) * BUFF_SIZE)))
			return (NULL);
		if ((tmp->content_size = read(fd, tmp->content, BUFF_SIZE)) == -1)
			return (NULL);
		tmp->next = NULL;
	}
	if (!(*line = (char *)malloc(sizeof(char) * ((ft_chainlistlen(debut) - 1)
	* BUFF_SIZE + ft_strcmp(tmp->content, '\n')))))
		return (NULL);
	ft_stncat(*line, tmp->content, ft_strchr(tmp->content, '\n'));
	return (tmp);
}

int		get_next_line(const int fd, char **line)
{
	static char *str;
	t_list		*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	tmp = ft_readintlst(fd, line);
	ft_memcpy(str, ft_strchr(tmp->content, '\n'),
	ft_strlen(ft_strchr(tmp->content, '\n')));
}
