/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 22:23:46 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/23 22:23:47 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar_vm.h"

void		ft_init_info(t_sdl *sdl, t_vm *vm)
{
	SDL_Surface	*img;

	img = IMG_Load("vm/image/yellow.png");
	if (!img)
		ft_free_sdl(sdl, ERR_IMAGE_TEXT, vm);
	sdl->t_yellow = SDL_CreateTextureFromSurface(sdl->ren, img);
	if (!sdl->t_yellow)
		ft_free_sdl(sdl, ERR_TEXTURE_TEXT, vm);
	SDL_FreeSurface(img);
	img = IMG_Load("vm/image/crown.png");
	if (!img)
		ft_free_sdl(sdl, ERR_IMAGE_TEXT, vm);
	sdl->crown = SDL_CreateTextureFromSurface(sdl->ren, img);
	if (!sdl->crown)
		ft_free_sdl(sdl, ERR_TEXTURE_TEXT, vm);
	SDL_FreeSurface(img);
	img = IMG_Load("vm/image/info.png");
	if (!img)
		ft_free_sdl(sdl, ERR_IMAGE_TEXT, vm);
	sdl->info = SDL_CreateTextureFromSurface(sdl->ren, img);
	if (!sdl->info)
		ft_free_sdl(sdl, ERR_TEXTURE_TEXT, vm);
	SDL_FreeSurface(img);
}

static void	ft_init_img3(t_sdl *sdl, t_vm *vm)
{
	SDL_Surface	*img;

	img = IMG_Load("vm/image/red_back.png");
	if (!img)
		ft_free_sdl(sdl, ERR_IMAGE_TEXT, vm);
	sdl->t_red_back = SDL_CreateTextureFromSurface(sdl->ren, img);
	if (!sdl->t_red_back)
		ft_free_sdl(sdl, ERR_TEXTURE_TEXT, vm);
	SDL_FreeSurface(img);
	img = IMG_Load("vm/image/red.png");
	if (!img)
		ft_free_sdl(sdl, ERR_IMAGE_TEXT, vm);
	sdl->t_red = SDL_CreateTextureFromSurface(sdl->ren, img);
	if (!sdl->t_red)
		ft_free_sdl(sdl, ERR_TEXTURE_TEXT, vm);
	SDL_FreeSurface(img);
	img = IMG_Load("vm/image/yellow_back.png");
	if (!img)
		ft_free_sdl(sdl, ERR_IMAGE_TEXT, vm);
	sdl->t_yellow_back = SDL_CreateTextureFromSurface(sdl->ren, img);
	if (!sdl->t_yellow_back)
		ft_free_sdl(sdl, ERR_TEXTURE_TEXT, vm);
	SDL_FreeSurface(img);
	ft_init_info(sdl, vm);
}

static void	ft_init_img2(t_sdl *sdl, t_vm *vm)
{
	SDL_Surface	*img;

	img = IMG_Load("vm/image/green.png");
	if (!img)
		ft_free_sdl(sdl, ERR_IMAGE_TEXT, vm);
	sdl->t_green = SDL_CreateTextureFromSurface(sdl->ren, img);
	if (!sdl->t_green)
		ft_free_sdl(sdl, ERR_TEXTURE_TEXT, vm);
	SDL_FreeSurface(img);
	img = IMG_Load("vm/image/purple_back.png");
	if (!img)
		ft_free_sdl(sdl, ERR_IMAGE_TEXT, vm);
	sdl->t_purple_back = SDL_CreateTextureFromSurface(sdl->ren, img);
	if (!sdl->t_purple_back)
		ft_free_sdl(sdl, ERR_TEXTURE_TEXT, vm);
	SDL_FreeSurface(img);
	img = IMG_Load("vm/image/purple.png");
	if (!img)
		ft_free_sdl(sdl, ERR_IMAGE_TEXT, vm);
	sdl->t_purple = SDL_CreateTextureFromSurface(sdl->ren, img);
	if (!sdl->t_purple)
		ft_free_sdl(sdl, ERR_TEXTURE_TEXT, vm);
	SDL_FreeSurface(img);
	ft_init_img3(sdl, vm);
}

void		ft_init_img(t_sdl *sdl, t_vm *vm)
{
	SDL_Surface	*img;

	img = IMG_Load("vm/image/black.png");
	if (!img)
		ft_free_sdl(sdl, ERR_IMAGE_TEXT, vm);
	sdl->t_black = SDL_CreateTextureFromSurface(sdl->ren, img);
	if (!sdl->t_black)
		ft_free_sdl(sdl, ERR_TEXTURE_TEXT, vm);
	SDL_FreeSurface(img);
	img = IMG_Load("vm/image/black_back.png");
	if (!img)
		ft_free_sdl(sdl, ERR_IMAGE_TEXT, vm);
	sdl->t_black_back = SDL_CreateTextureFromSurface(sdl->ren, img);
	if (!sdl->t_black_back)
		ft_free_sdl(sdl, ERR_TEXTURE_TEXT, vm);
	SDL_FreeSurface(img);
	img = IMG_Load("vm/image/green_back.png");
	if (!img)
		ft_free_sdl(sdl, ERR_IMAGE_TEXT, vm);
	sdl->t_green_back = SDL_CreateTextureFromSurface(sdl->ren, img);
	if (!sdl->t_green_back)
		ft_free_sdl(sdl, ERR_TEXTURE_TEXT, vm);
	SDL_FreeSurface(img);
	ft_init_img2(sdl, vm);
}
