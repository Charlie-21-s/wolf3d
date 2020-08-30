/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talexia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 00:19:54 by talexia           #+#    #+#             */
/*   Updated: 2020/08/22 00:19:56 by talexia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		get_size_map(int fd, t_main *main)
{
	char	a[1];
	int		width;
	char	tmp;

	main->map.w = 0;
	main->map.h = 1;
	width = 0;
	while (read(fd, a, 1) > 0 && a[0] != '\n')
		if (a[0] == '1' || a[0] == '0' || a[0] == '2')
			main->map.w++;
	while (read(fd, a, 1) > 0)
	{
		tmp = a[0];
		if (a[0] == '1' || a[0] == '0' || a[0] == '2')
			width++;
		if (a[0] == '\n')
		{
			if (width != main->map.w)
				error(1);
			width = 0;
			main->map.h++;
		}
	}
	if (main->map.w < 3 || main->map.h < 3 || tmp != '\n')
		error(1);
}

static void		fill_map(int fd, t_main *main)
{
	char	a[1];
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 1;
	while (read(fd, a, 1) > 0)
	{
		if (a[0] == '1' || a[0] == '0' || a[0] == '2')
		{
			main->map.map[i] = (int)a[0] - 48;
			i++;
			x++;
			if ((x == 1 || x == main->map.w || y == 1 ||
				y == main->map.h) && a[0] == '0')
				error(1);
		}
		if (a[0] == '\n')
		{
			x = 0;
			y++;
		}
	}
}

static void		check_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->h * map->w && map->map[i] != 0)
		i++;
	if (map->map[i] == 0 && i < map->h * map->w)
	{
		map->y = i / map->w;
		map->x = i % map->w;
	}
	else
		error(1);
}

static void		map_rect_w(t_map *map)
{
	int rect_w;
	int rect_h;

	rect_w = W_W / map->w / 3;
	rect_h = W_H / map->h / 3;
	if (rect_h < rect_w)
		map->rect_w = rect_h;
	else
		map->rect_w = rect_w;
}

void			read_map(t_main *main, char *file)
{
	int		fd;

	if ((fd = open(file, O_RDONLY, 0)) < 1)
		error(1);
	get_size_map(fd, main);
	close(fd);
	if ((fd = open(file, O_RDONLY, 0)) < 1)
		error(1);
	if (!(main->map.map = (int*)malloc(sizeof(int) *
		main->map.h * main->map.w)))
		error(2);
	fill_map(fd, main);
	close(fd);
	check_map(&main->map);
	map_rect_w(&main->map);
}
