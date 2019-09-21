/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 16:43:25 by ljonnel-          #+#    #+#             */
/*   Updated: 2018/12/08 23:13:41 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_s;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	new_s = ft_strnew(ft_strlen(s));
	if (new_s == NULL)
		return (NULL);
	while (s[i])
	{
		new_s[i] = (char)((*f)(s[i]));
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
