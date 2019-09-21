/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:48:52 by ljonnel-          #+#    #+#             */
/*   Updated: 2018/12/08 22:51:54 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_w(char const *str, char c)
{
	int i;
	int numb;

	i = 1;
	if (str[0] == c)
		numb = 0;
	else
		numb = 1;
	while (str[i])
	{
		if (str[i] != c && str[i - 1] == c)
			numb++;
		i++;
	}
	return (numb);
}

static char		**ft_dop_func(int j, char **nr)
{
	if ((nr[j] = (char*)malloc(sizeof(char))) == NULL)
		return (NULL);
	nr[j] = NULL;
	return (nr);
}

static int		ft_free_odd(char **nr, int tmp, int j)
{
	if ((nr[j] = (char*)malloc(sizeof(char) * (tmp + 1))) == NULL)
	{
		while (j >= 0)
		{
			free(nr[j]);
			j--;
		}
		free(nr);
		return (1);
	}
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	char	buf[1024];
	int		j;
	int		tmp;
	char	**nr;

	j = 0;
	if (!s || (nr = (char**)malloc(sizeof(char*) * (ft_w(s, c) + 1))) == NULL)
		return (NULL);
	while (*s)
	{
		tmp = 0;
		while (*s != c && *s != '\0')
			buf[tmp++] = *(s++);
		buf[tmp] = '\0';
		if (tmp != 0)
		{
			if (ft_free_odd(nr, tmp, j) == 1)
				return (NULL);
			ft_strcpy(nr[j++], buf);
		}
		if (*s)
			s++;
	}
	return (ft_dop_func(j, nr));
}
