/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:13:56 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/06 19:14:03 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	apply_matrix2vector(t_vector *cur, t_vector *src, float **mtx)
{
	cur->x = src->x * mtx[0][0] + src->y * mtx[0][1] + src->z * mtx[0][2];
	cur->y = src->x * mtx[1][0] + src->y * mtx[1][1] + src->z * mtx[1][2];
	cur->z = src->x * mtx[2][0] + src->y * mtx[2][1] + src->z * mtx[2][2];
}

void		rotate(t_fdf *fdf, float **matrix)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			apply_matrix2vector(&fdf->cur_map[i][j], &fdf->map[i][j], matrix);
			++j;
		}
		++i;
	}
}

void		isometric(t_fdf *fdf)
{
	free_matrix(&fdf->view->matrix);
	if (!(fdf->view->matrix = matrix_z(0.523599)))
		ft_exit(&fdf, MALLOC_FAILURE);
	if (!(fdf->view->matrix = change_matrix(fdf->view->matrix, 0.523599, AXIS_X)))
		ft_exit(&fdf, MALLOC_FAILURE);
	rotate(fdf, fdf->view->matrix);
	fdf->view->off_x = 0;
	fdf->view->off_y = 0;
	fdf->view->zoom = 1.0;
}

void		flatten(t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			fdf->cur_map[i][j].x = fdf->map[i][j].x;
			fdf->cur_map[i][j].y = fdf->map[i][j].y;
			fdf->cur_map[i][j].z = fdf->map[i][j].z;
			++j;
		}
		++i;
	}
	if (!(fdf->view->matrix = matrix_orto()))
		ft_exit(&fdf, MALLOC_FAILURE);
	fdf->view->off_x = 0;
	fdf->view->off_y = 0;
	fdf->view->zoom = 1.0;
}
