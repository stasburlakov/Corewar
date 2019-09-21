/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egottlie <egottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 22:23:21 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/24 15:52:03 by egottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar_vm.h"

static int	ft_event_pausa(SDL_Event event)
{
	event.key.keysym.scancode = 1;
	while (1)
	{
		SDL_Delay(50);
		SDL_PollEvent(&event);
		if (event.type == SDL_KEYUP)
		{
			if (event.key.keysym.scancode == SDL_SCANCODE_SPACE)
				break ;
			else if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				exit(0);
		}
		else if (event.type == SDL_QUIT)
			exit(0);
	}
	return (0);
}

static int	ft_event_key(SDL_Event event, t_sdl *sdl)
{
	if (event.key.keysym.scancode == SDL_SCANCODE_SPACE)
	{
		SDL_RenderCopy(sdl->ren, sdl->text_pause, NULL, &sdl->rect_paused);
		SDL_RenderPresent(sdl->ren);
		return (ft_event_pausa(event));
	}
	else
	{
		if (event.key.keysym.scancode == 86 && sdl->i_delay > 0)
		{
			sdl->delay = (sdl->delay + 2) * 28 / 13;
			sdl->i_delay -= 1;
		}
		else if (event.key.keysym.scancode == SDL_SCANCODE_KP_PLUS &&
		sdl->delay >= 1)
		{
			sdl->delay = (sdl->delay > 10) ? (sdl->delay - 2) * 13 / 28 : 0;
			sdl->i_delay += 1;
		}
		else if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			exit(0);
	}
	return (1);
}

int			ft_event(t_sdl *sdl)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			exit(0);
		else if (event.type == SDL_KEYUP)
		{
			if (!ft_event_key(event, sdl))
				return (0);
		}
	}
	SDL_RenderCopy(sdl->ren, sdl->text_play, NULL, &sdl->rect_running);
	return (1);
}

void		ft_event_quit(t_sdl *sdl, t_vm *vm)
{
	SDL_Event event;

	while (SDL_WaitEvent(&event))
	{
		if (event.type == SDL_QUIT)
			ft_free_sdl(sdl, NULL, vm);
		else if (event.type == SDL_KEYUP &&
		event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			ft_free_sdl(sdl, NULL, vm);
	}
	ft_free_sdl(sdl, NULL, vm);
}
