/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld_lld_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egottlie <egottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:46:43 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/26 18:01:25 by egottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar_vm.h"

void	ft_ld_lld(t_vm *vm, t_carriage **carriage)
{
	unsigned char	cod_arg[4];
	int				arg[5];
	int				step;
	int				count;

	step = 0;
	ft_check_arg(vm, carriage, cod_arg, arg);
	if (cod_arg[1] != REG_CODE && cod_arg[1] != 0 && cod_arg[2] == REG_CODE)
	{
		count = ft_lld_op(vm, carriage, cod_arg, arg);
		if (arg[4] == 0)
		{
			ft_lld_help(cod_arg, arg, carriage);
			((*carriage)->ex_cod == 2) ? ((*carriage)->r[arg[2]] = arg[1])
			: ((*carriage)->r[arg[2]] = arg[1]);
			(*carriage)->carry = (*carriage)->r[arg[2]] == 0 ? 1 : 0;
			step = count;
		}
	}
	if (step == 0)
		step = ft_check_step(vm->op[(*carriage)->ex_cod].size_t_dir,
		cod_arg, vm->op[(*carriage)->ex_cod].count_arg);
	(*carriage)->current_position =
	((*carriage)->current_position + step) % MEM_SIZE;
}

void	ft_lld_help(unsigned char *cad_arg, int *arg, t_carriage **carriage)
{
	int				i;
	int				tmp;

	i = 0;
	while (++i <= 1)
	{
		tmp = arg[i];
		if (cad_arg[i] == REG_CODE)
			arg[i] = (*carriage)->r[tmp];
	}
}

int		ft_lld_op(t_vm *vm, t_carriage **carriage,
unsigned char *cod_arg, int *arg)
{
	int				count;
	int				i;

	i = 0;
	count = OP_SIZE + ARG_SIZE;
	while (++i <= 2)
	{
		if (cod_arg[i] == REG_CODE)
			count = ft_check_reg(vm, carriage, arg, count);
		else if (cod_arg[i] == DIR_CODE)
			count = ft_check_dir_log(vm, carriage, arg, count);
		else if (cod_arg[i] == IND_CODE)
			count = ft_check_ind_lld(vm, carriage, arg, count);
	}
	return (count);
}

int		ft_check_ind_lld(t_vm *vm, t_carriage **carriage, int *arg, int count)
{
	int	position;

	position = 0;
	arg[0] += 1;
	if ((*carriage)->ex_cod == 2)
	{
		position = (*carriage)->current_position +
		((short int)(ft_check_number(vm, (*carriage)->current_position
		+ count, IND_SIZE)) % IDX_MOD);
		arg[arg[0]] = ft_check_number(vm, position, REG_SIZE);
	}
	else
	{
		position = (*carriage)->current_position +
		((short int)ft_check_number(vm, (*carriage)->current_position +
		count, IND_SIZE));
		arg[arg[0]] = ft_check_number(vm, position, REG_SIZE);
	}
	return (count + IND_SIZE);
}
