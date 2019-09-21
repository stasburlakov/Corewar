/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:51:17 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/23 21:51:18 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

char	*g_op2[17] = {"live", "ld", "st", "add", "sub", "and", "or", "xor",
	"zjmp", "ldi", "sti", "fork", "lld", "lldi", "lfork", "aff"};

int		ft_init_dir(t_data *data, int i, char *s)
{
	i += skip_space(data->line + i);
	if (data->line[i] != DIRECT_CHAR)
		ft_exit(data, 1, s, -9);
	i++;
	if (data->line[i] == LABEL_CHAR)
	{
		data->numb_symb = ft_lenstr_to_space(data->line + ++i);
		data->type = DIR_LABEL;
		ft_write_token(data, -1, i, data->numb_symb);
		i += data->numb_symb;
	}
	else
	{
		data->type = DIR_NUMBER;
		if (!(data->line[i] >= '0' && data->line[i] <= '9')
			&& data->line[i] != '-')
			ft_exit(data, 1, s, -9);
		ft_write_token(data, ft_atoi(data->line + i), i, 0);
		i += skip_number(data->line + i);
	}
	return (i);
}

int		ft_init_reg(t_data *data, int i, char *s)
{
	int value;

	i += skip_space(data->line + i);
	if (data->line[i] != 'r')
		ft_exit(data, 1, s, -9);
	else
	{
		i++;
		value = ft_atoi(data->line + i);
		data->type = REGISTR;
		ft_write_token(data, value, i, 0);
	}
	return (i + skip_number(data->line + i));
}

int		ft_init_ind(t_data *data, int i, char *s)
{
	i += skip_space(data->line + i);
	if (data->line[i] == LABEL_CHAR)
	{
		data->numb_symb = ft_lenstr_to_space(data->line + ++i);
		data->type = INDIR_LABEL;
		ft_write_token(data, -1, i, data->numb_symb);
		i += data->numb_symb;
	}
	else
	{
		data->type = INDIR_NUMBER;
		if (!(data->line[i] >= '0' && data->line[i] <= '9')
			&& data->line[i] != '-')
			ft_exit(data, 1, s, -9);
		ft_write_token(data, ft_atoi(data->line + i), i, 0);
		i += skip_number(data->line + i);
	}
	return (i);
}

int		ft_init_dir_reg(t_data *data, int i, char *s)
{
	i += skip_space(data->line + i);
	if (data->line[i] != DIRECT_CHAR)
		i = ft_init_ind(data, i, s);
	else
		i = ft_init_dir(data, i, s);
	i += skip_space(data->line + i);
	if (data->line[i] != SEPARATOR_CHAR)
		ft_exit(data, 1, s, -9);
	i++;
	i = ft_init_reg(data, i, s);
	return (i);
}

void	ft_init_instruct(int instr, t_data *data, int i)
{
	data->type = INSTRUCTION;
	ft_write_token(data, instr, i, data->numb_symb);
	i += data->numb_symb;
	if (instr == 0 || instr == 8 || instr == 11 || instr == 14)
		i = ft_init_dir(data, i, g_op2[instr]);
	else if (instr == 12 || instr == 1)
		i = ft_init_dir_reg(data, i, g_op2[instr]);
	else if (instr == 10)
		i = ft_init_sti(data, i);
	else if (instr == 15)
		i = ft_init_reg(data, i, g_op2[instr]);
	else if (instr == 2)
		i = ft_init_st(data, i);
	else if (instr == 3 || instr == 4)
		i = ft_init_three_reg(data, i, g_op2[instr]);
	else if (instr == 9 || instr == 13)
		i = ft_init_ld_lld(data, i, g_op2[instr]);
	else if (instr == 5 || instr == 6 || instr == 7)
		i = ft_init_logic(data, i, g_op2[instr]);
	i += skip_space(data->line + i);
	if ((data->line[i] && data->line[i] != COMMENT_CHAR) &&
	(data->line[i] && data->line[i] != ALT_COMMENT))
		ft_exit(data, i + 1, data->line + i, -8);
}
