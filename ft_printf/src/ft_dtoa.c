/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:19:57 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/05/10 14:19:58 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		*ft_create_str_dop(int digit, int len, char *str, char *s)
{
	while (digit-- > 0)
	{
		s[len - 1] = *str;
		s[len - 2] = *(str - 1);
		s[len - 3] = *(str - 2);
		s[len - 4] = ',';
		len -= 4;
		str -= 3;
	}
	while (len > 0)
	{
		s[len - 1] = *str;
		len--;
		str--;
	}
	return (s);
}

char		*ft_create_str_digit(char *str, int digit, int len)
{
	char	*s;
	int		len2;
	char	*s2;

	len = 0;
	len2 = 0;
	s = ft_strnew(len + digit);
	while (str[len] && str[len] != '.')
		len++;
	while (*str && *str != '.')
		str++;
	while (str[len2])
		s[len + len2++] = *str;
	s2 = str;
	str--;
	len += digit;
	len2 = len;
	s = ft_create_str_dop(digit, len, str, s);
	while (*s2)
	{
		s[len2] = *s2;
		s2++;
		len2++;
	}
	return (s);
}

char		*dtoa_other(long double d)
{
	char	*s;

	if (d != d)
		s = ft_strdup("nan");
	else if ((d * 0.0) != (d * 0.0) && (d > 0))
		s = ft_strdup("inf");
	else if ((d * 0.0) != (d * 0.0) && (d < 0))
		s = ft_strdup("-inf");
	else
		s = NULL;
	return (s);
}

char		*dtoa(long double d, int precision, int k)
{
	int		digit;
	char	*s;
	double	weight;
	int		i;

	if ((s = dtoa_other(d)) != NULL)
		return (s);
	i = ft_log10(d);
	s = ft_strnew(i + precision + 3);
	(d < 0) ? ((d *= -1) && (s[k++] = '-')) : 0;
	weight = pow_10(i);
	i += precision + 1;
	while (--i > 0)
	{
		digit = floors(d / weight);
		d -= (weight * digit);
		s[k++] = '0' + digit;
		if (i == precision && d <= 1.0 && d >= 0)
			s[k++] = '.';
		weight /= 10;
	}
	s = rounding(s, d / weight, precision, k);
	return (s);
}

char		*ft_float(t_form *form, va_list *ap)
{
	long double	d;

	(form->prec == -1) ? (form->prec = 6) : 0;
	if (form->mode_size == 7)
		d = va_arg(*ap, long double);
	else
		d = va_arg(*ap, double);
	(form->digit) ? (form->digit = ft_count_digit(d)) : 0;
	return (dtoa(d, form->prec, 0));
}
