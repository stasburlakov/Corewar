/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:24:09 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/05/10 14:24:10 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			char_len(wchar_t c)
{
	int len;

	if (c <= 0)
		return (0);
	else if (c <= 127)
		len = 1;
	else if (c >= 127 && c <= 2047)
		len = 2;
	else if (c >= 2048 && c <= 65535)
		len = 3;
	else
		len = 4;
	return (len);
}

int			ft_type_c(t_form *form, va_list *ap, int mode)
{
	wint_t	d;
	wchar_t	*wstr;
	int		count;

	if (mode)
		d = (wchar_t)va_arg(*ap, wint_t);
	else
		d = (char)va_arg(*ap, unsigned int);
	wstr = (wchar_t*)ft_memalloc(sizeof(*wstr) * 2);
	(!d) ? form->c = 1 : 0;
	*wstr = d;
	count = ft_parse_on_ws(form, wstr);
	free(wstr);
	return (count);
}

int			ft_preparation(t_form *form, char *str, char c)
{
	int mode;

	form->hash_width *= (c == 'o') ? 1 : 2;
	form->len = ft_strlen(str);
	if (str && !ft_strcmp(str, "0"))
	{
		(form->prec >= 0 && form->hash_width != 1) ? form->len = 0 : 0;
		(c != 'p') ? form->hash_width = 0 : 0;
	}
	(form->prec >= 0 && c != 's') ? (form->symb_width = 0) : 0;
	if (str && str[0] == '-')
	{
		form->minus = 1;
		form->plus_width = 0;
		form->space_width = 0;
		form->width--;
		form->len--;
	}
	mode = ft_print_on_spec_test(str, form);
	(str) ? free(str) : 0;
	return (mode);
}

char		*ft_type_middle(char c, t_form *form, int coun, va_list *ap)
{
	unsigned long long	*n;
	char				*str;

	if (c == 'p')
		(form->mode_size += 1) && (form->hash_width = 1);
	if (c == 'X' || c == 'u' || c == 'x' || c == 'o' || c == 'p')
		str = ft_str_xou(form, ap, form->mode_size, c);
	else if (c == 'n')
	{
		n = va_arg(*ap, unsigned long long*);
		*n = coun;
		return (0);
	}
	else if (c == 'f')
		return (ft_float(form, ap));
	else
	{
		str = ft_strnew(1);
		*str = c;
		form->hash_width = 0;
		form->prec = -1;
	}
	return (str);
}

int			ft_type(char c, t_form *form, va_list *ap, int coun)
{
	wchar_t				*wstr;

	if (c == 'D' || c == 'O' || c == 'S' || c == 'C' || c == 'U' || c == 'F')
		(form->mode_size = 1) && (c += 32);
	if (c == 'd' || c == 'i')
		wstr = (wchar_t*)ft_str_id(form, ap, form->mode_size);
	else
	{
		(c != 'u' && c != 'f') ? (form->digit = 0) : 0;
		form->space_width = 0;
		form->plus_width = 0;
		if (c == 's')
			if (form->mode_size)
			{
				wstr = ft_str_ws(form, ap);
				return (ft_parse_on_ws(form, wstr));
			}
			else
				wstr = (wchar_t*)ft_str_s(&(form->prec), ap);
		else if (c == 'c')
			return (ft_type_c(form, ap, form->mode_size));
		else
			wstr = (wchar_t*)ft_type_middle(c, form, coun, ap);
	}
	return (ft_preparation(form, (char*)wstr, c));
}
