/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:24:57 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/05/10 14:24:58 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		ft_prec(const char **format, t_form *form, va_list *ap)
{
	int		k;
	char	c;

	k = 0;
	c = *++(*format);
	if (c == '*')
	{
		form->prec = va_arg(*ap, int);
		(*format)++;
	}
	else
	{
		while (c < 58 && c > 47)
		{
			k *= 10;
			k += c - '0';
			(*format)++;
			c = **format;
		}
		form->prec = k;
	}
	(*format)--;
}

int			ft_mode_size(const char **format)
{
	char	c;

	c = **format;
	if (c == 'l')
		if (*(*format + 1) == 'l')
		{
			(*format)++;
			return (1);
		}
		else
			return (2);
	else if (c == 'h')
	{
		if (*(*format + 1) == 'h')
		{
			(*format)++;
			return (3);
		}
		else
			return (4);
	}
	else if (c == 'z')
		return (5);
	return ((c == 'j') ? 6 : 7);
}

int			ft_atoi_1(const char **nptr)
{
	int value;

	value = 0;
	while (**nptr >= '0' && **nptr <= '9')
	{
		value = value * 10 + **nptr - 48;
		(*nptr)++;
	}
	(*nptr)--;
	return (value);
}

void		ft_width_numb(t_form *form, char c)
{
	if (c == '-')
		form->pos_width = 1;
	else if (c == '+')
		form->plus_width = 1;
	else if (c == '0' && form->width == 0)
		form->symb_width = 1;
	else if (c == ' ')
		form->space_width = 1;
	else if (c == '#')
		form->hash_width = 1;
	else
		form->digit = 1;
}

int			ft_print_on_spec_test(char *format, t_form *form)
{
	int		abslen;
	char	c[2];
	int		symb;

	c[0] = '0';
	c[1] = (form->caps == 1) ? ft_strcapitalize(&format) : 'x';
	form->prec = ft_abs(form->prec - form->len - form->digit);
	(form->prec > 0 && form->hash_width == 1) ? form->hash_width-- : 0;
	symb = form->space_width + form->plus_width + form->hash_width;
	abslen = ft_abs(form->width - form->len - symb - form->prec - form->digit);
	if (form->pos_width)
		ft_print_pos(form, format, abslen, c);
	else if (form->symb_width)
		ft_print_symb(form, format, abslen, c);
	else
		ft_print_oth(form, format, abslen, c);
	return (form->prec + symb + abslen + form->len + form->minus);
}
