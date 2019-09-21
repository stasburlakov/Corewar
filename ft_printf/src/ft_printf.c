/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 05:52:57 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/04/26 05:53:00 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		ft_null(t_form *form)
{
	form->width = 0;
	form->symb_width = 0;
	form->prec = -1;
	form->pos_width = 0;
	form->space_width = 0;
	form->hash_width = 0;
	form->plus_width = 0;
	form->mode_size = 0;
	form->c = 0;
	form->len = 0;
	form->minus = 0;
	form->caps = 0;
	form->digit = 0;
}

int			ft_log10(long double d)
{
	int	i;

	i = 0;
	d = ABS(d);
	while (d >= 10)
	{
		i++;
		d = d / 10;
	}
	return (i);
}

int			ft_parse(const char **format, va_list *ap, char c, int count)
{
	t_form	form;

	ft_null(&form);
	while (c)
	{
		if (c == 45 || c == 43 || c == 48 || c == ' ' || c == '#' || c == '\'')
			ft_width_numb(&form, c);
		else if (c < 58 && c > 47)
			form.width = ft_atoi_1(format);
		else if (c == '*')
		{
			form.width = va_arg(*ap, int);
			(!form.symb_width && form.width < 0) ? (((form.pos_width) = 1)
			&& (form.width *= -1)) : 0;
		}
		else if (c == '.')
			ft_prec(format, &form, ap);
		else if (c == 'l' || c == 'h' || c == 'z' || c == 'j' || c == 'L')
			form.mode_size += ft_mode_size(format);
		else
			return (ft_type(c, &form, ap, count));
		c = *(++(*format));
	}
	(*format)--;
	return (0);
}

int			ft_printf(const char *format, ...)
{
	int		start;
	int		count;
	va_list	ap;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		start = 0;
		if (*format == '%')
		{
			start = *(++format);
			count += ft_parse(&format, &ap, start, count);
			format++;
			continue ;
		}
		else
			while (format[start] && format[start] != '%')
				start++;
		count += write(1, format, start);
		format += start;
	}
	va_end(ap);
	return (count);
}
