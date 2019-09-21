/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 07:44:17 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/02/20 07:44:19 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		dop_free(char **buf)
{
	free(*buf);
	*buf = NULL;
}

static int		read_line(char **buf, char **line, int i)
{
	char	*tmp;

	if (*buf[0] == '\0')
		return (0);
	if (ft_strchr(*buf, '\n') != NULL)
	{
		i = 2;
		*(ft_strchr(*buf, '\n')) = '\0';
		*line = ft_strdup(*buf);
		tmp = ft_strdup(ft_strchr(*buf, '\0') + 1);
		dop_free(buf);
		if (tmp)
		{
			*buf = ft_strdup(tmp);
			free(tmp);
		}
	}
	else
	{
		i++;
		(*line = ft_strdup(*buf));
		free(*buf);
		*buf = NULL;
	}
	return (i);
}

int				get_next_line(const int fd, char **line)
{
	int			count;
	char		stack[BUFF_SIZE + 1];
	static char	*buff[MAX_FD];
	char		*tmp;

	if (fd < 0 || read(fd, stack, 0) < 0 || !line)
		return (-1);
	if (!(buff[fd]))
		buff[fd] = ft_strnew(0);
	while (ft_strchr(buff[fd], '\n') == NULL)
	{
		count = read(fd, stack, BUFF_SIZE);
		stack[count] = '\0';
		if (count == 0)
			break ;
		tmp = ft_strjoin(buff[fd], stack);
		free(buff[fd]);
		buff[fd] = ft_strdup(tmp);
		free(tmp);
	}
	return (read_line(&(buff[fd]), line, 0));
}
