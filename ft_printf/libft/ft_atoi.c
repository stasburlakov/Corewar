/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 04:52:53 by ljonnel-          #+#    #+#             */
/*   Updated: 2018/11/28 04:53:09 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int value;
	int size;

	value = 0;
	size = 1;
	while (*nptr == '\n' || *nptr == ' ' || *nptr == '\t'
	|| *nptr == '\v' || *nptr == '\f' || *nptr == '\r')
		nptr++;
	if (*nptr == '-')
	{
		size = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		value = value * 10 + (int)*nptr - 48;
		nptr++;
	}
	if (size == -1 && value == 0)
		return (0);
	return (size * value);
}
