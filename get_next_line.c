/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 02:23:53 by caking            #+#    #+#             */
/*   Updated: 2019/08/03 18:13:31 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	next_line(int fd, char **line, char **tmp)
{
	char *sbuff;

	if (ft_strchr(tmp[fd], '\n') != NULL)
	{
		*line = ft_strsub(tmp[fd], 0, \
		ft_strchr(tmp[fd], '\n') - (tmp[fd]));
		sbuff = ft_strsub(tmp[fd], (ft_strchr(tmp[fd], '\n') - (tmp[fd])) \
		+ 1, ft_strlen(tmp[fd]) - (ft_strchr(tmp[fd], '\n') - (tmp[fd])));
		free(tmp[fd]);
		tmp[fd] = sbuff;
		return (1);
	}
	if (ft_strchr(tmp[fd], '\n') == NULL)
	{
		*(line) = ft_strsub(tmp[fd], 0, ft_strlen(tmp[fd]));
		ft_strdel(&tmp[fd]);
		return (1);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int			ret;
	char		buff[BUFF + 1];
	char		*tmp;
	static char	*tmp_buff[MAX_FD];

	ret = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buff, BUFF)) > 0)
	{
		buff[ret] = '\0';
		if (tmp_buff[fd] == NULL)
			tmp_buff[fd] = ft_strnew(BUFF);
		tmp = ft_strjoin(tmp_buff[fd], (char *)buff);
		free(tmp_buff[fd]);
		tmp_buff[fd] = tmp;
		if (ft_strchr(tmp_buff[fd], '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (tmp_buff[fd] == NULL || tmp_buff[fd][0] == '\0'))
		return (0);
	return (next_line(fd, line, tmp_buff));
}
