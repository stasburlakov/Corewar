/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 04:54:26 by ljonnel-          #+#    #+#             */
/*   Updated: 2018/12/08 23:10:06 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!n)
		return (0);
	while ((*s1 || *s2) && i < n)
	{
		if ((s1[i] != s2[i]) || (!s1[i] && !s2[i]))
			return ((int)(unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
