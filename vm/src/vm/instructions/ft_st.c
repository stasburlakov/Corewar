/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:07:47 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/25 15:07:48 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar_vm.h"

int		ft_st_help(t_vm *vm, t_carriage **carriage,
unsigned char *cod_arg, int *arg)
{
	int	count;
	int	i;

	count = ft_st_op(vm, carriage, cod_arg, arg);
	if (arg[4] == 0)
	{
		if (cod_arg[1] == cod_arg[2])
			(*carriage)->r[arg[2]] = (*carriage)->r[arg[1]];
		else
		{
			ft_rewrite(vm, (*carriage)->current_position + arg[2] % IDX_MOD,
			(*carriage)->r[arg[1]]);
			i = -1;
			while (++i < 4)
				vm->player_arena[((*carriage)->current_position +
				count + i) % MEM_SIZE] = (*carriage)->number_champ;
		}
		return (count);
	}
	return (0);
}

void	ft_st(t_vm *vm, t_carriage **carriage)
{
	unsigned char	cod_arg[4];
	int				arg[5];
	int				step;

	step = 0;
	ft_check_arg(vm, carriage, cod_arg, arg);
	if ((int)cod_arg[1] == REG_CODE && (int)cod_arg[2] != 0 &&
	(int)cod_arg[2] != DIR_CODE)
		step = ft_st_help(vm, carriage, cod_arg, arg);
	if (step == 0)
		step = ft_check_step(vm->op[(*carriage)->ex_cod].size_t_dir,
		cod_arg, vm->op[(*carriage)->ex_cod].count_arg);
	(*carriage)->current_position = ((*carriage)->current_position +
	step) % MEM_SIZE;
}

int		ft_st_op(t_vm *vm, t_carriage **carriage,
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
			count = ft_check_ind_st(vm, carriage, arg, count);
	}
	return (count);
}

int		ft_check_ind_st(t_vm *vm, t_carriage **carriage, int *arg, int count)
{
	arg[0] += 1;
	arg[arg[0]] = ((short int)ft_check_number(vm,
	(*carriage)->current_position + count, IND_SIZE)) % IDX_MOD;
	return (count + IND_SIZE);
}
