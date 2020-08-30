/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 20:25:17 by ahusk             #+#    #+#             */
/*   Updated: 2020/08/13 20:25:19 by ahusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_map(t_map *map, t_sdl *sdl)
{
	int y;
	int x;

	y = -1;
	while (++y < map->h)
	{
		x = -1;
		while (++x < map->w)
		{
			map->rect.x = x * map->rect_w;
			map->rect.y = y * map->rect_w;
			map->rect.h = map->rect_w;
			if (map->map[y * map->w + x] == 0)
				map->rect.color = RGB(20, 20, 20);
			if (map->map[y * map->w + x] == 1)
				map->rect.color = RGB(sdl->bytes_texture[0],
				sdl->bytes_texture[1], sdl->bytes_texture[2]);
			if (map->map[y * map->w + x] >= 2)
				map->rect.color = RGB(sdl->bytes_texture[0],
				sdl->bytes_texture[64 * 1], sdl->bytes_texture[64 * 2]);
			draw_rect(sdl, &map->rect);
		}
	}
}
