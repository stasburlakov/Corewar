/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 04:53:37 by ljonnel-          #+#    #+#             */
/*   Updated: 2018/12/08 23:07:30 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*new_s;

	len = 0;
	while (s[len])
		len++;
	if ((new_s = (char*)malloc(sizeof(*new_s) * (len + 1))) == NULL)
		return (NULL);
	len = 0;
	if (new_s != NULL)
		while (s[len])
		{
			new_s[len] = s[len];
			len++;
		}
	new_s[len] = '\0';
	return (new_s);
}
