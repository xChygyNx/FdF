/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:14:12 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/10 20:21:58 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_left_right(t_fdf *fdf, int i)
{
	int j;

	j = 0;
	while (j < fdf->width)
	{
		i ? draw_line(fdf, fdf->cur_map[i][j], fdf->cur_map[i - 1][j]) : 0;
		j ? draw_line(fdf, fdf->cur_map[i][j], fdf->cur_map[i][j - 1]) : 0;
		++j;
	}
}

static void	draw_right_left(t_fdf *fdf, int i)
{
	int j;

	j = fdf->width - 1;
	while (j >= 0)
	{
		i ? draw_line(fdf, fdf->cur_map[i][j], fdf->cur_map[i - 1][j]) : 0;
		j ? draw_line(fdf, fdf->cur_map[i][j], fdf->cur_map[i][j - 1]) : 0;
		--j;
	}
}

static void	draw_image(t_fdf *fdf)
{
	int		i;

	i = (fabs(fdf->view->x) < PI) ? 0 : fdf->height - 1;
	if (!i)
	{
		while (i < fdf->height)
		{
			if (fabs(fdf->view->y) < PI)
				draw_left_right(fdf, i);
			else
				draw_right_left(fdf, i);
			++i;
		}
	}
	else
	{
		while (i >= 0)
		{
			if (fabs(fdf->view->y) < PI)
				draw_left_right(fdf, i);
			else
				draw_right_left(fdf, i);
			--i;
		}
	}
}

void		view(t_fdf *fdf)
{
	int		i;
	int		j;
	char	mode;
	int 	k;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			apply_matrix2vector(&fdf->cur_map[i][j], &fdf->map[i][j],\
			fdf->view->matrix);
			fdf->cur_map[i][j].z += (int)((fdf->map[i][j].z - fdf->ah) * fdf->view->relief);
			fdf->cur_map[i][j].x *= fdf->view->zoom;
			fdf->cur_map[i][j].y *= fdf->view->zoom;
			fdf->cur_map[i][j].z *= fdf->view->zoom;
			fdf->cur_map[i][j].x += fdf->view->off_x;
			fdf->cur_map[i][j].y += fdf->view->off_y;
			++j;
		}
		++i;
	}
	draw_image(fdf);
}
