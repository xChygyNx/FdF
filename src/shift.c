/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 21:30:21 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/05 10:34:36 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	shift_x_y(t_fdf *fdf, int offset_x, int offset_y)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			fdf->cur_map[i][j].x = fdf->map[i][j].x + offset_x;
			fdf->cur_map[i][j].y = fdf->map[i][j].y + offset_y;
			j++;
		}
		i++;
	}
}

void	shift_z(t_fdf *fdf, int z)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			if (fdf->map[i][j].z)
				fdf->cur_map[i][j].z = fdf->map[i][j].z + z;
			j++;
		}
		i++;
	}
}
