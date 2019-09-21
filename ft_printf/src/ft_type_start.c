/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:23:08 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/05/10 14:23:09 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_print_on_ws(t_form *form, int len, int a, wchar_t *tmp)
{
	int	j;

	j = -1;
	if (form->pos_width)
	{
		while (tmp[++j] || form->c-- > 0)
			len += ft_str_wc(tmp[j]);
		while (a-- > 0)
			write(1, " ", 1);
	}
	else
	{
		if (form->symb_width)
			while (a-- > 0)
				write(1, "0", 1);
		else
			while (a-- > 0)
				write(1, " ", 1);
		while (tmp[++j] || form->c-- > 0)
			len += ft_str_wc(tmp[j]);
	}
	return (len);
}

int			ft_parse_on_ws(t_form *form, wchar_t *tmp)
{
	int		a;
	int		len;
	int		j;

	len = form->len;
	j = 0;
	if (form->prec < 0)
		while (tmp[j])
			len += char_len(tmp[j++]);
	a = ft_abs(form->width - len - form->c);
	len = a;
	return (ft_print_on_ws(form, len, a, tmp));
}

char		*ft_str_id(t_form *form, va_list *ap, int mode)
{
	int64_t	res;
	char	*str;

	if (mode == 0)
		res = va_arg(*ap, int);
	else if (mode == 1)
		res = va_arg(*ap, long long);
	else if (mode == 2)
		res = va_arg(*ap, long);
	else if (mode == 3)
		res = (signed char)va_arg(*ap, int);
	else if (mode == 4)
		res = (short)va_arg(*ap, int);
	else if (mode == 5)
		res = va_arg(*ap, ssize_t);
	else
		res = va_arg(*ap, intmax_t);
	str = ft_lltoa(res);
	if (form->plus_width)
		form->space_width = 0;
	form->hash_width = 0;
	(form->digit) ? (form->digit = ft_count_digit((intmax_t)res)) : 0;
	return (str);
}

wchar_t		*wstrndup(const wchar_t *s1, int *n)
{
	wchar_t	*s2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(s2 = (wchar_t *)malloc(sizeof(wchar_t) * (*n + 1))))
		return (NULL);
	while (s1[j])
	{
		i += char_len(s1[j]);
		if (i <= *n)
			s2[j] = s1[j];
		else
			break ;
		j++;
	}
	*n = ft_abs(i - char_len(s1[j]));
	s2[j] = '\0';
	return (s2);
}

wchar_t		*wstrdup(wchar_t *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (wstrndup(str, &len));
}
