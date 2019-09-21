# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egottlie <egottlie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/27 16:59:07 by egottlie          #+#    #+#              #
#    Updated: 2019/07/26 16:43:11 by egottlie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_COREWAR = corewar
NAME_ASM = asm
COREWAR_VM_DIR = vm/src/vm/ft_corewar_vm
COREWAR_INSTR_DIR = vm//src/vm/instructions
COREWAR_VIS_DIR = vm/src/vis
ASM_DIR = assembly/src

SDL2_F	= -framework SDL2 -framework SDL2_image -framework SDL2_ttf -F ./libSDL/
INCLUDE_SDL2 = -I libSDL/SDL2.framework/Headers \
-I libSDL/SDL2_image.framework/Headers \
-I libSDL/SDL2_ttf.framework/Headers
SDL2_P	= -rpath @loader_path/libSDL/
SRC_COREWAR_VM = $(COREWAR_VM_DIR)/ft_vm.c \
			$(COREWAR_VM_DIR)/ft_check_champ.c \
			$(COREWAR_VM_DIR)/ft_error.c \
			$(COREWAR_VM_DIR)/ft_init_and_create.c \
			$(COREWAR_VM_DIR)/ft_fight.c $(COREWAR_VM_DIR)/ft_init_op.c \
			$(COREWAR_VM_DIR)/ft_free_and_kill.c \
			$(COREWAR_VM_DIR)/ft_parse_champ.c \
			$(COREWAR_VM_DIR)/ft_print.c \
			$(COREWAR_VM_DIR)/ft_parse_flag.c \
			$(COREWAR_INSTR_DIR)/ft_add_sub_op.c \
			$(COREWAR_INSTR_DIR)/ft_aff.c \
			$(COREWAR_INSTR_DIR)/ft_fork_lfork_op.c \
			$(COREWAR_INSTR_DIR)/ft_ld_lld_op.c \
			$(COREWAR_INSTR_DIR)/ft_ldi_lldi_op.c \
			$(COREWAR_INSTR_DIR)/ft_live.c \
			$(COREWAR_INSTR_DIR)/ft_log_op.c \
			$(COREWAR_INSTR_DIR)/ft_st.c \
			$(COREWAR_INSTR_DIR)/ft_sti.c \
			$(COREWAR_INSTR_DIR)/ft_zjmp.c
SRC_COREWAR_VIS = $(COREWAR_VIS_DIR)/ft_assistance.c \
			$(COREWAR_VIS_DIR)/ft_event.c \
			$(COREWAR_VIS_DIR)/ft_init_color.c \
			$(COREWAR_VIS_DIR)/ft_init_img.c \
			$(COREWAR_VIS_DIR)/ft_init_info.c \
			$(COREWAR_VIS_DIR)/ft_init_sdl.c \
			$(COREWAR_VIS_DIR)/ft_viz.c \
			$(COREWAR_VIS_DIR)/ft_viz_arena.c \
			$(COREWAR_VIS_DIR)/ft_viz_winner.c
SRC_ASM = $(ASM_DIR)/assist.c $(ASM_DIR)/calc_label.c \
			$(ASM_DIR)/exit.c $(ASM_DIR)/ft_asm.c \
			$(ASM_DIR)/ft_write.c $(ASM_DIR)/instr1.c \
			$(ASM_DIR)/instr2.c $(ASM_DIR)/tokenization.c \
			$(ASM_DIR)/name_and_comment.c
INCLUDES_VM = vm/include
INCLUDES_OP = include
INCLUDES_ASM = assembly/include
INCLUDES_PRINTF = ft_printf/include
FLAG = -Wall -Wextra -Werror

all: $(NAME_COREWAR) $(NAME_ASM)
		
$(NAME_COREWAR):
		@$(MAKE) -C ft_printf
		@gcc $(FLAG) $(SRC_COREWAR_VM) ft_printf/libftprintf.a -I $(INCLUDES_PRINTF) $(SRC_COREWAR_VIS) -I $(INCLUDES_VM) -I $(INCLUDES_OP) -o $(NAME_COREWAR) $(INCLUDE_SDL2) $(SDL2_P) $(SDL2_F)
$(NAME_ASM):
		@gcc $(FLAG) $(SRC_ASM) ft_printf/libftprintf.a -I $(INCLUDES_ASM) -o $(NAME_ASM) -I $(INCLUDES_OP) -I $(INCLUDES_PRINTF)
clean:
		@$(MAKE) -C ft_printf fclean
		@/bin/rm -f rm -f *.o

fclean: clean
		@/bin/rm -f $(NAME_COREWAR) $(NAME_ASM)

re: fclean $(NAME_COREWAR) $(NAME_ASM)
