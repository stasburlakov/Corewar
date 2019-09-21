/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_viz.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egottlie <egottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 08:41:07 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/24 16:25:23 by egottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar_vm.h"

void		ft_viz_player(t_sdl *sdl, t_vm *vm)
{
	int			i;
	SDL_Rect	rect;

	i = 0;
	rect.x = 1492;
	rect.y = sdl->rect_number_player.y;
	while (i < vm->count_champ)
	{
		TTF_SizeText(sdl->little_font,
		vm->champ[i + 1].cut_name, &rect.w, &rect.h);
		sdl->tmp = vm->champ[i + 1].cut_name;
		ft_render_text(sdl, &rect, vm, i + 1);
		SDL_RenderCopy(sdl->ren, sdl->number_player[i],
				NULL, &sdl->rect_number_player);
		sdl->rect_number_player.y += 150;
		rect.y += 150;
		i++;
	}
	sdl->rect_number_player.y -= i * 150;
}

static void	ft_viz_text2(t_sdl *sdl, t_vm *vm)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		SDL_RenderCopy(sdl->ren, sdl->info, NULL, &sdl->rect_info);
		TTF_SizeText(sdl->little_font, sdl->s[i], &sdl->rect_little_text.w,
				&sdl->rect_little_text.h);
		sdl->tmp = sdl->s[i];
		ft_render_text(sdl, &sdl->rect_little_text, vm, 0);
		sdl->rect_little_text.y += 40;
	}
	sdl->rect_little_text.y -= 40 * i;
}

void		ft_viz_text(t_vm *vm, t_sdl *sdl)
{
	char	*tmp;

	tmp = ft_lltoa(sdl->viz_delay[sdl->i_delay]);
	ft_strcpy(sdl->s[0], "Cycles/second :                         ");
	ft_strcat(sdl->s[0], tmp);
	free(tmp);
	tmp = ft_lltoa(vm->count_carriage);
	ft_strcpy(sdl->s[1], "Total processes :                       ");
	ft_strcat(sdl->s[1], tmp);
	free(tmp);
	tmp = ft_lltoa(vm->count_cicle);
	ft_strcpy(sdl->s[2], "Cycle :                                           ");
	ft_strcat(sdl->s[2], tmp);
	free(tmp);
	tmp = ft_lltoa(vm->cycle_to_die);
	ft_strcpy(sdl->s[3], "Cycle to die :                               ");
	ft_strcat(sdl->s[3], tmp);
	free(tmp);
	tmp = ft_lltoa(vm->count_live_period);
	ft_strcpy(sdl->s[4], "Lives in current period :        ");
	ft_strcat(sdl->s[4], tmp);
	free(tmp);
	ft_viz_text2(sdl, vm);
}

void		ft_viz_live(t_sdl *sdl, t_vm *vm, int i)
{
	SDL_Rect	rect;

	rect.x = 1590;
	rect.y = sdl->rect_number_player.y + 33;
	i = 0;
	while (i < vm->count_champ)
	{
		SDL_RenderCopy(sdl->ren, sdl->text_live[0], NULL, &sdl->rect_live[0]);
		sdl->tmp = ft_lltoa(vm->last_live[i]);
		TTF_SizeText(sdl->little_font, sdl->tmp, &rect.w, &rect.h);
		ft_render_text(sdl, &rect, vm, 0);
		free(sdl->tmp);
		SDL_RenderCopy(sdl->ren, sdl->text_live[1], NULL, &sdl->rect_live[1]);
		rect.y += 33;
		sdl->tmp = ft_lltoa(vm->live_in_period[i]);
		TTF_SizeText(sdl->little_font, sdl->tmp, &rect.w, &rect.h);
		ft_render_text(sdl, &rect, vm, 0);
		free(sdl->tmp);
		(++i) && (rect.y += 117);
		sdl->rect_live[0].y += 150;
		sdl->rect_live[1].y += 150;
	}
	sdl->rect_live[0].y -= 150 * i;
	sdl->rect_live[1].y -= 150 * i;
}

int			ft_viz(t_vm *vm, t_sdl *sdl)
{
	SDL_RenderClear(sdl->ren);
	ft_run_carriages(vm, 1);
	ft_viz_player(sdl, vm);
	ft_viz_live(sdl, vm, 0);
	ft_viz_text(vm, sdl);
	if (sdl->rect_nbr.w == 21)
		ft_viz_icon(sdl, vm);
	else
		ft_viz_number(sdl, vm);
	ft_viz_keyboard(sdl, vm);
	ft_event(sdl);
	ft_run_carriages(vm, 2);
	SDL_RenderPresent(sdl->ren);
	SDL_Delay(sdl->delay);
	return (0);
}
