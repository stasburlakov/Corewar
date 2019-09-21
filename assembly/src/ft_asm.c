/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:57:35 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/02 21:57:36 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

char	*g_op[17] = {"live", "ld", "st", "add", "sub", "and", "or", "xor",
	"zjmp", "ldi", "sti", "fork", "lld", "lldi", "lfork", "aff"};

int		is_true_instr(char *line, int n)
{
	int i;

	i = -1;
	while (++i < 16)
	{
		if (!ft_strncmp(line, g_op[i], n) &&
		line[ft_strlen(g_op[i])] != LABEL_CHAR)
			return (i);
	}
	return (-1);
}

void	start_asm(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j++ < 2)
	{
		data->n_len++;
		if (get_next_line(data->fd_s, &data->line) <= 0)
			ft_exit(data, 1, ERR4, -1);
		i = skip_space(data->line);
		if (!ft_strncmp(data->line + i, NAME_CMD_STRING,
				ft_strlen(NAME_CMD_STRING)) && data->name == NULL)
			data->name = name_or_comm_asm(data, 1,
					i + ft_strlen(NAME_CMD_STRING));
		else if (!ft_strncmp(data->line + i, COMMENT_CMD_STRING,
				ft_strlen(COMMENT_CMD_STRING)) && data->comment == NULL)
			data->comment = name_or_comm_asm(data, 2,
					i + ft_strlen(COMMENT_CMD_STRING));
		else
			((data->line[i] && data->line[i] != COMMENT_CHAR) &&
			(data->line[i] && data->line[i] != ALT_COMMENT)) ?
			ft_exit(data, i + 1, data->line + i, -10) : (j -= 1);
		free(data->line);
	}
}

void	ex_code_asm(t_data *data)
{
	tokenization(data);
	ft_calc_all_instr(data);
	data->code = (char*)malloc(sizeof(char) * data->size_code + 1);
	ft_calc_all_label(data);
}

void	ft_translate_asm(char *s, t_data *data, int n, int i)
{
	data->fd_s = open(s, O_RDONLY);
	if (data->fd_s > 0)
	{
		((data->fl = new_name_file(s)) == NULL) ?
		ft_exit(data, -1, ERR1, -1) : 0;
		start_asm(data);
		ex_code_asm(data);
		data->fd_cor = open(data->fl, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
		while (--i >= 0)
			write(data->fd_cor, (char*)&n + i, 1);
		write(data->fd_cor, data->name, PROG_NAME_LENGTH);
		i = 0;
		write(data->fd_cor, &i, 4);
		i = sizeof(int);
		while (--i >= 0)
			write(data->fd_cor, (char*)&data->size_code + i, 1);
		write(data->fd_cor, data->comment, COMMENT_LENGTH);
		i = 0;
		write(data->fd_cor, &i, 4);
		write(data->fd_cor, data->code, data->size_code);
		ft_putstr("Writing output program to ");
		ft_putendl(data->fl);
	}
	else
		ft_exit(data, 1, ERR2, -4);
}

int		main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2)
	{
		data = (t_data *)malloc(sizeof(t_data));
		data->tmp = av[1];
		data->t_last = NULL;
		data->t_first = NULL;
		data->comment = NULL;
		data->name = NULL;
		data->fl = NULL;
		data->n_len = 0;
		data->code = NULL;
		data->i = 0;
		data->size_code = 0;
		ft_translate_asm(av[1], data, COREWAR_EXEC_MAGIC, sizeof(int));
		ft_exit(data, 0, 0, -12);
	}
	else
		ft_putendl("Usage: \n\t./asm <sourcefile.s>");
	return (0);
}
