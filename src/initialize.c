/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 22:02:41 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/09 15:33:04 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		margin(t_fdf *fdf)
{
	int		margin_x;
	int		margin_y;
	int		margin_z;
	int		i;
	int		j;

	margin_x = (IMG_WIDTH - (2 * MARGIN)) / (fdf->width - 1);
	margin_y = (IMG_HEIGHT - (2 * MARGIN)) / (fdf->height - 1);
	//margin_z = 10;
	fdf->view->off_x = IMG_WIDTH / 2;
	fdf->view->off_y = IMG_HEIGHT / 2;
	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			fdf->map[i][j].x = fdf->map[i][j].x * margin_x;
			fdf->map[i][j].y = fdf->map[i][j].y * margin_y;
			//fdf->map[i][j].z = fdf->map[i][j].z * margin_z;
			fdf->cur_map[i][j].x = fdf->map[i][j].x;
			fdf->cur_map[i][j].y = fdf->map[i][j].y;
			++j;
		}
		++i;
	}
}

void			initialize(t_fdf *fdf)
{
	int		i;
	int		j;

	if (!(fdf->mlx_ptr = mlx_init()))
		ft_exit(&fdf, MALLOC_FAILURE);
	if (!(fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
	"Fil de fer")))
		ft_exit(&fdf, MALLOC_FAILURE);
	if (!(fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, IMG_WIDTH, IMG_HEIGHT)))
		ft_exit(&fdf, MALLOC_FAILURE);
	if (!(fdf->img_str = mlx_get_data_addr(fdf->img_ptr, &fdf->bpp,\
	&fdf->size_line, &fdf->endian)))
		ft_exit(&fdf, MALLOC_FAILURE);
	if (!(fdf->view = create_view()))
		ft_exit(&fdf, MALLOC_FAILURE);
	margin(fdf);
}
