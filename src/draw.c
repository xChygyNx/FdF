/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:14:12 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/09 14:12:00 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		put_legend(void *mlx_ptr, void *win_ptr, void *img_ptr)
{
	mlx_string_put(mlx_ptr, win_ptr, 5, 0, GREEN, "ROTATE:");
	mlx_string_put(mlx_ptr, win_ptr, 85, 17, WHITE, "on Y: '2' or '8'");
	mlx_string_put(mlx_ptr, win_ptr, 85, 34, WHITE, "on X: '4' or '6'");
	mlx_string_put(mlx_ptr, win_ptr, 85, 51, WHITE, "on Z: '1', '3', '7' or '9'");
	mlx_string_put(mlx_ptr, win_ptr, 5, 75, PURPLE, "SHIFT:");
	mlx_string_put(mlx_ptr, win_ptr, 85, 109, WHITE, "on X: LEFT & RIGHT arrows");
	mlx_string_put(mlx_ptr, win_ptr, 85, 92, WHITE, "on Y: UP & Down arrows");
	mlx_string_put(mlx_ptr, win_ptr, 5, 133, YELLOW, "ZOOM:");
	mlx_string_put(mlx_ptr, win_ptr, 85, 150, WHITE, "increase: '+' on main");
	mlx_string_put(mlx_ptr, win_ptr, 85, 167, WHITE, "reduce: '-' on main");
	mlx_string_put(mlx_ptr, win_ptr, 5, 191, BLUE, "Standard's views:");
	mlx_string_put(mlx_ptr, win_ptr, 85, 208, WHITE, "isometric: 'I' or '/'");
	mlx_string_put(mlx_ptr, win_ptr, 85, 225, WHITE, "in profile: 'P' or '='");
	mlx_string_put(mlx_ptr, win_ptr, 85, 242, WHITE, "view from the top: 'O' or '0'");
	mlx_string_put(mlx_ptr, win_ptr, 5, 266, RED, "Exit:");
	mlx_string_put(mlx_ptr, win_ptr, 85, 2273, WHITE, "Press 'Esc'");

}

static void	draw_image(t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			i ? draw_line(fdf, fdf->cur_map[i][j], fdf->cur_map[i - 1][j]) : 0;
			j ? draw_line(fdf, fdf->cur_map[i][j], fdf->cur_map[i][j - 1]) : 0;
			++j;
		}
		++i;
	}
}

static void	draw_image_y(t_fdf *fdf, char mode)
{
	int		i;
	int		j;

	i = mode == 2 ? fdf->width : 0;
	while (mode == 2 ? i >= 0 : i < fdf->width)
	{
		j = mode == 2 ? 0 : fdf->height - 1;
		while (mode == 2 ? j < fdf->width : j >= 0)
		{
			i ? draw_line(fdf, fdf->cur_map[i][j], fdf->cur_map[i - 1][j]) : 0;
			j ? draw_line(fdf, fdf->cur_map[i][j], fdf->cur_map[i][j - 1]) : 0;
			mode == 2 ? ++j : j--;
		}
		mode == 2 ? ++i : i--;
	}
}

static char	print_mode(t_fdf *fdf)
{
	int		h;
	int		w;

	w = fdf->width - 1;
	h = fdf->height - 1;
	if (fdf->cur_map[0][0].y > fdf->cur_map[w][0].y\
		&& fdf->cur_map[0][0].y > fdf->cur_map[0][h].y)
		return (1);
	else if (fdf->cur_map[0][0].y > fdf->cur_map[w][0].y\
		&& fdf->cur_map[0][0].y < fdf->cur_map[0][h].y)
		return (2);
	else if (fdf->cur_map[0][0].y < fdf->cur_map[w][0].y\
		&& fdf->cur_map[0][0].y > fdf->cur_map[0][h].y)
		return (3);
	else
		return (4);
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
	//mode = print_mode(fdf);
	print_matrix(fdf->view->matrix);
	/*ft_printf("y[0][0] = %d, x[0][0] = %d\n", fdf->cur_map[0][0].y, fdf->cur_map[0][0].x);
	ft_printf("y[h][0] = %d, x[h][0] = %d\n", fdf->cur_map[fdf->height - 1][0].y, fdf->cur_map[fdf->height - 1][0].x);
	ft_printf("y[0][w] = %d, x[0][w] = %d\n", fdf->cur_map[0][fdf->width - 1].y, fdf->cur_map[0][fdf->width - 1].x);
	ft_printf("y[h][w] = %d, x[h][w] = %d\n", fdf->cur_map[fdf->height - 1][fdf->width - 1].y, fdf->cur_map[fdf->height - 1][fdf->width - 1].x);*/
	//ft_printf("relief = %f\n", fdf->view->relief);
	draw_image(fdf);
}
