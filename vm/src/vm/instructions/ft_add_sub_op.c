/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_sub_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:39:41 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/25 14:39:43 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar_vm.h"

int		ft_add_help(t_carriage **carriage, int *arg, int count)
{
	if ((*carriage)->ex_cod == 4)
		(*carriage)->r[arg[3]] = (*carriage)->r[arg[1]]
		+ (*carriage)->r[arg[2]];
	else if ((*carriage)->ex_cod == 5)
		(*carriage)->r[arg[3]] = (*carriage)->r[arg[1]]
		- (*carriage)->r[arg[2]];
	(*carriage)->carry = (*carriage)->r[arg[3]] == 0 ? 1 : 0;
	return (count);
}

void	ft_add_sub(t_vm *vm, t_carriage **carriage)
{
	unsigned char	cod_arg[4];
	int				arg[5];
	int				step;
	int				count;

	step = 0;
	ft_check_arg(vm, carriage, cod_arg, arg);
	if ((int)cod_arg[1] == REG_CODE && (int)cod_arg[2] ==
	REG_CODE && (int)cod_arg[3] == REG_CODE)
	{
		count = ft_log_op(vm, carriage, cod_arg, arg);
		if (arg[4] == 0)
			step = ft_add_help(carriage, arg, count);
	}
	(step == 0) ? step = ft_check_step(vm->op[(*carriage)->ex_cod].size_t_dir,
	cod_arg, vm->op[(*carriage)->ex_cod].count_arg) : 0;
	(*carriage)->current_position =
	((*carriage)->current_position + step) % MEM_SIZE;
}
