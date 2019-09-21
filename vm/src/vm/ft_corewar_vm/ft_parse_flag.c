/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egottlie <egottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 16:57:52 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/26 17:20:17 by egottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar_vm.h"

void				ft_check_flag_and_champs_help(char **argv, t_vm *vm,
					int *i, int argc)
{
	if (ft_strcmp(argv[(*i)], "-v") == 0)
	{
		if (vm->index_viz == 1 || vm->index_viz == 2)
			ft_error(vm, ERROR_USAGE, 0);
		if ((*i) + 1 < argc && (ft_strcmp(argv[(*i) + 1], "--ninja") == 0))
		{
			vm->index_viz = 1;
			++(*i);
			vm->count_flag += 2;
		}
		else
		{
			vm->count_flag += 1;
			vm->index_viz = 2;
		}
	}
	else
		ft_check_flag_and_champs_help_2(argv, vm, i, argc);
}

void				ft_check_flag_and_champs_help_2(char **argv, t_vm *vm,
					int *i, int argc)
{
	if (ft_strcmp(argv[(*i)], "-s") == 0)
	{
		if (++(*i) >= argc || vm->show != -1)
			ft_error(vm, ERROR_USAGE, 0);
		vm->show = ft_is_number(argv[(*i)]) ? ft_atoi(argv[(*i)]) : -2;
		if ((vm->show != 1 && vm->show != 2) || vm->show == -2)
			ft_error(vm, ERROR_USAGE, 0);
		vm->count_flag += 2;
	}
	else if (ft_strcmp(argv[(*i)], "-a") == 0)
	{
		if (vm->flag_aff == 1)
			ft_error(vm, ERROR_USAGE, 0);
		vm->flag_aff = 1;
		vm->count_flag += 1;
	}
}

void				ft_check_flag_and_champs(int argc, char **argv, t_vm *vm,
					int i)
{
	while (i < argc)
	{
		if (strcmp(argv[i], "-dump") == 0)
		{
			if (++i >= argc || vm->dump != -1)
				ft_error(vm, ERROR_USAGE, 0);
			vm->dump = ft_is_number(argv[i]) ? ft_atoi(argv[i]) : -2;
			if (vm->dump < 0)
				ft_error(vm, ERROR_USAGE, 0);
			vm->count_flag += 2;
		}
		else if (ft_strcmp(argv[i], "-d") == 0)
		{
			if (++i >= argc || vm->debug != -1)
				ft_error(vm, ERROR_USAGE, 0);
			vm->debug = ft_is_number(argv[i]) ? ft_atoi(argv[i]) : -2;
			if (vm->debug <= 0)
				ft_error(vm, ERROR_USAGE, 0);
			vm->count_flag += 2;
		}
		else
			ft_check_flag_and_champs_help(argv, vm, &i, argc);
		i++;
	}
}

int					ft_is_number_help(char *str)
{
	int				i;
	int				j;
	int				num;
	char			*num_str;

	i = 0;
	j = 0;
	num = ft_atoi(str);
	num_str = ft_lltoa(num);
	if (str[i] == '-' || str[i] == '+')
		j++;
	while (str[i + j] == 0)
		i++;
	if (str[i + j] == num_str[j])
	{
		free(num_str);
		return (1);
	}
	else
		free(num_str);
	return (0);
}

void				ft_parse_corewar(t_vm *vm)
{
	int				i;
	int				fd;

	fd = -1;
	i = 1;
	while (i <= vm->count_champ)
	{
		fd = open(vm->champ[i].file_champ, O_RDONLY);
		if (fd < 0)
		{
			ft_putstr_fd("Error: Can't read source file ", 2);
			ft_putstr_fd(vm->champ[i].file_champ, 2);
			ft_error(vm, ERROR_READ, i);
		}
		ft_check_champ(vm, i, fd);
		close(fd);
		i++;
	}
}
