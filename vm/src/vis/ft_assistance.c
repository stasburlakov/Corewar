/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preparation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 22:24:09 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/23 22:24:10 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar_vm.h"

void	ft_naming_player(t_sdl *sdl, t_vm *vm)
{
	int			i;
	SDL_Surface	*img;
	char		tmp[2];
	char		str[170];

	i = 0;
	while (i < vm->count_champ)
	{
		tmp[0] = i + '1';
		tmp[1] = 0;
		ft_strcpy(str, "Player :   -");
		ft_strcat(str, tmp);
		img = TTF_RenderText_Blended(sdl->little_font, str, sdl->color[0]);
		if (!img)
			ft_free_sdl(sdl, ERR_SURFACE_TEXT, vm);
		sdl->number_player[i] = SDL_CreateTextureFromSurface(sdl->ren, img);
		if (!sdl->number_player[i])
			ft_free_sdl(sdl, ERR_TEXTURE_TEXT, vm);
		SDL_FreeSurface(img);
		i++;
	}
	TTF_SizeText(sdl->little_font, "Player :   -2",
			&sdl->rect_number_player.w, &sdl->rect_number_player.h);
}

void	cut_champ_name(t_vm *vm)
{
	char	c;
	int		i;

	i = 0;
	while (i < vm->count_champ)
	{
		if (ft_strlen(vm->champ[i + 1].name) > 11)
		{
			c = vm->champ[i + 1].name[11];
			vm->champ[i + 1].name[11] = 0;
			ft_strcpy(vm->champ[i + 1].cut_name, vm->champ[i + 1].name);
			ft_strcat(vm->champ[i + 1].cut_name, "...");
			vm->champ[i + 1].name[11] = c;
		}
		else
			ft_strcpy(vm->champ[i + 1].cut_name, vm->champ[i + 1].name);
		i++;
	}
}

void	ft_render_text(t_sdl *sdl, SDL_Rect *rect, t_vm *vm, int color)
{
	SDL_Texture	*texture;
	SDL_Surface	*img;

	img = TTF_RenderText_Blended(sdl->little_font, sdl->tmp, sdl->color[color]);
	if (!img)
		ft_free_sdl(sdl, ERR_SURFACE_TEXT, vm);
	texture = SDL_CreateTextureFromSurface(sdl->ren, img);
	if (!texture)
		ft_free_sdl(sdl, ERR_TEXTURE_TEXT, vm);
	SDL_RenderCopy(sdl->ren, texture, NULL, rect);
	SDL_FreeSurface(img);
	SDL_DestroyTexture(texture);
}

void	ft_free_sdl(t_sdl *sdl, char *s, t_vm *vm)
{
	ft_putstr(s);
	if (sdl->win)
	{
		SDL_DestroyWindow(sdl->win);
		if (sdl->ren)
		{
			SDL_DestroyRenderer(sdl->ren);
			if (sdl->big_font)
				TTF_CloseFont(sdl->big_font);
			if (sdl->little_font)
				TTF_CloseFont(sdl->little_font);
		}
	}
	TTF_Quit();
	SDL_Quit();
	ft_free_vm(vm);
	exit(0);
}

void	ft_run_carriages(t_vm *vm, int index)
{
	t_carriage		*carriage;

	carriage = vm->carriage;
	if (index == 1)
		while (carriage)
		{
			if (vm->player_arena[carriage->current_position] < 5)
				vm->player_arena[carriage->current_position] += 5;
			carriage = carriage->next;
		}
	else
	{
		while (carriage)
		{
			if (vm->player_arena[carriage->current_position] >= 5)
				vm->player_arena[carriage->current_position] -= 5;
			carriage = carriage->next;
		}
	}
}
