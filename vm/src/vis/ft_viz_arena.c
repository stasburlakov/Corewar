/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_viz_arena.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 22:24:29 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/23 22:24:30 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar_vm.h"

static void	ft_viz_icon2(t_sdl *sdl, t_vm *vm, int j)
{
	if (vm->player_arena[j] == 3)
		SDL_RenderCopy(sdl->ren, sdl->t_purple, NULL, &sdl->rect_nbr);
	else if (vm->player_arena[j] == 4)
		SDL_RenderCopy(sdl->ren, sdl->t_green, NULL, &sdl->rect_nbr);
	else if (vm->player_arena[j] == 5)
		SDL_RenderCopy(sdl->ren, sdl->t_black_back, NULL, &sdl->rect_nbr);
	else if (vm->player_arena[j] == 6)
		SDL_RenderCopy(sdl->ren, sdl->t_red_back, NULL, &sdl->rect_nbr);
	else if (vm->player_arena[j] == 7)
		SDL_RenderCopy(sdl->ren, sdl->t_yellow_back, NULL, &sdl->rect_nbr);
	else if (vm->player_arena[j] == 8)
		SDL_RenderCopy(sdl->ren, sdl->t_purple_back, NULL, &sdl->rect_nbr);
	else
		SDL_RenderCopy(sdl->ren, sdl->t_green_back, NULL, &sdl->rect_nbr);
}

void		ft_viz_icon(t_sdl *sdl, t_vm *vm)
{
	int i;
	int j;

	j = 0;
	sdl->rect_nbr.y = 0;
	while (j < MEM_SIZE)
	{
		sdl->rect_nbr.x = 0;
		i = -1;
		while (++i < 64)
		{
			if (vm->player_arena[j] == 0)
				SDL_RenderCopy(sdl->ren, sdl->t_black, NULL, &sdl->rect_nbr);
			else if (vm->player_arena[j] == 1)
				SDL_RenderCopy(sdl->ren, sdl->t_red, NULL, &sdl->rect_nbr);
			else if (vm->player_arena[j] == 2)
				SDL_RenderCopy(sdl->ren, sdl->t_yellow, NULL, &sdl->rect_nbr);
			else
				ft_viz_icon2(sdl, vm, j);
			sdl->rect_nbr.x += sdl->rect_nbr.w;
			j++;
		}
		sdl->rect_nbr.y += sdl->rect_nbr.h;
	}
}

static void	ft_viz_number_help(t_sdl *sdl, SDL_Texture *texture)
{
	SDL_RenderCopy(sdl->ren, texture, NULL, &sdl->rect_nbr);
	sdl->rect_nbr.x += sdl->rect_nbr.w;
}

void		ft_viz_number(t_sdl *sdl, t_vm *vm)
{
	int		i;
	int		j;
	char	t[2];

	j = 0;
	sdl->rect_nbr.y = 0;
	while (j < MEM_SIZE)
	{
		sdl->rect_nbr.x = 0;
		i = -1;
		while (++i < 64)
		{
			ft_memset(t, 0, 2);
			t[1] = ((unsigned char)vm->arena[j]) & 0xF;
			t[0] = ((unsigned char)vm->arena[j]) >> 4;
			ft_viz_number_help(sdl, sdl->text_img[t[0] +
			vm->player_arena[j] * 16]);
			ft_viz_number_help(sdl, sdl->text_img[t[1] +
			vm->player_arena[j] * 16]);
			ft_viz_number_help(sdl, sdl->text_img[160]);
			j++;
		}
		sdl->rect_nbr.y += sdl->rect_nbr.h;
	}
}

void		ft_viz_keyboard(t_sdl *sdl, t_vm *vm)
{
	SDL_Rect	rect;

	rect.x = sdl->rect_little_text.x + 100;
	rect.y = 1130;
	sdl->tmp = "PAUSE / PLAY : \"SPACE\"";
	TTF_SizeText(sdl->little_font, sdl->tmp, &rect.w, &rect.h);
	ft_render_text(sdl, &rect, vm, 0);
	sdl->tmp = "ADD SPEED : \"+\"";
	TTF_SizeText(sdl->little_font, sdl->tmp, &rect.w, &rect.h);
	rect.y += 40;
	ft_render_text(sdl, &rect, vm, 0);
	sdl->tmp = "REDUCE SPEED : \"-\"";
	TTF_SizeText(sdl->little_font, sdl->tmp, &rect.w, &rect.h);
	rect.y += 40;
	ft_render_text(sdl, &rect, vm, 0);
	sdl->tmp = "EXIT : \"ESC\"";
	TTF_SizeText(sdl->little_font, sdl->tmp, &rect.w, &rect.h);
	rect.y += 40;
	ft_render_text(sdl, &rect, vm, 0);
}
