/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:13:21 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/25 15:13:22 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar_vm.h"

int		ft_check_reg(t_vm *vm, t_carriage **carriage,
int *arg, int count)
{
	arg[0] += 1;
	arg[arg[0]] = vm->arena[((*carriage)->current_position + count) % MEM_SIZE];
	if (arg[arg[0]] < 1 || arg[arg[0]] > REG_NUMBER)
		arg[4] += 1;
	else
		arg[arg[0]]--;
	return (count + T_REG);
}

void	ft_zjmp(t_vm *vm, t_carriage **carriage)
{
	short int		number;

	number = ft_check_number(vm, (*carriage)->current_position + OP_SIZE,
	vm->op[(*carriage)->ex_cod].size_t_dir);
	if ((*carriage)->carry == 1)
	{
		(*carriage)->current_position = ((*carriage)->current_position +
		number % IDX_MOD) % MEM_SIZE;
		if ((*carriage)->current_position < 0)
			(*carriage)->current_position = MEM_SIZE +
			(*carriage)->current_position;
	}
	else
		(*carriage)->current_position = ((*carriage)->current_position +
		vm->op[(*carriage)->ex_cod].size_t_dir + OP_SIZE) % MEM_SIZE;
}

int		ft_check_number(t_vm *vm, int position, int byte)
{
	unsigned int	num1;
	int				i;

	i = -1;
	num1 = 0;
	if (position < 0)
		position = MEM_SIZE + position % MEM_SIZE;
	if (byte == 4)
	{
		while (++i < byte)
		{
			num1 = num1 << 8;
			num1 = num1 | ((unsigned char)(vm->arena[(position + i) %
			MEM_SIZE]));
		}
		return (num1);
	}
	else
		return (ft_check_number_help(vm, position, byte));
	return (-1);
}

int		ft_check_step(int size_t_dir, unsigned char *cod_arg, int i)
{
	int	j;
	int	step;

	j = 1;
	step = ARG_SIZE + OP_SIZE;
	while (j <= i)
	{
		if (cod_arg[j] == REG_CODE)
			step += REG_CODE;
		else if (cod_arg[j] == DIR_CODE)
			step += size_t_dir;
		else if (cod_arg[j] == IND_CODE)
			step += IND_SIZE;
		j++;
	}
	return (step);
}
