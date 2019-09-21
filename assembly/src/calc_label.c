/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_label.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:50:50 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/23 21:50:53 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

void	ft_calc_type_instr2(int size[2], int code,
		t_list_lex *head, t_list_lex *list)
{
	while (++size[0] < 4)
	{
		if (list && list->type == REGISTR)
			(code += 1) && head->size++;
		else if (list && (list->type == DIR_NUMBER || list->type == DIR_LABEL))
		{
			code += 2;
			head->size += size[1];
			list->count = size[1];
		}
		else if (list && (list->type == INDIR_LABEL ||
		list->type == INDIR_NUMBER))
		{
			code += 3;
			head->size += T_IND;
			list->count = T_IND;
		}
		if (list && (list->type == REGISTR || list->type == DIR_NUMBER
		|| list->type == 9 || list->type == DIR_LABEL
		|| list->type == INDIR_NUMBER))
			list = list->next;
		(size[0] != 3) ? code = code << 2 : 0;
	}
	head->number = code;
}

void	ft_calc_type_instr(t_list_lex *list, int instr)
{
	uint8_t		code;
	t_list_lex	*head;
	int			size[2];

	size[0] = -1;
	head = list;
	code = 0;
	if (instr == 0 || instr == 8 || instr == 11 || instr == 14)
	{
		head->size = 1;
		head->count = -1;
	}
	else
		head->size = 2;
	if (instr >= 8 && instr <= 14 && instr != 12)
		(size[1] = T_IND);
	else
		(size[1] = T_DIR);
	list = list->next;
	ft_calc_type_instr2(size, code, head, list);
}

int		ft_search_label(t_data *data, t_list_lex *curr_label, int addr)
{
	t_list_lex	*tmp;
	int			save[2];
	int			check;

	check = 1;
	tmp = data->t_first;
	while (!((tmp->type == LABEL &&
	!ft_strcmp(curr_label->label, tmp->label)) || tmp == curr_label))
	{
		(tmp->type == INSTRUCTION) ? save[0] = tmp->size : 0;
		tmp = tmp->next;
	}
	if (tmp->type == LABEL)
		check = 0;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->type == INSTRUCTION)
			(addr += tmp->size) && (save[1] = tmp->size);
		else if ((tmp->type == LABEL &&
		!ft_strcmp(curr_label->label, tmp->label)) || tmp == curr_label)
			return (check ? addr + save[0] : -addr + save[1]);
		tmp = tmp->next;
	}
	return (ft_exit(data, 0, curr_label->label, -5));
}

void	ft_calc_all_label(t_data *data)
{
	t_list_lex	*tmp;

	tmp = data->t_first;
	while (tmp)
	{
		if (tmp->type == DIR_LABEL || tmp->type == INDIR_LABEL)
			ft_add_byte(data, ft_search_label(data, tmp, 0), tmp->count);
		else if (tmp->type == REGISTR)
			ft_add_byte(data, tmp->number, 1);
		else if (tmp->type == DIR_NUMBER || tmp->type == INDIR_NUMBER)
			ft_add_byte(data, tmp->number, tmp->count);
		else if (tmp->type == INSTRUCTION)
		{
			ft_add_byte(data, is_true_instr(tmp->label,
					ft_strlen(tmp->label)) + 1, 1);
			(tmp->count != -1) ? ft_add_byte(data, tmp->number, 1) : 0;
		}
		tmp = tmp->next;
	}
}

void	ft_calc_all_instr(t_data *data)
{
	t_list_lex	*tmp;

	tmp = data->t_first;
	while (tmp)
	{
		if (tmp->type == INSTRUCTION)
		{
			ft_calc_type_instr(tmp,
					is_true_instr(tmp->label, ft_strlen(tmp->label)));
			data->size_code += tmp->size;
		}
		tmp = tmp->next;
	}
}
