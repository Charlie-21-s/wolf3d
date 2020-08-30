/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 15:39:42 by ahusk             #+#    #+#             */
/*   Updated: 2020/08/30 15:39:44 by ahusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	hook_mouse(t_sdl *sdl, t_player *player)
{
	if (sdl->e.type == SDL_MOUSEMOTION)
	{
		if (sdl->e.motion.x - player->mouse_x > 0 || sdl->e.motion.x == W_W - 1)
			player->angle += 0.1;
		else
			player->angle -= 0.1;
		player->mouse_x = sdl->e.motion.x;
	}
}

void	check_move(t_map *map, t_player *player, float x, float y)
{
	if ((map->map[(((int)x + 3) / map->rect_w) +
	((int)y + 3) / map->rect_w * map->w]) == 0 &&
	(map->map[(((int)x - 3) / map->rect_w) +
	((int)y - 3) / map->rect_w * map->w]) == 0 &&
	(map->map[((int)x / map->rect_w) +
	(int)y / map->rect_w * map->w]) == 0)
	{
		player->x = x;
		player->y = y;
		player->rect.x = player->x - 3;
		player->rect.y = player->y - 3;
	}
}

void	hooks(t_sdl *sdl, t_map *map, t_player *player)
{
	float		tmp_x;
	float		tmp_y;

	while (SDL_PollEvent(&sdl->e) != 0)
	{
		if (sdl->e.type == SDL_QUIT)
			sdl->run = false;
		hook_mouse(sdl, player);
		if (sdl->e.type == SDL_KEYDOWN)
		{
			if (sdl->e.key.keysym.sym == SDLK_ESCAPE)
				sdl->run = false;
			tmp_x = cos(player->angle) * player->speed;
			tmp_y = sin(player->angle) * player->speed;
			if (sdl->e.key.keysym.sym == SDLK_w)
				check_move(map, player, player->x + tmp_x, player->y + tmp_y);
			if (sdl->e.key.keysym.sym == SDLK_s)
				check_move(map, player, player->x - tmp_x, player->y - tmp_y);
			if (sdl->e.key.keysym.sym == SDLK_d)
				check_move(map, player, player->x - tmp_y, player->y + tmp_x);
			if (sdl->e.key.keysym.sym == SDLK_a)
				check_move(map, player, player->x + tmp_y, player->y - tmp_x);
		}
	}
}
