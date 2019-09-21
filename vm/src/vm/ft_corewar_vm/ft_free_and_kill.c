/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_kill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 16:55:00 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/26 16:55:01 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar_vm.h"

void				ft_kill_carriage_help(t_vm *vm, t_carriage **tmp, \
					t_carriage **tmp1)
{
	if (vm->count_cicle - (*tmp)->cicle_last_live >= vm->cycle_to_die
		&& (*tmp) == vm->carriage)
	{
		vm->count_carriage--;
		vm->carriage = vm->carriage->next;
		free((*tmp));
		(*tmp) = vm->carriage;
		(*tmp1) = vm->carriage;
	}
	else if (vm->count_cicle - (*tmp)->cicle_last_live >= vm->cycle_to_die)
	{
		vm->count_carriage--;
		(*tmp1)->next = (*tmp1)->next->next;
		free((*tmp));
		(*tmp) = (*tmp1);
	}
}

void				ft_kill_carriage(t_vm *vm)
{
	t_carriage		*tmp;
	t_carriage		*tmp1;

	tmp = vm->carriage;
	tmp1 = vm->carriage;
	while (vm != NULL && tmp != NULL)
	{
		if ((vm->count_cicle - tmp->cicle_last_live >= vm->cycle_to_die && \
			tmp == vm->carriage) || \
			(vm->count_cicle - tmp->cicle_last_live >= vm->cycle_to_die))
			ft_kill_carriage_help(vm, &tmp, &tmp1);
		else if (tmp != NULL)
		{
			tmp1 = tmp;
			tmp = tmp->next;
		}
		else
			break ;
	}
}

void				ft_free_vm(t_vm *vm)
{
	t_carriage		*tmp1;

	if (vm)
	{
		while (vm->carriage)
		{
			tmp1 = vm->carriage->next;
			free(vm->carriage);
			vm->carriage = tmp1;
		}
		if (vm->champ)
			free(vm->champ);
		if (vm->arena)
			free(vm->arena);
		if (vm->op)
			free(vm->op);
		free(vm);
	}
}
