/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 16:55:18 by ljonnel-          #+#    #+#             */
/*   Updated: 2018/12/01 16:55:19 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*new_s;
	unsigned int		i;

	i = 0;
	if (!s)
		return (NULL);
	new_s = ft_strnew(ft_strlen(s));
	if (new_s == NULL)
		return (NULL);
	while (s[i])
	{
		new_s[i] = (*f)(i, s[i]);
		i++;
	}
	new_s[i] = 0;
	return (new_s);
}
