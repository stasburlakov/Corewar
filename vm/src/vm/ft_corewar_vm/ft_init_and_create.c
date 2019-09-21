/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_and_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egottlie <egottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 16:55:18 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/26 17:47:06 by egottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar_vm.h"

void	ft_create_carriage(t_vm *vm)
{
	t_carriage	*tmp;

	if (vm->carriage == NULL)
	{
		if (!(vm->carriage = (t_carriage *)malloc(sizeof(t_carriage))))
			ft_error(vm, ERROR_MALLOC, 0);
		vm->carriage->next = NULL;
		vm->carriage->count_wait_cicle = 0;
	}
	else
	{
		if (!(tmp = (t_carriage *)malloc(sizeof(t_carriage))))
			ft_error(vm, ERROR_MALLOC, 0);
		tmp->next = vm->carriage;
		vm->carriage = tmp;
		vm->carriage->count_wait_cicle = 0;
	}
}

void	ft_init_arena_help_1(t_vm *vm, int i, int champ)
{
	int	j;

	j = 0;
	ft_create_carriage(vm);
	vm->count_carriage++;
	vm->carriage->carry = 0;
	vm->carriage->cicle_last_live = 0;
	vm->carriage->current_position = i;
	vm->carriage->count_wait_cicle = 0;
	vm->carriage->number_champ = champ;
	vm->carriage->r[0] = -champ;
	while (++j < REG_NUMBER)
		vm->carriage->r[j] = 0;
}

void	ft_init_arena_help_2(t_vm *vm, int *i, int tab, int champ)
{
	int	k;

	k = 0;
	while (vm->champ[champ].size_champ >= k)
	{
		vm->arena[(*i)] = vm->champ[champ].ex_cod[k];
		vm->player_arena[(*i)] = champ;
		k++;
		(*i)++;
	}
	while ((*i) < tab * champ)
	{
		vm->arena[(*i)] = '\0';
		vm->player_arena[(*i)] = 0;
		(*i)++;
	}
}

void	ft_init(t_vm *vm)
{
	vm->dump = -1;
	vm->count_flag = 0;
	vm->index_viz = -1;
	vm->debug = -1;
	vm->flag_aff = -1;
	vm->show = -1;
	vm->count_champ = 0;
	vm->champ_said_a_live = 0;
	vm->op = NULL;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->count_cicle = 0;
	vm->max_check = 0;
	vm->champ = NULL;
	vm->count_carriage = 0;
	vm->carriage = NULL;
	vm->arena = NULL;
	if (!(vm->op = (t_op *)malloc(sizeof(t_op) * 17)))
		ft_error(vm, ERROR_MALLOC, 0);
	ft_create_op_1(vm);
	if (!(vm->arena = (char *)malloc(sizeof(char) * MEM_SIZE)))
		ft_error(vm, ERROR_MALLOC, 0);
}

void	ft_init_arena(t_vm *vm)
{
	int	i;
	int	champ;
	int	tab;

	i = 0;
	champ = 1;
	tab = MEM_SIZE / vm->count_champ;
	vm->champ_said_a_live = -vm->count_champ;
	while (champ <= vm->count_champ && i < MEM_SIZE)
	{
		ft_init_arena_help_1(vm, i, champ);
		ft_init_arena_help_2(vm, &i, tab, champ);
		champ++;
	}
}
