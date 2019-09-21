/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egottlie <egottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:54:43 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/26 18:19:53 by egottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar_vm.h"

void				ft_live(t_vm *vm, t_carriage **carriage)
{
	int	number;
	int	i;

	i = 0;
	number = ft_check_number(vm, (*carriage)->current_position +
	OP_SIZE, vm->op[(*carriage)->ex_cod].size_t_dir);
	vm->count_live_period++;
	(*carriage)->cicle_last_live = vm->count_cicle + 1;
	if (number < 0 && number >= -vm->count_champ)
	{
		while (++i <= vm->count_champ)
			if (number * -1 == i)
			{
				vm->champ_said_a_live = number;
				if (vm->show == 1)
					ft_printf("Player %d (%s) is said to be alive\n",
					-number, vm->champ[-number].name);
				vm->live_in_period[-number - 1]++;
				vm->last_live[-number - 1] = vm->count_cycle_in_period + 1;
				break ;
			}
	}
	(*carriage)->current_position = ((*carriage)->current_position +
	vm->op[(*carriage)->ex_cod].size_t_dir + OP_SIZE) % MEM_SIZE;
}
