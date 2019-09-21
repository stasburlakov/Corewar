/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 04:53:48 by ljonnel-          #+#    #+#             */
/*   Updated: 2018/11/28 04:53:50 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (dest[len])
		len++;
	i = 0;
	while (src[i] && i < n)
	{
		dest[i + len] = src[i];
		i++;
	}
	dest[i + len] = '\0';
	return (dest);
}
