/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 00:19:54 by ahusk             #+#    #+#             */
/*   Updated: 2020/08/22 00:19:56 by ahusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	quit(t_sdl *sdl)
{
	SDL_DestroyRenderer(sdl->rend);
	sdl->rend = NULL;
	SDL_DestroyTexture(sdl->win_texture);
	sdl->win_texture = NULL;
	SDL_DestroyWindow(sdl->win);
	sdl->win = NULL;
	SDL_Quit();
}

int		main(int arg, char **argv)
{
	t_main main;

	if (arg != 2)
		error(1);
	read_map(&main, argv[1]);
	init(&main);
	while (main.sdl.run)
	{
		hooks(&main.sdl, &main.map, &main.player);
		SDL_LockTexture(main.sdl.win_texture,
			NULL, (void**)&main.sdl.bytes, &main.sdl.pitch);
		draw_skybox(&main.sdl, &main.player);
		draw_walls(&main, &main.player, &main.raycast, &main.map);
		draw_map(&main.map, &main.sdl);
		draw_fov(&main.sdl, &main.player);
		draw_rect(&main.sdl, &main.player.rect);
		SDL_UnlockTexture(main.sdl.win_texture);
		SDL_RenderCopy(main.sdl.rend, main.sdl.win_texture, NULL, NULL);
		SDL_RenderPresent(main.sdl.rend);
	}
	quit(&main.sdl);
	return (0);
}
