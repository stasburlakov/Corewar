/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_champ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 16:57:47 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/26 16:57:48 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar_vm.h"

void				ft_count_champ(int argc, char **argv, t_vm *vm)
{
	int				len;
	int				i;

	len = 0;
	i = 1;
	while (i < argc)
	{
		len = ft_strlen(argv[i]);
		if (len > 4 && (ft_strcmp(argv[i] + len - 4, ".cor") == 0))
			vm->count_champ++;
		i++;
	}
}

void				ft_parse_champ_flag_n_help_2(char **argv, t_vm *vm,
					int n, int i)
{
	int				len;

	len = ft_strlen(argv[i]);
	if (len > 4 && (ft_strcmp(argv[i] + len - 4, ".cor") == 0))
	{
		vm->champ[n].file_champ = argv[i];
		vm->champ[n].number = n;
	}
}

int					ft_parse_champ_flag_n_help_1(int argc, char **argv,
					t_vm *vm, int i)
{
	int				n;

	n = -1;
	if (i < argc)
		n = ft_is_number(argv[i]) ? ft_atoi(argv[i]) : -1;
	else
		ft_error(vm, ERROR_USAGE, 0);
	if (n <= 0 || n > vm->count_champ)
		ft_error(vm, ERROR_USAGE, 0);
	return (n);
}

void				ft_parse_champ_flag_n(int argc, char **argv, t_vm *vm,
					int *s)
{
	int				i;
	int				n;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-n") == 0)
		{
			n = ft_parse_champ_flag_n_help_1(argc, argv, vm, ++i);
			if (s[n] == 0)
			{
				s[n] = 1;
				if (++i < argc)
					ft_parse_champ_flag_n_help_2(argv, vm, n, i);
				else
					ft_error(vm, ERROR_USAGE, 0);
				vm->count_flag += 2;
			}
			else
				ft_error(vm, ERROR_USAGE, 0);
		}
		i++;
	}
}

void				ft_parse_champ(int argc, char **argv, t_vm *vm, int *s)
{
	int				i;
	int				len;
	int				n;

	n = 1;
	i = 1;
	while (i < argc)
	{
		len = ft_strlen(argv[i]);
		if (len > 4 && (ft_strcmp(argv[i] + len - 4, ".cor") == 0))
		{
			if (i <= 2 || (i >= 3 && ft_strcmp(argv[i - 2], "-n") != 0))
			{
				while (s[n] == 1 && n <= vm->count_champ)
					n++;
				s[n] = 1;
				vm->champ[n].file_champ = argv[i];
				vm->champ[n].number = n;
			}
		}
		i++;
	}
}
