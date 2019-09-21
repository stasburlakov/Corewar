/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 00:16:40 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/04/29 00:16:41 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_size(unsigned long long tmp, char base)
{
	int size;

	size = 0;
	while (tmp != 0)
	{
		size++;
		tmp = tmp / base;
	}
	return (size);
}

char		*ft_ulltoa_base(unsigned long long i, char base)
{
	char				*str;
	unsigned long long	tmp;
	int					size;

	if (base <= 0 || base > 16)
		return (NULL);
	if (i == 0)
	{
		str = ft_strnew(1);
		str[0] = '0';
		return (str);
	}
	size = ft_count_size(i, base);
	str = ft_strnew(size);
	while (size-- > 0)
	{
		tmp = i % base;
		if (tmp >= 10)
			str[size] = tmp + 87;
		else
			str[size] = tmp + '0';
		i = i / base;
	}
	return (str);
}
