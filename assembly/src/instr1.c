/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:51:21 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/23 21:51:23 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

int	ft_init_sti(t_data *data, int i)
{
	i = ft_init_reg(data, i, "sti");
	i += skip_space(data->line + i);
	if (data->line[i] != SEPARATOR_CHAR)
		ft_exit(data, i, "sti", -9);
	i++;
	i += skip_space(data->line + i);
	if (data->line[i] == '%')
		i = ft_init_dir(data, i, "sti");
	else if (data->line[i] == 'r')
		i = ft_init_reg(data, i, "sti");
	else
		i = ft_init_ind(data, i, "sti");
	i += skip_space(data->line + i);
	if (data->line[i] != SEPARATOR_CHAR)
		ft_exit(data, i, "sti", -9);
	i++;
	i += skip_space(data->line + i);
	if (data->line[i] == 'r')
		i = ft_init_reg(data, i, "sti");
	else
		i = ft_init_dir(data, i, "sti");
	return (i);
}

int	ft_init_st(t_data *data, int i)
{
	i = ft_init_reg(data, i, "st");
	i += skip_space(data->line + i);
	if (data->line[i] != SEPARATOR_CHAR)
		ft_exit(data, i, "st", -9);
	i++;
	i += skip_space(data->line + i);
	if (data->line[i] == 'r')
		i = ft_init_reg(data, i, "st");
	else
		i = ft_init_ind(data, i, "st");
	return (i);
}

int	ft_init_three_reg(t_data *data, int i, char *s)
{
	int k;

	k = -1;
	while (++k < 3)
	{
		i = ft_init_reg(data, i, s);
		i += skip_space(data->line + i);
		if (k != 2)
		{
			if (data->line[i] != SEPARATOR_CHAR)
				ft_exit(data, i, s, -9);
			else
				i++;
		}
	}
	return (i);
}

int	ft_init_ld_lld(t_data *data, int i, char *s)
{
	int k;

	k = -1;
	while (++k < 2)
	{
		i += skip_space(data->line + i);
		if (data->line[i] == 'r')
			i = ft_init_reg(data, i, s);
		else if (data->line[i] == '%' || k == 1)
			i = ft_init_dir(data, i, s);
		else
			i = ft_init_ind(data, i, s);
		i += skip_space(data->line + i);
		if (data->line[i] != SEPARATOR_CHAR)
			ft_exit(data, i, s, -9);
		i++;
	}
	i += skip_space(data->line + i);
	i = ft_init_reg(data, i, s);
	return (i);
}

int	ft_init_logic(t_data *data, int i, char *s)
{
	int k;

	k = -1;
	while (++k < 2)
	{
		i += skip_space(data->line + i);
		if (data->line[i] == 'r')
			i = ft_init_reg(data, i, s);
		else if (data->line[i] == '%')
			i = ft_init_dir(data, i, s);
		else
			i = ft_init_ind(data, i, s);
		i += skip_space(data->line + i);
		if (data->line[i] != SEPARATOR_CHAR)
			ft_exit(data, i, s, -9);
		i++;
	}
	i += skip_space(data->line + i);
	i = ft_init_reg(data, i, s);
	return (i);
}
