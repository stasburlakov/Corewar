/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 00:02:01 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/04/29 00:02:03 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(const char *s)
{
	int64_t	value;
	char	size;

	value = 0;
	size = 1;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (*s == '-')
	{
		size = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s <= '9' && *s >= '0')
	{
		value = value * 10 + *s - '0';
		s++;
	}
	return (long long int)value;
}
