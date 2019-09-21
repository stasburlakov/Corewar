/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 16:55:22 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/26 16:55:23 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar_vm.h"

void				ft_create_op_4(t_vm *vm)
{
	ft_strcpy(vm->op[9].description, "jump if zero");
	ft_strcpy(vm->op[10].name_op, "ldi");
	ft_strcpy(vm->op[10].description, "load index");
	ft_strcpy(vm->op[11].name_op, "sti");
	ft_strcpy(vm->op[11].description, "store index");
	ft_strcpy(vm->op[12].name_op, "fork");
	ft_strcpy(vm->op[12].description, "fork");
	ft_strcpy(vm->op[13].name_op, "lld");
	ft_strcpy(vm->op[13].description, "long load");
	ft_strcpy(vm->op[14].name_op, "lldi");
	ft_strcpy(vm->op[14].description, "long load index");
	ft_strcpy(vm->op[15].name_op, "lfork");
	ft_strcpy(vm->op[15].description, "long fork");
	ft_strcpy(vm->op[16].name_op, "aff");
	ft_strcpy(vm->op[16].description, "aff");
}

void				ft_create_op_3(t_vm *vm)
{
	ft_strcpy(vm->op[0].name_op, "\0");
	ft_strcpy(vm->op[1].description, "\0");
	ft_strcpy(vm->op[1].name_op, "live");
	ft_strcpy(vm->op[1].description, "alive");
	ft_strcpy(vm->op[2].name_op, "ld");
	ft_strcpy(vm->op[2].description, "load");
	ft_strcpy(vm->op[3].name_op, "st");
	ft_strcpy(vm->op[3].description, "store");
	ft_strcpy(vm->op[4].name_op, "add");
	ft_strcpy(vm->op[4].description, "addition");
	ft_strcpy(vm->op[5].name_op, "sub");
	ft_strcpy(vm->op[5].description, "soustraction");
	ft_strcpy(vm->op[6].name_op, "and");
	ft_strcpy(vm->op[6].description, "et (and  r1, r2, r3   r1&r2 . r3");
	ft_strcpy(vm->op[7].name_op, "or");
	ft_strcpy(vm->op[7].description, "ou  (or   r1, r2, r3   r1 | r2 . r3");
	ft_strcpy(vm->op[8].name_op, "xor");
	ft_strcpy(vm->op[8].description, "ou (xor  r1, r2, r3   r1^r2 . r3");
	ft_strcpy(vm->op[9].name_op, "zjmp");
}

void				ft_create_op_2(t_vm *vm)
{
	int				i;

	i = -1;
	while (++i < 17)
	{
		if (i == 13 || i == 1 || i == 4 || i == 5)
			vm->op[i].count_cicle = 10;
		else if (i == 2 || i == 3)
			vm->op[i].count_cicle = 5;
		else if (i == 6 || i == 7 || i == 8)
			vm->op[i].count_cicle = 6;
		else if (i == 10 || i == 11)
			vm->op[i].count_cicle = 25;
		else if (i == 9)
			vm->op[i].count_cicle = 20;
		else if (i == 12)
			vm->op[i].count_cicle = 800;
		else if (i == 14)
			vm->op[i].count_cicle = 50;
		else if (i == 15)
			vm->op[i].count_cicle = 1000;
		else if (i == 16)
			vm->op[i].count_cicle = 2;
	}
}

void				ft_create_op_1(t_vm *vm)
{
	int				i;

	i = -1;
	while (++i < 17)
	{
		if (i == 0)
			vm->op[i].count_arg = 0;
		else if (i == 1 || i == 9 || i == 12 || i == 15 || i == 16)
			vm->op[i].count_arg = 1;
		else if (i == 2 || i == 3 || i == 13)
			vm->op[i].count_arg = 2;
		else
			vm->op[i].count_arg = 3;
		if (i == 0)
			vm->op[i].size_t_dir = 0;
		else if (i == 9 || i == 10 || i == 11 || i == 12 || i == 14 || i == 15)
			vm->op[i].size_t_dir = 2;
		else
			vm->op[i].size_t_dir = 4;
	}
	ft_create_op_2(vm);
	ft_create_op_3(vm);
	ft_create_op_4(vm);
}

void				ft_check_priority_flags(t_vm *vm)
{
	int				i;

	i = 0;
	if (vm->index_viz != -1)
		i++;
	if (vm->dump != -1)
		i++;
	if (vm->debug != -1)
		i++;
	if (vm->show != -1)
		i++;
	if (i > 1)
		ft_error(vm, ERROR_USAGE, 0);
}
