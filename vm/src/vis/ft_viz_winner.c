/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_viz_winner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egottlie <egottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 22:24:39 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/24 16:21:44 by egottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar_vm.h"

static void	ft_viz_crown(t_sdl *sdl, t_vm *vm)
{
	SDL_Rect	rect;
	int			i;

	i = 0;
	rect.x = 1380;
	rect.y = sdl->rect_number_player.y - 40;
	while (i <= vm->count_champ)
	{
		if (vm->winner == vm->champ[i + 1].cut_name)
			break ;
		rect.y += 150;
		i++;
	}
	rect.w = 40;
	rect.h = 40;
	SDL_RenderCopy(sdl->ren, sdl->crown, NULL, &rect);
}

static void	ft_viz_winner_player(t_sdl *sdl, char *s)
{
	char		tmp[ft_strlen(s) + 10];
	SDL_Texture	*texture;
	SDL_Surface	*img;

	ft_strcpy(tmp, "WINNER:  ");
	ft_strcat(tmp, s);
	TTF_SizeText(sdl->big_font, tmp,
			&sdl->rect_running.w, &sdl->rect_running.h);
	img = TTF_RenderText_Blended(sdl->big_font, tmp, sdl->color[5]);
	texture = SDL_CreateTextureFromSurface(sdl->ren, img);
	sdl->rect_running.x -= 120;
	SDL_RenderCopy(sdl->ren, texture, NULL, &sdl->rect_running);
	SDL_FreeSurface(img);
	SDL_DestroyTexture(texture);
}

void		ft_viz_winner(t_vm *vm, t_sdl *sdl)
{
	SDL_RenderClear(sdl->ren);
	ft_viz_player(sdl, vm);
	ft_viz_live(sdl, vm, 0);
	vm->count_carriage = 0;
	ft_viz_text(vm, sdl);
	if (sdl->rect_nbr.w == 21)
		ft_viz_icon(sdl, vm);
	else
		ft_viz_number(sdl, vm);
	ft_viz_keyboard(sdl, vm);
	ft_viz_winner_player(sdl, vm->winner);
	ft_viz_crown(sdl, vm);
	SDL_RenderPresent(sdl->ren);
	ft_event_quit(sdl, vm);
}
