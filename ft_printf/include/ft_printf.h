/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 23:18:52 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/04/27 23:18:53 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define ABS(a) ((a > 0) ? (a) : (-a))
# include <stdarg.h>
# include <wchar.h>
# include "../libft/libft.h"

typedef struct	s_form
{
	int			width;
	char		symb_width;
	int			prec;
	char		pos_width;
	char		space_width;
	int			hash_width;
	char		plus_width;
	int			mode_size;
	int			caps;
	char		c;
	int			len;
	int			minus;
	int			digit;
}				t_form;

int				ft_printf(const char *format, ...);
char			*ft_create_str_dop(int digit, int len, char *str, char *s);
char			*ft_create_str_digit(char *str, int digit, int len);
char			*dtoa_other(long double d);
char			*dtoa(long double d, int precision, int k);
char			*ft_float(t_form *form, va_list *ap);
int				ft_log10(long double d);
char			*rounding_other(char *s, int k);
char			*rounding(char *s, long double d, int precision, int k);
int				floors(long double n);
long double		pow_10(int pos);
int				ft_print_on_spec_test(char *format, t_form *form);
void			ft_width_numb(t_form *form, char c);
int				ft_atoi_1(const char **nptr);
int				ft_mode_size(const char **format);
void			ft_prec(const char **format, t_form *form, va_list *ap);
char			ft_strcapitalize(char **str);
int				ft_count_digit(long double res);
void			ft_print_pos(t_form *form, char *format, int a, const char *c);
void			ft_print_symb(t_form *form, char *format, int a, const char *c);
void			ft_print_oth(t_form *form, char *format, int a, const char *c);
int				char_len(wchar_t c);
int				ft_type_c(t_form *form, va_list *ap, int mode);
int				ft_preparation(t_form *form, char *str, char c);
char			*ft_type_middle(char c, t_form *form, int coun, va_list *ap);
int				ft_type(char c, t_form *form, va_list *ap, int coun);
int				ft_dop_wc(wint_t d, unsigned char **s);
int				ft_str_wc(wint_t d);
char			*ft_str_s(int *prec, va_list *ap);
wchar_t			*ft_str_ws(t_form *form, va_list *ap);
char			*ft_str_xou(t_form *form, va_list *ap, int mode, char c);
int				ft_print_on_ws(t_form *form, int len, int a, wchar_t *tmp);
int				ft_parse_on_ws(t_form *form, wchar_t *tmp);
char			*ft_str_id(t_form *form, va_list *ap, int mode);
wchar_t			*wstrndup(const wchar_t *s1, int *n);
wchar_t			*wstrdup(wchar_t *str);

#endif
