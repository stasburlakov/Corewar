/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 03:12:35 by ljonnel-          #+#    #+#             */
/*   Updated: 2018/11/28 03:12:39 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s0, const void *s1, size_t n)
{
	unsigned char	*p0;
	unsigned char	*p1;
	size_t			i;

	i = 0;
	p0 = (unsigned char *)s0;
	p1 = (unsigned char *)s1;
	while (i < n)
	{
		if (p0[i] != p1[i] && (p0[i] || p1[i]))
			return (p0[i] - p1[i]);
		i++;
	}
	return (0);
}
