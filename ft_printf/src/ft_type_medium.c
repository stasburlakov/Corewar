/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:26:39 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/05/10 14:26:40 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_dop_wc(wint_t d, unsigned char **s)
{
	if (d <= 0xFFFF && d > 0x7FF)
	{
		(*s)[0] = (d >> 12) + 224;
		(*s)[1] = ((d >> 6) & 63) + 128;
		(*s)[2] = (d & 63) + 128;
		return (3);
	}
	else
	{
		(*s)[0] = (d >> 18) + 240;
		(*s)[1] = ((d >> 12) & 63) + 128;
		(*s)[2] = ((d >> 6) & 63) + 128;
		(*s)[3] = (d & 63) + 128;
		return (4);
	}
}

int			ft_str_wc(wint_t d)
{
	int				len;
	unsigned char	*s;

	s = (unsigned char*)malloc((sizeof(*s) * 5));
	if (d <= 0x7F)
	{
		s[0] = d;
		len = 1;
	}
	else if (d <= 0x7FF && d > 0x7F)
	{
		s[0] = (d >> 6) + 192;
		s[1] = (d & 63) + 128;
		len = 2;
	}
	else
		len = ft_dop_wc(d, &s);
	write(1, s, len);
	free(s);
	return (len);
}

char		*ft_str_s(int *prec, va_list *ap)
{
	char	*str;

	str = va_arg(*ap, char*);
	if (*prec >= 0)
	{
		if (str)
			str = ft_strndup(str, *prec);
		else
			str = ft_strndup("(null)", *prec);
		*prec = 0;
	}
	else
		str = (!str) ? (ft_strdup("(null)")) : ft_strdup(str);
	return (str);
}

wchar_t		*ft_str_ws(t_form *form, va_list *ap)
{
	wchar_t	*str;

	str = (wchar_t *)va_arg(*ap, wchar_t *);
	if (form->prec >= 0)
	{
		if (!str)
			str = wstrndup(L"(null)", &(form->prec));
		else
			str = wstrndup(str, &(form->prec));
		form->len = form->prec;
		form->prec = 0;
	}
	else if (!str)
	{
		str = wstrdup(L"(null)");
		form->prec = 0;
	}
	return (str);
}

char		*ft_str_xou(t_form *form, va_list *ap, int mode, char c)
{
	uintmax_t	res;

	if (mode == 0)
		res = va_arg(*ap, unsigned int);
	else if (mode == 1)
		res = va_arg(*ap, unsigned long long);
	else if (mode == 2)
		res = va_arg(*ap, unsigned long);
	else if (mode == 3)
		res = (unsigned char)va_arg(*ap, unsigned int);
	else if (mode == 4)
		res = (unsigned short)va_arg(*ap, unsigned int);
	else if (mode == 5)
		res = va_arg(*ap, size_t);
	else
		res = va_arg(*ap, uintmax_t);
	if (c == 'X' || c == 'x' || c == 'p')
	{
		(c == 'X') ? (form->caps = 1) : 0;
		return (ft_ulltoa_base(res, 16));
	}
	(form->digit && c == 'u') ? (form->digit = ft_count_digit(res)) : 0;
	return ((c == 'o') ? (ft_ulltoa_base(res, 8)) : (ft_ulltoa_base(res, 10)));
}
