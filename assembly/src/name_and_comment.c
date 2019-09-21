/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_and_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egottlie <egottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:51:28 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/26 18:16:29 by egottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

char	*new_name_file(char *src)
{
	char	*dest;
	int		len;

	len = ft_strlen(src);
	if (src[len - 1] != 's' || src[len - 2] != '.')
		return (NULL);
	dest = malloc(sizeof(char) * (len + 3));
	ft_strncpy(dest, src, len - 2);
	dest[len - 2] = 0;
	ft_strcat(dest, ".cor");
	return (dest);
}

int		name_or_coom_asm2(char *name, int index, t_data *data, int len)
{
	char	*line;
	int		i;

	while (get_next_line(data->fd_s, &line) > 0)
	{
		(data->n_len++) && (i = 0);
		name[len++] = '\n';
		while (line[i] && line[i] != '"')
			i++;
		len += i;
		if (len > ((index == 1) ? PROG_NAME_LENGTH : COMMENT_LENGTH))
		{
			free(line);
			return (-1);
		}
		ft_strncat(name, line, i);
		if (line[i])
		{
			free(line);
			return (0);
		}
		free(line);
	}
	return (-1);
}

char	*name_or_comm_asm(t_data *data, int index, int i)
{
	char	*name;
	int		len;

	len = 0;
	name = ft_memalloc(((index == 1) ? PROG_NAME_LENGTH : COMMENT_LENGTH));
	i += skip_space(data->line + i);
	if (data->line[i] != '"')
		ft_exit(data, i + 1, ERR3, -2);
	i++;
	while (data->line[i] && data->line[i] != '"')
		(len += 1) && (i++);
	if ((len > ((index == 1) ? PROG_NAME_LENGTH : COMMENT_LENGTH)))
		ft_exit(data, PROG_NAME_LENGTH, ERR5, -3);
	ft_strncpy(name, data->line + i - len, len);
	if (data->line[i])
		return (name);
	else if (name_or_coom_asm2(name, index, data, ft_strlen(name)) == -1)
		ft_exit(data, i + 1, ERR3, -2);
	return (name);
}
