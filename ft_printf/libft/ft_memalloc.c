/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:37:42 by ljonnel-          #+#    #+#             */
/*   Updated: 2018/12/01 15:37:43 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*buffer;

	if ((buffer = (void*)malloc(size)) == NULL)
		return (NULL);
	ft_bzero(buffer, size);
	return (buffer);
}
