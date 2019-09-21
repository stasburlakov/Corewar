/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:41:46 by ljonnel-          #+#    #+#             */
/*   Updated: 2018/12/08 23:18:40 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_size(long long int i)
{
	int size;

	if (i < 0)
	{
		i *= -1;
		size = 1;
	}
	else
		size = 0;
	while (i != 0)
	{
		size++;
		i = i / 10;
	}
	return (size);
}

char		*ft_lltoa(long long int i)
{
	char	*str;
	int		size;

	if (i == 0)
	{
		str = ft_strnew(1);
		str[0] = '0';
		return (str);
	}
	else if (i == -9223372036854775807 - 1)
		return (ft_strdup("-9223372036854775808"));
	size = ft_count_size(i);
	str = ft_strnew(size);
	(i < 0) ? (i *= -1) : 0;
	while (size-- > 0 && i)
	{
		str[size] = i % 10 + '0';
		i = i / 10;
	}
	if (!str[0])
		str[0] = '-';
	return (str);
}
