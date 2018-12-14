/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:17:26 by marvin            #+#    #+#             */
/*   Updated: 2018/12/14 12:04:56 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_strchrint(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] != (char)c)
		return (-1);
	return (i);
}

char	*ft_printinline(char **line, t_list *tmp)
{
	t_list	*debut;

	debut = tmp;
	while (tmp->next != NULL)
		tmp = tmp->next;
	printf("test : %s\n", debut->content);
	if (ft_strchrint(tmp->content, '\n') != -1)
	{
		if (!(*line = (char *)malloc(sizeof(char) * ((ft_chainlistlen(tmp) - 1)
		* BUFF_SIZE + ft_strchrint(tmp->content, '\n') + 1))))
			return (NULL);
	}
	else
	{
		printf("bombe has been planted\n");
		if (!(*line = (char *)malloc(sizeof(char) * ((ft_chainlistlen(tmp) - 1)
		* BUFF_SIZE + ft_strlen(tmp->content)))))
			return (NULL);
	}
	printf("espace mallocé = %zd\n", ((ft_chainlistlen(tmp) - 1)
	* BUFF_SIZE + ft_strchrint(tmp->content, '\n') + 1));
	printf("5\n");
	tmp = debut;
	*line[0] = '\0';
	while (tmp != NULL)
	{
		if (ft_strchrint(tmp->content, '\n') == -1)
			*line = ft_strncat(*line, tmp->content, tmp->content_size);
		else
			//*line = ft_strncat(*line, tmp->content, ft_strchrint(tmp->content, '\n'));
			printf("qwe = %s\n", ft_strncat(*line, tmp->content, ft_strchrint(tmp->content, '\n')));
		tmp = tmp->next;
		printf("6 dans while\n");
	}
	printf("6 fin while\n");
	printf("line = %s \n", *line);
	return (ft_strchr(tmp->content, '\n'));
}

char	*ft_readinlst(const int fd, char **line, const char *save)
{
	t_list	*tmp;
	t_list	*debut;

	printf("2\n");
	if (save == NULL)
	{
		tmp = ft_lstnew("0", BUFF_SIZE + 1);
		ft_bzero(tmp->content, BUFF_SIZE);
		if ((tmp->content_size = read(fd, tmp->content, BUFF_SIZE)) == -1)
			return (NULL);
	}
	else
		tmp = ft_lstnew(save, ft_strlen(save));
	debut = tmp;
	printf("3\n");
	while (ft_strchr(tmp->content, '\n') == NULL && tmp->content_size != 0)
	{
		tmp->next = ft_lstnew("0", BUFF_SIZE + 1);
		tmp = tmp->next;
		printf("4 dans while\n");
		ft_bzero(tmp->content, BUFF_SIZE);
		if ((tmp->content_size = read(fd, tmp->content, BUFF_SIZE)) == -1)
			return (NULL);
		printf("tmp->content_size = %zd", tmp->content_size);
		printf("tmp->content = %s", tmp->content);
		tmp->next = NULL;
	}
	printf("fin boucle while 4\n");
	return (ft_printinline(line, tmp));
}

int		get_next_line(const int fd, char **line)
{
	static char *save;
	char		*tmp;

	if (!(save))
		save = NULL;
	tmp = save;
	if (fd < 0 || line == NULL || fd > 1024)
		return (-1);
	save = ft_readinlst(fd, line, save);
	printf("lolilol: %s\n", *line);
	if (ft_strchr(save, '\n') == NULL)
		return (0);
	return (1);
}
