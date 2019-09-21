/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 04:54:18 by ljonnel-          #+#    #+#             */
/*   Updated: 2018/11/28 04:54:19 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	i = 0;
	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	while (i < n && dest[i])
		i++;
	if (i == n)
		return (n + slen);
	while (*src && i < (n - 1))
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return (dlen + slen);
}
