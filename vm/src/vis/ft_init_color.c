/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 22:23:36 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/07/23 22:23:37 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar_vm.h"

static void	ft_init_color3(t_sdl *sdl)
{
	sdl->color[5].r = 106;
	sdl->color[5].g = 235;
	sdl->color[5].b = 131;
	sdl->color[5].a = 255;
	sdl->color[6].r = 249;
	sdl->color[6].g = 60;
	sdl->color[6].b = 60;
	sdl->color[6].a = 255;
}

static void	ft_init_color2(t_sdl *sdl)
{
	sdl->color[7].r = 162;
	sdl->color[7].g = 162;
	sdl->color[7].b = 162;
	sdl->color[7].a = 255;
	sdl->color[8].r = 244;
	sdl->color[8].g = 181;
	sdl->color[8].b = 180;
	sdl->color[8].a = 255;
	sdl->color[9].r = 253;
	sdl->color[9].g = 246;
	sdl->color[9].b = 183;
	sdl->color[9].a = 255;
	sdl->color[10].r = 228;
	sdl->color[10].g = 181;
	sdl->color[10].b = 250;
	sdl->color[10].a = 255;
	sdl->color[11].r = 194;
	sdl->color[11].g = 253;
	sdl->color[11].b = 203;
	sdl->color[11].a = 255;
	ft_init_color3(sdl);
}

void		ft_init_color(t_sdl *sdl)
{
	sdl->color[0].a = 255;
	sdl->color[0].r = 255;
	sdl->color[0].g = 255;
	sdl->color[0].b = 255;
	sdl->color[1].r = 231;
	sdl->color[1].g = 76;
	sdl->color[1].b = 60;
	sdl->color[1].a = 255;
	sdl->color[2].r = 241;
	sdl->color[2].g = 196;
	sdl->color[2].b = 15;
	sdl->color[2].a = 255;
	sdl->color[3].r = 155;
	sdl->color[3].g = 89;
	sdl->color[3].b = 182;
	sdl->color[3].a = 255;
	sdl->color[4].r = 26;
	sdl->color[4].g = 188;
	sdl->color[4].b = 156;
	sdl->color[4].a = 255;
	ft_init_color2(sdl);
}
