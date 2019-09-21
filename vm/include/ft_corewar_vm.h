/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_corewar_vm.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egottlie <egottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:42:29 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/26 15:05:27 by egottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COREWAR_VM_H
# define FT_COREWAR_VM_H
# include "ft_printf.h"
# include <fcntl.h>
# include "op.h"

# define MASK 0xff
# define ARG_SIZE 1
# define OP_SIZE 1

# include "SDL.h"
# include "SDL_ttf.h"
# include "SDL_image.h"

# define ERROR_MALLOC 1
# define ERROR_COUNT_CHAMP 2
# define ERROR_CHAMP_MAX_SIZE 3
# define ERROR_MAGIC_HEADER 4
# define ERROR_COMMENT_SIZE 5
# define ERROR_USAGE 6
# define ERROR_READ 7
# define ERROR_CHAMP_NAME_SIZE 8
# define ERROR_CHAMP_CHECK_SIZE 9

# define ERR_TEXTURE_TEXT "Failed to allocate memory for texture\n"
# define ERR_IMAGE_TEXT "Invalid file image\n"
# define ERR_SURFACE_TEXT "Failed to allocate memory for surface\n"
# define ERR_FONT_TEXT "Invalid file font\n"

typedef struct			s_op
{
	int					count_arg;
	int					size_t_dir;
	int					count_cicle;
	char				name_op[6];
	char				description[50];
}						t_op;

typedef struct			s_carriage
{
	int					current_position;
	int					carry;
	int					r[REG_NUMBER];
	int					cicle_last_live;
	int					ex_cod;
	int					count_wait_cicle;
	char				number_champ;
	struct s_carriage	*next;
}						t_carriage;

typedef struct			s_champ
{
	char				cut_name[15];
	int					number;
	char				*file_champ;
	char				name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
	char				ex_cod[CHAMP_MAX_SIZE + 1];
	int					size_champ;
	struct s_champ		*next;
}						t_champ;

typedef struct			s_vm
{
	char				*winner;
	int					count_flag;
	int					index_viz;
	int					flag_aff;
	int					dump;
	int					debug;
	int					show;
	int					cycle_to_die;
	int					count_cicle;
	int					count_champ;
	int					count_carriage;
	int					count_live_period;
	int					champ_said_a_live;
	int					max_check;
	int					live_in_period[4];
	int					count_cycle_in_period;
	int					last_live[4];
	char				*arena;
	char				player_arena[MEM_SIZE];
	t_op				*op;
	t_carriage			*carriage;
	t_champ				*champ;
}						t_vm;

typedef struct			s_sdl
{
	char				*tmp;
	SDL_Rect			rect_nbr;
	SDL_Rect			rect_running;
	SDL_Rect			rect_paused;
	SDL_Rect			rect_number_player;
	SDL_Rect			rect_live[2];
	SDL_Rect			rect_little_text;
	SDL_Rect			rect_info;
	SDL_Window			*win;
	SDL_Renderer		*ren;
	SDL_Color			color[12];
	SDL_Texture			*t_red;
	SDL_Texture			*t_green;
	SDL_Texture			*t_yellow;
	SDL_Texture			*t_black;
	SDL_Texture			*t_purple;
	SDL_Texture			*t_red_back;
	SDL_Texture			*t_purple_back;
	SDL_Texture			*t_green_back;
	SDL_Texture			*t_yellow_back;
	SDL_Texture			*t_black_back;
	SDL_Texture			*crown;
	SDL_Texture			*info;
	SDL_Texture			*text_live[2];
	SDL_Texture			*number_player[4];
	TTF_Font			*big_font;
	TTF_Font			*little_font;
	SDL_Texture			*text_pause;
	SDL_Texture			*text_play;
	int					viz_delay[7];
	int					i_delay;
	int					delay;
	SDL_Texture			*text_img[161];
	char				s[5][100];
}						t_sdl;

void					ft_run_carriages(t_vm *vm, int index);
void					ft_free_sdl(t_sdl *sdl, char *s, t_vm *vm);
void					cut_champ_name(t_vm *vm);
void					ft_naming_player(t_sdl *sdl, t_vm *vm);
void					ft_render_text(t_sdl *sdl, SDL_Rect *rect,
t_vm *vm, int color);

int						ft_event(t_sdl *sdl);
void					ft_event_quit(t_sdl *sdl, t_vm *vm);

void					ft_init_color(t_sdl *sdl);

void					ft_init_img(t_sdl *sdl, t_vm *vm);
void					ft_init_info(t_sdl *sdl, t_vm *vm);

void					ft_init_16_number(t_sdl *sdl, t_vm *vm);

t_sdl					*ft_sdl_init(t_vm *vm);

void					ft_viz_keyboard(t_sdl *sdl, t_vm *vm);
void					ft_viz_number(t_sdl *sdl, t_vm *vm);
void					ft_viz_icon(t_sdl *sdl, t_vm *vm);

void					ft_viz_winner(t_vm *vm, t_sdl *sdl);

void					ft_viz_player(t_sdl *sdl, t_vm *vm);
void					ft_viz_text(t_vm *vm, t_sdl *sdl);
void					ft_viz_live(t_sdl *sdl, t_vm *vm, int i);
int						ft_viz(t_vm *vm, t_sdl *sdl);
void					ft_flag_debug(t_vm *vm);
int						ft_is_number(char *str);
void					ft_error(t_vm *vm, int error, int i);
void					ft_init(t_vm *vm);
int						ft_check_magic_header(int fd);
void					ft_check_size_champ(t_vm *vm, int i, int fd);
void					ft_check_champ(t_vm *vm, int i, int fd);
void					ft_preparation_champ(int argc, char **argv, t_vm *vm);
void					ft_count_champ(int argc, char **argv, t_vm *vm);
void					ft_check_flag_and_champs_help(char **argv, t_vm *vm,
						int *i, int argc);
void					ft_create_carriage(t_vm *vm);
void					ft_init_arena(t_vm *vm);
void					ft_parse_champ(int argc, char **argv, t_vm *vm, int *s);
void					ft_check_flag_and_champs(int argc,
char **argv, t_vm *vm, int i);
void					ft_check_flag_and_champs_help_2(char **argv, t_vm *vm,
						int *i, int argc);
void					ft_intro_champs(t_vm *vm);
void					ft_parse_champ_flag_n(int argc,
char **argv, t_vm *vm, int *s);
void					ft_check_priority_flags(t_vm *vm);
int						ft_parse_champ_flag_n_help_1(int argc,
char **argv, t_vm *vm, int i);
void					ft_parse_champ_flag_n_help_2(char **argv, t_vm *vm,
int n, int i);
void					ft_parse_corewar(t_vm *vm);
int						ft_check_reg(t_vm *vm, t_carriage **carriage,
int *arg, int count);
void					ft_zjmp(t_vm *vm, t_carriage **carriage);
int						ft_check_number(t_vm *vm, int position, int byte);
int						ft_check_step(int size_t_dir,
unsigned char *cod_arg, int i);
int						ft_check_number_help(t_vm *vm, int position, int byte);
int						ft_st_help(t_vm *vm, t_carriage **carriage,
unsigned char *cod_arg, int *arg);
void					ft_st(t_vm *vm, t_carriage **carriage);
int						ft_st_op(t_vm *vm, t_carriage **carriage,
unsigned char *cod_arg, int *arg);
int						ft_check_dir_log(t_vm *vm, t_carriage **carriage,
int *arg, int count);
int						ft_is_number_help(char *str);
void					ft_create_op_1(t_vm *vm);
int						ft_check_ind_st(t_vm *vm,
t_carriage **carriage, int *arg, int count);
void					ft_sti(t_vm *vm, t_carriage **carriage);
int						ft_check_ind_log(t_vm *vm, t_carriage **carriage,
int *arg, int count);
int						ft_log_op(t_vm *vm, t_carriage **carriage,
unsigned char *cod_arg, int *arg);
void					ft_log_help(unsigned char *cad_arg, int *arg,
t_carriage **carriage);
void					ft_log(t_vm *vm, t_carriage **carriage);
void					ft_live(t_vm *vm, t_carriage **carriage);
void					ft_ldi_lldi(t_vm *vm, t_carriage **carriage);
int						ft_ldi_help(t_vm *vm, t_carriage **carriage,
unsigned char *cod_arg, int *arg);
int						ft_check_ind_lld(t_vm *vm, t_carriage **carriage,
int *arg, int count);
int						ft_lld_op(t_vm *vm, t_carriage **carriage,
unsigned char *cod_arg, int *arg);
void					ft_lld_help(unsigned char *cad_arg, int *arg,
t_carriage **carriage);
void					ft_ld_lld(t_vm *vm, t_carriage **carriage);
void					ft_fork_lfork(t_vm *vm, t_carriage **carriage);
void					ft_aff(t_vm *vm, t_carriage **carriage);
void					ft_add_sub(t_vm *vm, t_carriage **carriage);
int						ft_add_help(t_carriage **carriage, int *arg, int count);

void					ft_fight_champ(t_vm *vm, t_sdl *sdl);
void					ft_help(void);
void					ft_op(t_vm *vm, t_carriage **carriage);
void					ft_check_arg(t_vm *vm,
t_carriage **carriage, unsigned char *cod_arg, int *arg);
void					ft_rewrite(t_vm *vm, int position, int number);
void					ft_win_champ(t_vm *vm);
void					ft_change_cicle_to_die(t_vm *vm);
void					ft_free_vm(t_vm *vm);
void					ft_kill_carriage(t_vm *vm);

#endif
