/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_lfork_op.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:46:02 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/25 14:46:03 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar_vm.h"

void	ft_fork_lfork(t_vm *vm, t_carriage **carriage)
{
	short int		number;
	int				i;

	i = -1;
	number = ft_check_number(vm, (*carriage)->current_position + OP_SIZE,
	vm->op[(*carriage)->ex_cod].size_t_dir);
	ft_create_carriage(vm);
	vm->carriage->number_champ = (*carriage)->number_champ;
	vm->carriage->carry = (*carriage)->carry;
	vm->carriage->cicle_last_live = (*carriage)->cicle_last_live;
	vm->count_carriage++;
	while (++i < REG_NUMBER)
		vm->carriage->r[i] = (*carriage)->r[i];
	if ((*carriage)->ex_cod == 12)
		vm->carriage->current_position = ((*carriage)->current_position +
		number % IDX_MOD) % MEM_SIZE;
	else
		vm->carriage->current_position = ((*carriage)->current_position +
		number) % MEM_SIZE;
	(*carriage)->current_position = ((*carriage)->current_position +
	vm->op[(*carriage)->ex_cod].size_t_dir + OP_SIZE) % MEM_SIZE;
	if (vm->carriage->current_position < 0)
		vm->carriage->current_position = MEM_SIZE +
		vm->carriage->current_position;
}
