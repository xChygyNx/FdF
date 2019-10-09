/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:14:12 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/09 21:54:05 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		put_legend(void *mlx_ptr, void *win_ptr, void *img_ptr)
{
	mlx_string_put(mlx_ptr, win_ptr, 5, 0, RED, "ROTATE:");
	mlx_string_put(mlx_ptr, win_ptr, 5, 20, YELLOW, "on Y: ");
	mlx_string_put(mlx_ptr, win_ptr, 65, 20, WHITE, "Key '2' / '8'");
	mlx_string_put(mlx_ptr, win_ptr, 65, 40, WHITE, "or click by mouse on upper middle");
	mlx_string_put(mlx_ptr, win_ptr, 65, 60, WHITE, "or bottom middle side of screen");
	mlx_string_put(mlx_ptr, win_ptr, 5, 80, YELLOW, "on X: ");
	mlx_string_put(mlx_ptr, win_ptr, 65, 80, WHITE, "Key '4' / '6'");
	mlx_string_put(mlx_ptr, win_ptr, 65, 100, WHITE, "or click by mouse on left middle");
	mlx_string_put(mlx_ptr, win_ptr, 65, 120, WHITE, "or right middle sige of screen");
	mlx_string_put(mlx_ptr, win_ptr, 5, 140, YELLOW, "on Z:");
	mlx_string_put(mlx_ptr, win_ptr, 65, 140, WHITE, "Key '1' / '3' / '7' / '9'");
	mlx_string_put(mlx_ptr, win_ptr, 65, 160, WHITE, "or click by mouse on corners");
	mlx_string_put(mlx_ptr, win_ptr, 65, 180, WHITE, "of the screen");
	mlx_string_put(mlx_ptr, win_ptr, 5, 500, RED, "SHIFT:");
	mlx_string_put(mlx_ptr, win_ptr, 50, 500, WHITE, "on X: LEFT & RIGHT \
	arrows");
	mlx_string_put(mlx_ptr, win_ptr, 50,500, WHITE, "on Y: UP & Down arrows");
	mlx_string_put(mlx_ptr, win_ptr, 5, 500, RED, "ZOOM:");
	mlx_string_put(mlx_ptr, win_ptr, 50, 500, WHITE, "increase: '+' on main");
	mlx_string_put(mlx_ptr, win_ptr, 50, 500, WHITE, "reduce: '-' on main");
	mlx_string_put(mlx_ptr, win_ptr, 5, 500, RED, "VIEWS:");
	mlx_string_put(mlx_ptr, win_ptr, 50, 500, WHITE, "isometric: 'I' or '/'");
	mlx_string_put(mlx_ptr, win_ptr, 50, 500, WHITE, "in profile: 'P' or '='");
	mlx_string_put(mlx_ptr, win_ptr, 50, 500, WHITE, "view from the top: 'O' \
	or '0'");
	mlx_string_put(mlx_ptr, win_ptr, 5, 500, RED, "Exit:");
	mlx_string_put(mlx_ptr, win_ptr, 50, 500, WHITE, "Press 'Esc'");
}

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
	int		ah;
	char	mode;

	i = 0;
	ah = average_height(fdf);
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			apply_matrix2vector(&fdf->cur_map[i][j], &fdf->map[i][j],\
			fdf->view->matrix);
			fdf->cur_map[i][j].z += (fdf->map[i][j].z - ah) * fdf->view->relief;
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
