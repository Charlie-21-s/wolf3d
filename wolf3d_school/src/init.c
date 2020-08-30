/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 00:30:46 by ahusk             #+#    #+#             */
/*   Updated: 2020/08/22 00:30:47 by ahusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		init_sdl(t_sdl *sdl)
{
	if (!(sdl->pic = SDL_LoadBMP("texture.bmp")))
		error(3);
	if (sdl->pic->h < 64 || sdl->pic->w < 192)
		error(3);
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		error(4);
	if (!(sdl->win = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, W_W, W_H, SDL_WINDOW_SHOWN)))
		error(5);
	if (!(sdl->rend = SDL_CreateRenderer(sdl->win, -1,
		SDL_RENDERER_ACCELERATED)))
		error(6);
	sdl->textures = SDL_ConvertSurfaceFormat(sdl->pic,
		SDL_PIXELFORMAT_ABGR8888, 0);
	sdl->bytes_texture = (unsigned char*)sdl->textures->pixels;
	if (!(sdl->win_texture = SDL_CreateTexture(sdl->rend,
		SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, W_W, W_H)))
		error(7);
	if (SDL_SetRelativeMouseMode(SDL_TRUE) < 0)
		error(8);
	sdl->run = true;
	return (0);
}

void	init_player(t_player *player, t_map *map)
{
	player->x = map->x * map->rect_w + map->rect_w / 2;
	player->y = map->y * map->rect_w + map->rect_w / 2;
	player->rect.x = player->x - 3;
	player->rect.y = player->y - 3;
	player->angle = 2121;
	player->speed = map->rect_w / 8;
	player->mouse_x = 0;
	player->rect.h = 6;
	player->rect.color = RGB(255, 255, 255);
}

void	init(t_main *main)
{
	init_player(&main->player, &main->map);
	init_sdl(&main->sdl);
}
