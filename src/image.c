/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:14:12 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/03 20:20:54 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_image(t_fdf *fdf)
{
	//int				i;
	//int				j;
	//t_vector		**p;
	//unsigned int	*img;

	if (!(mlx_new_image(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT)))
		ft_exit(&fdf, MALLOC_FAILURE);
	if (!(fdf->img_str = (unsigned int*)mlx_get_data_addr(fdf->img_ptr,\
		&fdf->bpp, &fdf->size_line, &fdf->endian)))
		ft_exit(&fdf, MALLOC_FAILURE);
	//if (!(fdf->img_arr = ft_strsplit(fdf->img_str, '\n'));
	
	
}
	
	
	
	/*i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			p = fdf->map + i;
			i ? draw_line(p[0][0].x, p[0][0].y, point[1][0].x, point[1][0].y : 0;
			j ? draw_line(fdf, fdf->map[i][j], fdf->map[i][j - 1]) : 0;
			++j;
		}
		++i;
	}
//	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, 250, 250, 0xFFFFFF);
	mlx_loop(fdf->mlx_ptr);*/