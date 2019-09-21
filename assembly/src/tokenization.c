/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:51:35 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/23 21:51:36 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

void	tokenization(t_data *data)
{
	char	*line;
	int		i;
	int		check;
	int		tmp;

	while ((tmp = get_next_line(data->fd_s, &data->line)) > 0)
	{
		line = data->line;
		i = 0;
		(check = 2) && (data->n_len++);
		while (line[i] && (line[i] != COMMENT_CHAR && line[i] != ALT_COMMENT))
		{
			i += skip_space(line + i);
			if (!line[i] || (line[i] == COMMENT_CHAR || line[i] == ALT_COMMENT))
				break ;
			((line[i] >= 'a' && line[i] <= 'z') || (line[i] <= 'Z' &&
			line[i] >= 'A') || line[i] == '_') ? ((check = tmp) &&
			(i = ft_new_alph_token(data, i))) : ft_exit(data, i + 1, ERR3, -2);
			if (i == 0)
				break ;
		}
		free(line);
	}
	(check == 1) ? ft_exit(data, 1, data->line, -11) : 0;
}

int		ft_new_alph_token(t_data *data, int i)
{
	int instr;

	data->numb_symb = ft_lenstr_to_space(data->line + i);
	if (data->line[i + data->numb_symb] != LABEL_CHAR &&
		(instr = is_true_instr(data->line + i, data->numb_symb)) >= 0)
		ft_init_instruct(instr, data, i);
	else if (data->line[i + data->numb_symb] == LABEL_CHAR)
	{
		data->type = LABEL;
		ft_write_token(data, -1, i, data->numb_symb);
		return (i + data->numb_symb + 1);
	}
	else
	{
		data->line[i + data->numb_symb] = 0;
		ft_exit(data, i + 1, data->line + i, -6);
	}
	return (0);
}
