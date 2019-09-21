/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egottlie <egottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 16:55:30 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/26 17:15:01 by egottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar_vm.h"

void				ft_check_arg(t_vm *vm, t_carriage **carriage,
unsigned char *cod_arg, int *arg)
{
	int				i;

	i = -1;
	while (++i <= 4)
		arg[i] = 0;
	cod_arg[0] = vm->arena[((*carriage)->current_position +
	OP_SIZE) % MEM_SIZE];
	cod_arg[1] = cod_arg[0];
	cod_arg[1] >>= 6;
	cod_arg[0] <<= 2;
	cod_arg[2] = cod_arg[0];
	cod_arg[2] >>= 6;
	cod_arg[0] <<= 2;
	cod_arg[3] = cod_arg[0];
	cod_arg[3] >>= 6;
}

void				ft_op(t_vm *vm, t_carriage **carriage)
{
	if ((*carriage)->ex_cod == 1)
		ft_live(vm, carriage);
	else if ((*carriage)->ex_cod == 2 || (*carriage)->ex_cod == 13)
		ft_ld_lld(vm, carriage);
	else if ((*carriage)->ex_cod == 3)
		ft_st(vm, carriage);
	else if ((*carriage)->ex_cod == 4 || (*carriage)->ex_cod == 5)
		ft_add_sub(vm, carriage);
	else if ((*carriage)->ex_cod == 6 || (*carriage)->ex_cod == 7 ||
	(*carriage)->ex_cod == 8)
		ft_log(vm, carriage);
	else if ((*carriage)->ex_cod == 9)
		ft_zjmp(vm, carriage);
	else if ((*carriage)->ex_cod == 10 || (*carriage)->ex_cod == 14)
		ft_ldi_lldi(vm, carriage);
	else if ((*carriage)->ex_cod == 11)
		ft_sti(vm, carriage);
	else if ((*carriage)->ex_cod == 12 || (*carriage)->ex_cod == 15)
		ft_fork_lfork(vm, carriage);
	else
		ft_aff(vm, carriage);
}

void				ft_fight_champ_help(t_vm *vm, t_carriage **tmp)
{
	if ((*tmp)->current_position < 0)
		(*tmp)->current_position = MEM_SIZE +
		(*tmp)->current_position % MEM_SIZE;
	if ((*tmp)->count_wait_cicle == 0)
	{
		(*tmp)->ex_cod = vm->arena[(*tmp)->current_position % MEM_SIZE];
		if ((*tmp)->ex_cod >= 1 && (*tmp)->ex_cod <= 16)
			(*tmp)->count_wait_cicle = vm->op[(*tmp)->ex_cod].count_cicle;
		else
		{
			(*tmp)->current_position = ((*tmp)->current_position +
			OP_SIZE) % MEM_SIZE;
			(*tmp)->ex_cod = vm->arena[(*tmp)->current_position];
		}
	}
	if ((*tmp)->count_wait_cicle == 1)
		ft_op(vm, tmp);
	if ((*tmp)->count_wait_cicle > 0)
		(*tmp)->count_wait_cicle--;
	(*tmp) = (*tmp)->next;
}

void				ft_fight_champ(t_vm *vm, t_sdl *sdl)
{
	t_carriage		*tmp;
	int				i;

	i = 0;
	vm->count_live_period = 0;
	while (1)
	{
		tmp = vm->carriage;
		if (vm->show == 2)
			ft_printf("It is now cycle %d\n", vm->count_cicle + 1);
		if (vm->debug != -1 && vm->debug != 0)
			ft_flag_debug(vm);
		if (vm->dump > 0 && vm->dump == vm->count_cicle)
			break ;
		(sdl) ? ft_viz(vm, sdl) : 0;
		while (tmp)
			ft_fight_champ_help(vm, &tmp);
		vm->count_cicle++;
		vm->count_cycle_in_period++;
		i++;
		if (i >= vm->cycle_to_die || vm->cycle_to_die <= 0)
			break ;
	}
}

void				ft_change_cicle_to_die(t_vm *vm)
{
	if (vm->count_live_period >= NBR_LIVE)
		vm->cycle_to_die -= CYCLE_DELTA;
	else if (vm->max_check == MAX_CHECKS - 1)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		vm->max_check = 0;
	}
	else
		vm->max_check++;
}
