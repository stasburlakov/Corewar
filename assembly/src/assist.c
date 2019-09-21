/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:50:27 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/23 21:50:47 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	skip_number(const char *s)
{
	int	i;

	i = 0;
	if (*s == '-')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	return (i);
}

int	skip_alph(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != ' ' && s[i] != '\t')
		i++;
	return (i);
}

int	skip_space(const char *s)
{
	int i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	return (i);
}

int	is_label_chars(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9') || c == '_')
		return (1);
	return (0);
}

int	ft_lenstr_to_space(char *s)
{
	int i;

	i = 0;
	while (is_label_chars(s[i]))
		i++;
	return (i);
}
