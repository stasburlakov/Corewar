/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_champ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 16:54:44 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/26 16:54:45 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar_vm.h"

int		ft_check_magic_header(int fd)
{
	unsigned char	s;
	int				tmp;
	int				tmp_header;

	tmp = -1;
	tmp_header = 0;
	while (++tmp < 4 && read(fd, &s, 1) > 0)
		tmp_header = tmp_header << 8 | s;
	if (tmp_header == COREWAR_EXEC_MAGIC)
		return (1);
	return (-1);
}

void	ft_check_size_champ(t_vm *vm, int i, int fd)
{
	unsigned char	s;
	int				tmp;
	int				tmp_header;

	tmp = -1;
	tmp_header = 0;
	while (++tmp < 4 && read(fd, &s, 1) > 0)
		tmp_header = tmp_header << 8 | s;
	vm->champ[i].size_champ = tmp_header;
	if (vm->champ[i].size_champ > CHAMP_MAX_SIZE)
		ft_error(vm, ERROR_CHAMP_MAX_SIZE, i);
}

void	ft_rewrite(t_vm *vm, int position, int number)
{
	int				i;

	i = 4;
	if (position < 0)
		position = MEM_SIZE + position % MEM_SIZE;
	while (i > 0)
	{
		vm->arena[(position + i - 1) % MEM_SIZE] = number & MASK;
		number = number >> 8;
		i--;
	}
}

int		ft_check_number_help(t_vm *vm, int position, int byte)
{
	unsigned short	num1;
	int				i;

	i = -1;
	num1 = 0;
	while (++i < byte)
	{
		num1 = num1 | ((unsigned char)(vm->arena[(position + i) % MEM_SIZE]));
		if (i == 1)
			break ;
		num1 = num1 << 8;
	}
	return (num1);
}

void	ft_check_champ(t_vm *vm, int i, int fd)
{
	int	buf;
	int	ret;

	buf = 5;
	if (ft_check_magic_header(fd) == -1)
		ft_error(vm, ERROR_MAGIC_HEADER, i);
	read(fd, vm->champ[i].name, PROG_NAME_LENGTH);
	read(fd, &buf, 4);
	if (buf != 0)
		ft_error(vm, ERROR_CHAMP_NAME_SIZE, i);
	ft_check_size_champ(vm, i, fd);
	read(fd, vm->champ[i].comment, COMMENT_LENGTH);
	read(fd, &buf, 4);
	if (buf != 0)
		ft_error(vm, ERROR_COMMENT_SIZE, i);
	ret = read(fd, vm->champ[i].ex_cod, vm->champ[i].size_champ + 10);
	if (ret != vm->champ[i].size_champ)
		ft_error(vm, ERROR_CHAMP_CHECK_SIZE, i);
}
