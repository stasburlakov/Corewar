/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:51:09 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/23 21:51:10 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

void	ft_write_token(t_data *data, int number, int start, int len)
{
	if (data->t_first)
	{
		data->t_last->next = (t_list_lex*)malloc(sizeof(t_list_lex));
		data->t_last->next->next = NULL;
		data->t_last = data->t_last->next;
	}
	else if (!data->t_first)
	{
		data->t_last = (t_list_lex*)malloc(sizeof(t_list_lex));
		data->t_last->next = NULL;
		data->t_first = data->t_last;
	}
	data->t_last->type = data->type;
	data->t_last->number = number;
	data->t_last->label = (len > 0) ?
			ft_strndup(data->line + start, len) : NULL;
}

void	ft_add_byte(t_data *data, int32_t byte, int size)
{
	uint8_t	c;

	while (--size >= 0)
	{
		c = (byte >> (size * 8)) & 0xFF;
		data->code[data->i++] = c;
	}
}
