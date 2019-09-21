/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:48:53 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/05/06 12:48:55 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*new_s;

	if ((new_s = (char*)malloc(sizeof(*new_s) * (n + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
