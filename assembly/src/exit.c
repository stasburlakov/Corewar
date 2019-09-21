/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:50:59 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/23 21:51:00 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

void	ft_exit3(int ch, int i, char *lab, t_data *data)
{
	if (ch == -2)
		ft_printf("%s[%.3i:%.3i]\n", lab, data->n_len, i);
	else if (ch == -3)
		(i == PROG_NAME_LENGTH) ? ft_printf("name too long (Max length %i)\n",
											PROG_NAME_LENGTH) :
		ft_printf("%s%i)\n", ERR10, COMMENT_LENGTH);
	else if (i >= 0 && ch == -1)
		ft_printf("%s[%.3i:%.3i] END \"%s\"\n", lab, data->n_len, i, NULL);
	else if (ch == -1)
		ft_printf("%s\n", lab);
}

void	ft_exit2(t_data *data, int i, char *lab, int ch)
{
	(ch == -10 || ch == -2 || ch == -8 || ch == -6 || ch == -9) ?
	free(data->line) : 0;
	if (ch == -11)
		ft_putendl("Syntax error - unexpected end of input (Perhaps you\
	forgot to end with a newline ?)");
	else if (ch == -9)
		ft_printf("%s\"%s\" [len=%.3i]\n", ERR9, lab, data->n_len);
	else if (ch == -8 || ch == -10)
		ft_printf("%s[%.3i:%.3i] INSTRUCTION \"%.*s\"\n", ERR4, data->n_len, i,
				skip_alph(lab), lab);
	else if (ch == -7)
		ft_printf("%s%s\n", ERR6, lab);
	else if (ch == -4)
		ft_printf("%s%s\n", lab, data->tmp);
	else if (ch == -6)
		ft_printf("%s[%.3i:%.3i] INSTRUCTION \"%s\"\n", ERR8, data->n_len,
				i, lab);
	else if (ch == -5)
		ft_printf("%s[%.3i:%.3i] LABEL \"%s\"", "No such label loo while \
attempting to dereference token [TOKEN]", data->n_len, i, lab);
	else
		ft_exit3(ch, i, lab, data);
}

int		ft_exit(t_data *data, int i, char *s, int ch)
{
	t_list_lex	*tmp;
	char		lab[1280];

	(s != NULL) ? ft_strcpy(lab, s) : 0;
	(ch >= 0) ? free(data->line) : 0;
	free(data->name);
	free(data->comment);
	free(data->fl);
	free(data->code);
	while (data->t_first)
	{
		tmp = data->t_first;
		if (data->t_first->label)
			free(data->t_first->label);
		data->t_first = data->t_first->next;
		free(tmp);
	}
	ft_exit2(data, i, s, ch);
	free(data);
	exit(0);
}
