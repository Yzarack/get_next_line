/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:17:26 by marvin            #+#    #+#             */
/*   Updated: 2019/01/03 19:44:25 by jthierce         ###   ########.fr       */
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

void	ft_printinline(char **line, t_list *tmp, char **str)
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
			return ;
	}
	else
	{
		printf("bombe has been planted\n");
		if (!(*line = (char *)malloc(sizeof(char) * ((ft_chainlistlen(tmp) - 1)
		* BUFF_SIZE + ft_strlen(tmp->content)))))
			return ;
	}
	printf("espace mallocé = %zd\n", ((ft_chainlistlen(tmp) - 1)
	* BUFF_SIZE + ft_strchrint(tmp->content, '\n') + 1));
	printf("5\n");
	tmp = debut;
	*line[0] = '\0';
	while (tmp != NULL)
	{
		if (ft_strchrint(tmp->content, '\n') == -1)
		{
			*line = ft_strncat(*line, tmp->content, tmp->content_size);
			printf("qwe1derkfkkfkfs = %s\n", ft_strncat(*line, tmp->content, tmp->content_size));
		}
		else
		{
			printf("*line = %s\n", *line);
			printf("size = %d\n", ft_strchrint(tmp->content, '\n'));
			printf("tmp->content = %s\n", (char *)tmp->content);
			ft_strncat(*line, tmp->content, ft_strchrint(tmp->content, '\n'));
			printf("line = %s\n", *line);
		}
		tmp = tmp->next;
		printf("6 dans while\n");
	}
	if (!(*str = (char *)malloc(sizeof(char) * (ft_strlen(debut->content) - ft_strchrint(debut->content, '\n')))))
		return ;
	*str = ft_strchr(debut->content, '\n');
	printf("6 fin while\n");
	printf("line = %s \n", *line);
}

char	*ft_readinlst(const int fd, char **line, const char *save)
{
	t_list	*tmp;
	t_list	*debut;
	char	*str;

	printf("2\n");
	if (save == NULL)
	{
		tmp = ft_lstnew("0", BUFF_SIZE + 1);
		ft_bzero(tmp->content, BUFF_SIZE);
		if ((tmp->content_size = read(fd, tmp->content, BUFF_SIZE)) == -1)
			return (NULL);
	}
	else
	{
		printf("save = %s\n", save);
		tmp = ft_lstnew(save + 1, ft_strlen(save));
		printf("ft_readinlst tmp = %s\n", (char *)tmp->content);
	}
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
	ft_printinline(line, debut, &str);
	printf("line verification = %s \n", *line);
	printf("str = %s\n", str);
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	static char *save;
	char		*tmp;

	if (!(save))
		save = NULL;
	printf("testostes SAVE = %s\n", save);
	tmp = save;
	printf("testostes TMP = %s\n", tmp);
	if (fd < 0 || line == NULL || fd > 1024)
		return (-1);
	save = ft_readinlst(fd, line, tmp);
	printf("lolilol: %s\n", *line);
	if (ft_strchr(save, '\n') == NULL)
		return (0);
	return (1);
}
