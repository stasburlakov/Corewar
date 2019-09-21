/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 16:54:49 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/26 16:54:50 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar_vm.h"

static void	ft_error_help(t_vm *vm, int error, int i)
{
	if (error == ERROR_COMMENT_SIZE)
	{
		ft_putstr_fd("Error: File ", 2);
		ft_putstr_fd(vm->champ[i].file_champ, 2);
		ft_putstr_fd(". Champion comment too long (Max length 2048)\n", 2);
	}
	else if (error == ERROR_USAGE)
		ft_help();
	else if (error == ERROR_CHAMP_NAME_SIZE)
	{
		ft_putstr_fd("Error: File ", 2);
		ft_putstr_fd(vm->champ[i].file_champ, 2);
		ft_putstr_fd(". Champion name too long (Max length 128)\n", 2);
	}
	else if (error == ERROR_CHAMP_CHECK_SIZE)
	{
		ft_putstr_fd("Error: File ", 2);
		ft_putstr_fd(vm->champ[i].file_champ, 2);
		ft_putstr_fd(". Actual and declared size do not match\n", 2);
	}
}

void		ft_error(t_vm *vm, int error, int i)
{
	if (error == ERROR_MALLOC)
		ft_putstr_fd("Error: Maloc buh buh\n", 2);
	else if (error == ERROR_COUNT_CHAMP)
		ft_putstr_fd("Error: Too many champions\n", 2);
	else if (error == ERROR_CHAMP_MAX_SIZE)
	{
		ft_putstr_fd("Error: File ", 2);
		ft_putstr_fd(vm->champ[i].file_champ, 2);
		ft_putstr_fd(" has too large a code (Max - 682 bytes)\n", 2);
	}
	else if (error == ERROR_MAGIC_HEADER)
	{
		ft_putstr_fd("Error: File ", 2);
		ft_putstr_fd(vm->champ[i].file_champ, 2);
		ft_putstr_fd(" incorrect magic_header\n", 2);
	}
	else
		ft_error_help(vm, error, i);
	ft_free_vm(vm);
	exit(-1);
}
