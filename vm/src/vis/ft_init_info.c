/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 22:23:52 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/23 22:23:53 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar_vm.h"

char	*g_hex_number = "0123456789ABCDEF";

static void	ft_init_16_number3(t_sdl *sdl, t_vm *vm)
{
	SDL_Surface	*img;

	img = TTF_RenderGlyph_Blended(sdl->little_font, ' ', sdl->color[0]);
	if (!img)
		ft_free_sdl(sdl, ERR_SURFACE_TEXT, vm);
	sdl->text_img[160] = SDL_CreateTextureFromSurface(sdl->ren, img);
	if (!sdl->text_img[160])
		ft_free_sdl(sdl, ERR_TEXTURE_TEXT, vm);
	SDL_FreeSurface(img);
}

static void	ft_init_16_number2(t_sdl *sdl, t_vm *vm)
{
	SDL_Surface	*img;
	int			i;
	int			j;

	j = 4;
	while (++j < 10)
	{
		i = 0;
		while (i < 16)
		{
			img = TTF_RenderGlyph_Shaded(sdl->little_font, g_hex_number[i],
					sdl->color[j - 5], sdl->color[j + 2]);
			if (!img)
				ft_free_sdl(sdl, ERR_SURFACE_TEXT, vm);
			sdl->text_img[i + j * 16] =
					SDL_CreateTextureFromSurface(sdl->ren, img);
			if (!sdl->text_img[i + j * 16])
				ft_free_sdl(sdl, ERR_TEXTURE_TEXT, vm);
			SDL_FreeSurface(img);
			i++;
		}
	}
	ft_init_16_number3(sdl, vm);
}

void		ft_init_16_number(t_sdl *sdl, t_vm *vm)
{
	int			i;
	int			j;
	SDL_Surface	*img;

	j = -1;
	while (++j < 5)
	{
		i = -1;
		while (++i < 16)
		{
			img = TTF_RenderGlyph_Blended(sdl->little_font, g_hex_number[i],
			sdl->color[j]);
			if (!img)
				ft_free_sdl(sdl, ERR_SURFACE_TEXT, vm);
			sdl->text_img[i + j * 16] =
					SDL_CreateTextureFromSurface(sdl->ren, img);
			if (!sdl->text_img[i + j * 16])
				ft_free_sdl(sdl, ERR_TEXTURE_TEXT, vm);
			SDL_FreeSurface(img);
		}
	}
	ft_init_16_number2(sdl, vm);
}
