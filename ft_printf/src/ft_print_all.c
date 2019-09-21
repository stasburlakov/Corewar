/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:22:15 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/05/10 14:22:17 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		ft_strcapitalize(char **str)
{
	char	c;
	int		i;

	i = 0;
	c = **str;
	while (c)
	{
		if (c <= 122 && c >= 97)
			(*str)[i] -= 32;
		i++;
		c = (*str)[i];
	}
	return ('X');
}

int			ft_count_digit(long double res)
{
	int count;

	res = ABS(res);
	count = 0;
	while (1)
	{
		res = res / 1000;
		if (res > 1)
			count++;
		else
			break ;
	}
	return (count);
}

void		ft_print_pos(t_form *form, char *format, int a, const char *c)
{
	int		prec;
	char	*str;

	prec = form->prec;
	(form->plus_width) ? write(1, "+", 1) : 0;
	(form->space_width) ? write(1, " ", 1) : 0;
	(form->hash_width) ? write(1, c, form->hash_width) : 0;
	(form->c) ? write(1, &(form->c), 1) : 0;
	format += (form->minus) ? write(1, "-", 1) : 0;
	while (prec-- > 0)
		write(1, "0", 1);
	if (!form->digit)
		(form->len) ? write(1, format, form->len) : 0;
	else
	{
		str = ft_create_str_digit(format, form->digit, form->len);
		(form->len) ? write(1, str, form->len + form->digit) : 0;
		free(str);
	}
	while (a-- > 0)
		write(1, " ", 1);
}

void		ft_print_symb(t_form *form, char *format, int a, const char *c)
{
	int		prec;
	char	*str;

	prec = form->prec;
	(form->plus_width) ? write(1, "+", 1) : 0;
	(form->space_width) ? write(1, " ", 1) : 0;
	(form->hash_width) ? write(1, c, form->hash_width) : 0;
	(form->c) ? write(1, &(form->c), 1) : 0;
	format += (form->minus) ? write(1, "-", 1) : 0;
	while (a-- > 0)
		write(1, "0", 1);
	while (prec-- > 0)
		write(1, "0", 1);
	if (!form->digit)
		(form->len) ? write(1, format, form->len) : 0;
	else
	{
		str = ft_create_str_digit(format, form->digit, form->len);
		(form->len) ? write(1, str, form->len + form->digit) : 0;
		free(str);
	}
}

void		ft_print_oth(t_form *form, char *format, int a, const char *c)
{
	int		prec;
	char	*str;

	prec = form->prec;
	while (a-- > 0)
		write(1, " ", 1);
	(form->plus_width) ? write(1, "+", 1) : 0;
	(form->space_width) ? write(1, " ", 1) : 0;
	(form->hash_width) ? write(1, c, form->hash_width) : 0;
	if (form->c)
		write(1, &(form->c), 1);
	else
	{
		format += (form->minus) ? write(1, "-", 1) : 0;
		while (prec-- > 0)
			write(1, "0", 1);
		if (!form->digit)
			(form->len) ? write(1, format, form->len) : 0;
		else
		{
			str = ft_create_str_digit(format, form->digit, form->len);
			(form->len) ? write(1, str, form->len + form->digit) : 0;
			free(str);
		}
	}
}
