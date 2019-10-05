/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 22:02:41 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/05 13:32:47 by astripeb         ###   ########.fr       */
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

void			initialize(t_fdf *fdf)
{
	int		i;
	int		j;

	if (!(fdf->mlx_ptr = mlx_init()))
		ft_exit(&fdf, MALLOC_FAILURE);
	if (!(fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
	"Fil de fer")))
		ft_exit(&fdf, MALLOC_FAILURE);
	if (!(fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT)))
		ft_exit(&fdf, MALLOC_FAILURE);
	if (!(fdf->img_str = mlx_get_data_addr(fdf->img_ptr, &fdf->bpp,\
	&fdf->size_line, &fdf->endian)))
		ft_exit(&fdf, MALLOC_FAILURE);
	if (!(fdf->matrix = matrix_orto()))
		ft_exit(&fdf, MALLOC_FAILURE);
	margin(fdf);
}
