/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:14:12 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/05 13:42:07 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void put_legend(void *mlx_ptr, void *win_ptr, void *img_ptr)
{
	mlx_string_put(mlx_ptr, win_ptr, 5, 0, WHITE, "put 'Ø' for to do something");
	mlx_string_put(mlx_ptr, win_ptr, 5, 17, WHITE, "put 'Ѻ' for to do something else");
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
			i ? draw_line(fdf, fdf->cur_map[i][j], fdf->cur_map[i - 1][j]) : 0;
			j ? draw_line(fdf, fdf->cur_map[i][j], fdf->cur_map[i][j - 1]) : 0;
			++j;
		}
		++i;
	}

}

void	ft_fdf(t_fdf *fdf)
{
	double z;

	z = 0.1;
	mlx_key_hook(fdf->win_ptr, &key_hook, (void*)fdf);
	mlx_loop(fdf->mlx_ptr);
}
