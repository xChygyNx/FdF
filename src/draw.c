/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:14:12 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/03 23:38:40 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	ft_bzero(fdf->img_str, fdf->size_line * WIN_HEIGHT);
	mlx_loop(fdf->mlx_ptr);
}
