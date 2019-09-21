/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 00:55:11 by ljonnel-          #+#    #+#             */
/*   Updated: 2018/11/28 00:55:13 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p0;
	unsigned char	*p1;

	p0 = (unsigned char *)dest;
	p1 = (unsigned char *)src;
	if (dest != src)
	{
		while (n-- > 0)
			*(p0++) = *(p1++);
	}
	return (dest);
}
