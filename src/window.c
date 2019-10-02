/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 22:02:41 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/03 00:09:58 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		margin(t_fdf *fdf)
{
	int		margin_x;
	int		margin_y;
	int		i;
	int		j;

	margin_x = (WIN_WIDTH - (2 * MARGIN_FROM_FRAME)) / (fdf->width - 1);
	margin_y = (WIN_HEIGHT - (2 * MARGIN_FROM_FRAME)) / (fdf->height - 1);
	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			fdf->map[i][j].x = fdf->map[i][j].x * margin_x + MARGIN_FROM_FRAME;
			fdf->map[i][j].y = fdf->map[i][j].y * margin_y + MARGIN_FROM_FRAME;
			++j;
		}
		++i;
	}
}

void			create_window(t_fdf *fdf)
{
	int		i;
	int		j;

	margin(fdf);
	if (!(fdf->mlx_ptr = mlx_init()))
		ft_exit(&fdf, MALLOC_FAILURE);
	if (!(fdf->win_ptr = mlx_new_window(fdf->mlx_ptr,\
	WIN_WIDTH, WIN_HEIGHT, "Fil de Fer")))
		ft_exit(&fdf, MALLOC_FAILURE);
	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			i ? draw_line(fdf, fdf->map[i - 1][j].x, fdf->map[i - 1][j].y,\
			fdf->map[i][j].x, fdf->map[i][j].y) : 0;
			j ? draw_line(fdf, fdf->map[i][j - 1].x, fdf->map[i][j - 1].y,\
			fdf->map[i][j].x, fdf->map[i][j].y) : 0;
			++j;
		}
		++i;
	}
//	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, 250, 250, 0xFFFFFF);
	mlx_loop(fdf->mlx_ptr);
}
