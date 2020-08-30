/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talexia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 00:19:54 by talexia           #+#    #+#             */
/*   Updated: 2020/08/22 00:19:56 by talexia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	error(int i)
{
	if (i == 1)
		write(1, "Map is not valid\n", 17);
	else if (i == 2)
		write(1, "No memory allocated\n", 20);
	else if (i == 3)
		write(1, "Texture is not valid\n", 21);
	else if (i == 4)
		write(1, "Not init SDL\n", 13);
	else if (i == 5)
		write(1, "Not create window\n", 18);
	else if (i == 6)
		write(1, "Not create render\n", 18);
	else if (i == 7)
		write(1, "Not create window texture\n", 26);
	else if (i == 8)
		write(1, "Not set relative mousemode\n", 27);
	exit(1);
}
