/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:44:59 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/25 14:45:02 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar_vm.h"

void	ft_aff(t_vm *vm, t_carriage **carriage)
{
	unsigned char	cod_arg[4];
	int				arg[5];
	int				step;

	step = 0;
	ft_check_arg(vm, carriage, cod_arg, arg);
	if ((int)cod_arg[1] == REG_CODE && vm->flag_aff == 1)
	{
		arg[1] = vm->arena[((*carriage)->current_position +
		OP_SIZE + ARG_SIZE) % MEM_SIZE];
		if (arg[1] >= 1 && arg[1] <= REG_NUMBER)
		{
			arg[1]--;
			ft_putchar((char)(*carriage)->r[arg[1]]);
			step = T_REG + ARG_SIZE + OP_SIZE;
		}
	}
	if (step == 0)
		step = ft_check_step(vm->op[(*carriage)->ex_cod].size_t_dir,
		cod_arg, vm->op[(*carriage)->ex_cod].count_arg);
	(*carriage)->current_position = ((*carriage)->current_position +
	step) % MEM_SIZE;
}
