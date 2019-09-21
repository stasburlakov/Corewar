/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egottlie <egottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 10:10:32 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/26 17:59:37 by egottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar_vm.h"

int					ft_flag_dump(t_vm *vm)
{
	int				dump;
	int				i;
	int				k;

	i = 0;
	k = 0;
	while (i < MEM_SIZE && vm->dump == vm->count_cicle)
	{
		dump = 0;
		ft_printf("0x%.4x : ", k * 64);
		while (dump < 64 && i < MEM_SIZE)
		{
			ft_printf("%.2hhx ", vm->arena[i]);
			dump++;
			i++;
		}
		k++;
		ft_printf("\n");
	}
	if (i > 0)
		return (1);
	return (0);
}

void				ft_flag_debug(t_vm *vm)
{
	int				dump;
	char			c;
	int				i;
	int				k;

	i = 0;
	k = 0;
	if ((vm->count_cicle % vm->debug == 0) && read(0, &c, 1))
	{
		while (i < MEM_SIZE)
		{
			dump = 0;
			ft_printf("0x%.4x : ", k * 64);
			while (dump < 64 && i < MEM_SIZE)
			{
				ft_printf("%.2hhx ", vm->arena[i]);
				dump++;
				i++;
			}
			k++;
			ft_printf("\n");
		}
	}
}

void				ft_play_game(t_vm *vm, t_sdl *sdl)
{
	int				i;

	i = vm->cycle_to_die;
	while (vm->carriage)
	{
		if (i > vm->cycle_to_die && vm->show == 2)
		{
			i = vm->cycle_to_die;
			ft_printf("Cycle to die is now %d\n", vm->cycle_to_die);
		}
		ft_memset(vm->last_live, 0, 16);
		ft_memset(vm->live_in_period, 0, 16);
		vm->count_cycle_in_period = 0;
		ft_fight_champ(vm, sdl);
		ft_kill_carriage(vm);
		ft_change_cicle_to_die(vm);
		if (vm->dump > 0 && vm->dump == vm->count_cicle)
			break ;
	}
}

void				ft_preparation_champ(int argc, char **argv, t_vm *vm)
{
	int				i;
	int				s[MAX_PLAYERS + 1];

	i = 1;
	ft_count_champ(argc, argv, vm);
	if (vm->count_champ > MAX_PLAYERS)
		ft_error(vm, ERROR_COUNT_CHAMP, 0);
	else if (vm->count_champ <= 0)
		ft_error(vm, ERROR_USAGE, 0);
	ft_check_flag_and_champs(argc, argv, vm, i);
	if (!(vm->champ = (t_champ *)malloc(sizeof(t_champ) *
		(vm->count_champ + 1))))
		ft_error(vm, ERROR_MALLOC, 0);
	i = -1;
	while (++i <= vm->count_champ)
		s[i] = 0;
	ft_parse_champ_flag_n(argc, argv, vm, s);
	ft_parse_champ(argc, argv, vm, s);
	ft_parse_corewar(vm);
	if (argc - 1 != vm->count_flag + vm->count_champ)
		ft_error(vm, ERROR_USAGE, 0);
	ft_check_priority_flags(vm);
}

int					main(int argc, char **argv)
{
	t_vm			*vm;
	t_sdl			*sdl;

	if ((vm = (t_vm*)malloc(sizeof(t_vm))) == NULL)
		ft_error(vm, ERROR_MALLOC, 0);
	ft_init(vm);
	if (argc == 1)
		ft_error(vm, ERROR_USAGE, 0);
	else
		ft_preparation_champ(argc, argv, vm);
	sdl = (vm->index_viz != -1) ? ft_sdl_init(vm) : NULL;
	ft_init_arena(vm);
	ft_intro_champs(vm);
	if (sdl)
		ft_naming_player(sdl, vm);
	ft_play_game(vm, sdl);
	if (ft_flag_dump(vm) == 0)
		ft_win_champ(vm);
	(sdl) ? ft_viz_winner(vm, sdl) : 0;
	ft_free_vm(vm);
}
