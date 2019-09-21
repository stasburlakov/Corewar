/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sdl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 22:24:03 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/23 22:24:04 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar_vm.h"

static void	ft_init_paused_live2(t_sdl *sdl, t_vm *vm)
{
	SDL_Surface	*img;

	img = TTF_RenderText_Blended(sdl->little_font,
			"Last live :", sdl->color[0]);
	if (!img)
		ft_free_sdl(sdl, ERR_SURFACE_TEXT, vm);
	sdl->text_live[0] = SDL_CreateTextureFromSurface(sdl->ren, img);
	if (!sdl->text_live[0])
		ft_free_sdl(sdl, ERR_TEXTURE_TEXT, vm);
	SDL_FreeSurface(img);
	img = TTF_RenderText_Blended(sdl->little_font,
			"Lives in current period :", sdl->color[0]);
	if (!img)
		ft_free_sdl(sdl, ERR_SURFACE_TEXT, vm);
	sdl->text_live[1] = SDL_CreateTextureFromSurface(sdl->ren, img);
	if (!sdl->text_live[1])
		ft_free_sdl(sdl, ERR_TEXTURE_TEXT, vm);
	SDL_FreeSurface(img);
}

static void	ft_init_paused_live(t_sdl *sdl, t_vm *vm)
{
	SDL_Surface	*img;

	img = TTF_RenderText_Blended(sdl->big_font, "PAUSED", sdl->color[6]);
	if (!img)
		ft_free_sdl(sdl, ERR_SURFACE_TEXT, vm);
	sdl->text_pause = SDL_CreateTextureFromSurface(sdl->ren, img);
	if (!sdl->text_pause)
		ft_free_sdl(sdl, ERR_TEXTURE_TEXT, vm);
	SDL_FreeSurface(img);
	img = TTF_RenderText_Blended(sdl->big_font, "RUNNING", sdl->color[5]);
	if (!img)
		ft_free_sdl(sdl, ERR_SURFACE_TEXT, vm);
	sdl->text_play = SDL_CreateTextureFromSurface(sdl->ren, img);
	if (!sdl->text_play)
		ft_free_sdl(sdl, ERR_TEXTURE_TEXT, vm);
	SDL_FreeSurface(img);
	TTF_SizeText(sdl->big_font, "PAUSED",
			&sdl->rect_paused.w, &sdl->rect_paused.h);
	TTF_SizeText(sdl->big_font, "RUNNING",
			&sdl->rect_running.w, &sdl->rect_running.h);
	TTF_SizeText(sdl->little_font, "Last live :",
			&sdl->rect_live[0].w, &sdl->rect_live[0].h);
	TTF_SizeText(sdl->little_font, "Lives in current period :",
			&sdl->rect_live[1].w, &sdl->rect_live[1].h);
	ft_init_paused_live2(sdl, vm);
}

static void	ft_sdl_init_rect(t_sdl *sdl)
{
	sdl->rect_nbr.h = 21;
	sdl->rect_info.h = 50;
	sdl->rect_info.w = 500;
	sdl->rect_info.x = 1347;
	sdl->rect_info.y = 10;
	sdl->rect_running.x = 1495;
	sdl->rect_running.y = 90;
	sdl->rect_paused.x = 1515;
	sdl->rect_paused.y = 90;
	sdl->rect_little_text.x = 1370;
	sdl->rect_little_text.y = 850;
	sdl->rect_number_player.x = 1370;
	sdl->rect_number_player.y = 200;
	sdl->rect_live[1].x = 1370;
	sdl->rect_live[1].y = 266;
	sdl->rect_live[0].x = 1370;
	sdl->rect_live[0].y = 233;
}

static void	ft_init_delay(t_sdl *sdl)
{
	sdl->delay = 0;
	sdl->viz_delay[0] = 1;
	sdl->viz_delay[1] = 5;
	sdl->viz_delay[2] = 10;
	sdl->viz_delay[3] = 25;
	sdl->viz_delay[4] = 50;
	sdl->viz_delay[5] = 100;
	sdl->viz_delay[6] = 200;
	sdl->i_delay = 6;
}

t_sdl		*ft_sdl_init(t_vm *vm)
{
	t_sdl	*sdl;

	sdl = (t_sdl*)malloc(sizeof(t_sdl));
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	sdl->win = SDL_CreateWindow("Corewar", 0, 0, 1850, 1370, SDL_WINDOW_SHOWN);
	if (!sdl->win)
		ft_free_sdl(sdl, NULL, vm);
	sdl->ren = SDL_CreateRenderer(sdl->win, -1, SDL_RENDERER_ACCELERATED);
	sdl->big_font = TTF_OpenFont("vm/image/OpenSans-Bold.ttf", 40);
	sdl->little_font = TTF_OpenFont("vm/image/OpenSans-Bold.ttf", 16);
	if (sdl->big_font == NULL || sdl->little_font == NULL)
		ft_free_sdl(sdl, ERR_FONT_TEXT, vm);
	SDL_SetRenderDrawColor(sdl->ren, 0, 0, 0, 255);
	sdl->rect_nbr.w = (vm->index_viz == 1) ? 21 : 7;
	ft_init_delay(sdl);
	ft_sdl_init_rect(sdl);
	ft_init_color(sdl);
	ft_init_info(sdl, vm);
	(vm->index_viz == 1) ? ft_init_img(sdl, vm) : 0;
	ft_init_paused_live(sdl, vm);
	if (vm->index_viz == 2)
		ft_init_16_number(sdl, vm);
	cut_champ_name(vm);
	return (sdl);
}
