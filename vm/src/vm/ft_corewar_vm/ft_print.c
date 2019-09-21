/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 16:58:08 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/26 16:58:09 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar_vm.h"

int					ft_is_number(char *str)
{
	int				i;
	int				len;

	i = 0;
	len = ft_strlen(str);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		i++;
	if (i == len)
		return (ft_is_number_help(str));
	return (0);
}

void				ft_intro_champs(t_vm *vm)
{
	int				i;

	i = 1;
	ft_putstr("Introducing contestants...\n");
	while (i <= vm->count_champ)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", i,
			vm->champ[i].size_champ, vm->champ[i].name, vm->champ[i].comment);
		i++;
	}
}

void				ft_win_champ(t_vm *vm)
{
	vm->winner = vm->champ[-vm->champ_said_a_live].cut_name;
	ft_printf("Contestant %d, \"%s\", has won !\n",
	vm->champ[-vm->champ_said_a_live].number,
	vm->champ[-vm->champ_said_a_live].name);
}

void				ft_help(void)
{
	ft_putstr("Usage: ./corewar [-a] [-dump N | -d N | -s N | -v -ninja]");
	ft_putstr("[-n N] <champion1.cor> <...>\n");
	ft_putstr("	-a      : Prints output from aff (Default is to hide it)\n");
	ft_putstr("	-n N    ; The choice of the position of the player\n");
	ft_putstr("#### TEXT OUTPUT MODE ####################################");
	ft_putstr("##################\n");
	ft_putstr("	-dump N : Dumps memory after N cycles then exits\n");
	ft_putstr("	-d N    : Runs N cycles, dumps memory, pauses, then repeats\n");
	ft_putstr("	-s N    : Verbosity levels, can");
	ft_putstr("be added together to enable several\n");
	ft_putstr("		- 1 : Show lives\n");
	ft_putstr("		- 2 : Show cycles\n");
	ft_putstr("#### SDL OUTPUT MODE #####################################");
	ft_putstr("##################\n");
	ft_putstr("	-v      : SDL output mode\n");
	ft_putstr("	--ninja : Hides the real contents of the memory\n");
	ft_putstr("####################################");
	ft_putstr("########################################\n");
}
