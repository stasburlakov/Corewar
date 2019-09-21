/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 04:54:37 by ljonnel-          #+#    #+#             */
/*   Updated: 2018/11/28 04:54:38 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*i;

	i = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			i = (char*)s;
		s++;
	}
	if (*s == (char)c)
		return ((char*)s);
	else
		return (i);
}
