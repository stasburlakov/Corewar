/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 21:22:23 by ljonnel-          #+#    #+#             */
/*   Updated: 2018/12/21 21:22:26 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_exp_int(int base, int pow)
{
	int compos;

	compos = 1;
	if (pow <= 0)
		return (1);
	while (pow-- > 0)
		compos = compos * base;
	return (compos);
}
