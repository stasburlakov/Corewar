/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi_lldi_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:49:46 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/25 14:49:47 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar_vm.h"

int					ft_ldi_help(t_vm *vm, t_carriage **carriage,
unsigned char *cod_arg, int *arg)
{
	int	count;

	count = ft_log_op(vm, carriage, cod_arg, arg);
	ft_log_help(cod_arg, arg, carriage);
	if (arg[4] == 0)
	{
		if ((*carriage)->ex_cod == 10)
			(*carriage)->r[arg[3]] =
			ft_check_number(vm, (*carriage)->current_position +
			(arg[1] + arg[2]) % IDX_MOD, REG_SIZE);
		else
		{
			(*carriage)->r[arg[3]] = ft_check_number(vm,
			(*carriage)->current_position + arg[1] + arg[2], REG_SIZE);
			(*carriage)->carry = (*carriage)->r[arg[3]] == 0 ? 1 : 0;
		}
		return (count);
	}
	return (0);
}

void				ft_ldi_lldi(t_vm *vm, t_carriage **carriage)
{
	unsigned char	cod_arg[4];
	int				arg[5];
	int				step;

	step = 0;
	ft_check_arg(vm, carriage, cod_arg, arg);
	if (cod_arg[1] != 0 && cod_arg[2] != 0 && cod_arg[2]
	!= IND_CODE && cod_arg[3] == REG_CODE)
		step = ft_ldi_help(vm, carriage, cod_arg, arg);
	if (step == 0)
		step = ft_check_step(vm->op[(*carriage)->ex_cod].size_t_dir,
		cod_arg, vm->op[(*carriage)->ex_cod].count_arg);
	(*carriage)->current_position = ((*carriage)->current_position +
	step) % MEM_SIZE;
}
