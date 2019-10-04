/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:14:12 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/04 15:22:35 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void put_legend(void *mlx_ptr, void *win_ptr, void *img_ptr)
{
	mlx_string_put(mlx_ptr, win_ptr, 5, 0, WHITE, "put 'button' for to do something");
	mlx_string_put(mlx_ptr, win_ptr, 5, 17, WHITE, "put 'button№2' for to do something else");
	mlx_string_put(mlx_ptr, win_ptr, 5, 34, WHITE, "put 'ʥ' for to do something ");
}

static void refresh_screen_img(t_fdf *fdf)
{
	ft_bzero(fdf->img_str, fdf->size_line * WIN_HEIGHT);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
}

void	draw_image(t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			i ? draw_line(fdf, fdf->map[i][j], fdf->map[i - 1][j]) : 0;
			j ? draw_line(fdf, fdf->map[i][j], fdf->map[i][j - 1]) : 0;
			++j;
		}
		++i;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, IDENTATION);
	//mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 200, 200);
	//refresh_screen_img(fdf);
	put_legend (fdf->mlx_ptr, fdf->win_ptr, (void *)fdf->img_ptr);
	mlx_loop(fdf->mlx_ptr);
}
