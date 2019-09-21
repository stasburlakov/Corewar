/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 08:43:35 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/09 20:40:39 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ASM_H
# define FT_ASM_H
# include <fcntl.h>
# include "ft_printf.h"
# include "op.h"
# define DIR_NUMBER		5
# define INDIR_NUMBER	6
# define REGISTR		7
# define DIR_LABEL		8
# define INDIR_LABEL	9
# define LABEL			10
# define INSTRUCTION	11
# define ERR1			"Enter the .s file"
# define ERR2			"Can't read source file "
# define ERR3			"Lexical error at "
# define ERR4			"Syntax error at token [TOKEN]"
# define ERR5			"Champion "
# define ERR6			"Invalid parameter count for instruction "
# define ERR8			"Invalid instruction at token [TOKEN]"
# define ERR9			"Invalid parameter type for instruction "
# define ERR10			"comment too long (Max length "

typedef struct			s_list_lex
{
	int					type;
	int					size;
	int					count;
	int					number;
	char				*label;
	struct s_list_lex	*next;
}						t_list_lex;

typedef struct			s_data
{
	int					type;
	int					numb_symb;
	int					fd_cor;
	t_list_lex			*t_last;
	t_list_lex			*t_first;
	char				*line;
	char				*name;
	char				*comment;
	char				*code;
	char				*fl;
	int					size_code;
	int					i;
	int					n_len;
	int					fd_s;
	char				*tmp;
}						t_data;

typedef struct			s_carriage
{
	int					current_position;
	int					number_carriage;
	int					carry;
	int					r[REG_NUMBER + 1];
	int					cicle_last_live;
	int					step;
	int					ex_cod;
	int					count_wait_cicle;
	struct s_carriage	*next;
}						t_carriage;

typedef struct			s_champ
{
	int					number;
	char				*file_champ;
	char				name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
	unsigned char		ex_cod[CHAMP_MAX_SIZE + 1];
	int					size_champ;
	struct s_champ		*next;
}						t_champ;

typedef struct			s_vm
{
	int					visu;
	int					cycle_to_die;
	int					count_cicle;
	int					dump;
	int					count_champ;
	int					count_carriage;
	int					count_live_period;
	int					champ_said_a_live;
	int					count_check;
	unsigned char		*arena;
	t_carriage			*carriage;
	t_champ				*champ;
}						t_vm;

int						skip_number(const char *s);
int						skip_alph(char *s);
int						skip_space(const char *s);
int						ft_lenstr_to_space(char *s);
int						is_label_chars(char c);
void					ft_calc_type_instr2(int size[2], int code,
		t_list_lex *head, t_list_lex *list);
void					ft_calc_type_instr(t_list_lex *list, int instr);
int						ft_search_label(t_data *data,
		t_list_lex *curr_label, int addr);
void					ft_calc_all_label(t_data *data);
void					ft_calc_all_instr(t_data *data);

int						ft_exit(t_data *data, int i, char *s, int ch);
void					ft_exit2(t_data *data, int i, char *lab, int ch);
void					ft_exit3(int ch, int i, char *lab, t_data *data);

int						is_true_instr(char *line, int n);
void					start_asm(t_data *data);
void					ex_code_asm(t_data *data);
void					ft_translate_asm(char *s, t_data *data, int n, int i);
int						main(int ac, char **av);

void					ft_write_token(t_data *data,
		int number, int start, int len);
void					ft_add_byte(t_data *data, int32_t byte, int size);

int						ft_init_logic(t_data *data, int i, char *s);
int						ft_init_ld_lld(t_data *data, int i, char *s);
int						ft_init_three_reg(t_data *data, int i, char *s);
int						ft_init_st(t_data *data, int i);
int						ft_init_sti(t_data *data, int i);

int						ft_init_dir(t_data *data, int i, char *s);
int						ft_init_reg(t_data *data, int i, char *s);
int						ft_init_ind(t_data *data, int i, char *s);
int						ft_init_dir_reg(t_data *data, int i, char *s);
void					ft_init_instruct(int instr, t_data *data, int i);

char					*name_or_comm_asm(t_data *data, int index, int i);
int						name_or_coom_asm2(char *name,
		int index, t_data *data, int len);
char					*new_name_file(char *src);

void					tokenization(t_data *data);
int						ft_new_alph_token(t_data *data, int i);

#endif
