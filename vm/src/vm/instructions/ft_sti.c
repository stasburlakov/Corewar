/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:01:57 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/25 15:01:59 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar_vm.h"

int		ft_sti_help(t_vm *vm, t_carriage **carriage,
unsigned char *cod_arg, int *arg)
{
	int	count;
	int	i;
	int	tmp;

	count = ft_log_op(vm, carriage, cod_arg, arg);
	if (arg[4] == 0)
	{
		i = 1;
		while (++i <= 3)
		{
			tmp = arg[i];
			if (cod_arg[i] == REG_CODE)
				arg[i] = (*carriage)->r[tmp];
		}
		ft_rewrite(vm, (*carriage)->current_position + (arg[2] +
		arg[3]) % IDX_MOD, (*carriage)->r[arg[1]]);
		i = -1;
		while (++i < 4)
			vm->player_arena[((*carriage)->current_position + count +
			i) % MEM_SIZE] = (*carriage)->number_champ;
		return (count);
	}
	return (0);
}

void	ft_sti(t_vm *vm, t_carriage **carriage)
{
	unsigned char	cod_arg[4];
	int				arg[5];
	int				step;

	step = 0;
	ft_check_arg(vm, carriage, cod_arg, arg);
	if ((int)cod_arg[1] == REG_CODE && (int)cod_arg[3] != IND_CODE &&
	(int)cod_arg[2] != 0 && (int)cod_arg[3] != 0)
		step = ft_sti_help(vm, carriage, cod_arg, arg);
	if (step == 0)
		step = ft_check_step(vm->op[(*carriage)->ex_cod].size_t_dir,
		cod_arg, vm->op[(*carriage)->ex_cod].count_arg);
	(*carriage)->current_position = ((*carriage)->current_position +
	step) % MEM_SIZE;
}
