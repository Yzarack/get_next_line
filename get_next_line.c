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

int		get_next_line(const int fd, char **line)
{
	static t_list_fd	*save;
	t_list_fd			*tmp;

	if (!(save))
		save = NULL;
	if (fd < 0 || line == NULL || fd > 1024)
		return (-1);
	save = ft_readinlst(fd, line, tmp);
	if (ft_strchr(save, '\n') == NULL)
		return (0);
	return (1);
}
