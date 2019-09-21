/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 16:01:56 by ljonnel-          #+#    #+#             */
/*   Updated: 2018/12/01 16:01:57 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (size + 1 <= 0)
		return (NULL);
	if ((str = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	ft_memset(str, 0, size + 1);
	return (str);
}
