/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:19:07 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/05/10 14:19:13 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		*rounding_rounding(char *s)
{
	int		len;
	char	*s2;
	int		tmp;

	tmp = 0;
	len = ft_strlen(s);
	s2 = ft_strnew(len + 1);
	if (s[0] == '-')
	{
		*(s2++) = '-';
		s++;
		tmp++;
	}
	*(s2++) = '1';
	s2 = ft_strcpy(s2, s);
	s2--;
	s2 -= tmp;
	return (s2);
}

char		*rounding_other(char *s, int k)
{
	char	*c;

	while (1)
	{
		if (s[k] == '9')
		{
			s[k--] = '0';
			if (k == -1)
			{
				c = rounding_rounding(s);
				free(s);
				return (c);
			}
		}
		else if (s[k] == '.')
			k--;
		else
		{
			s[k] += 1;
			break ;
		}
	}
	return (s);
}

char		*rounding(char *s, long double d, int precision, int k)
{
	int	value;

	value = (int)(d * 100) % 100;
	s[k] = '0' + (int)d;
	if (precision == 0 && value == 50)
	{
		((s[k] - '0') % 2) ? s[k] += 1 : 0;
		while (s[k] == ':')
		{
			s[k--] = '0';
			s[k] += 1;
		}
	}
	else if (value >= 50)
		s = rounding_other(s, k);
	return (s);
}

int			floors(long double n)
{
	n = n + 0.000000000000001;
	return (n - ((int)n % 1));
}

long double	pow_10(int pos)
{
	long double base;

	base = 1;
	while (pos-- > 0)
		base *= 10;
	return (base);
}
