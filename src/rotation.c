/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:13:56 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/09 16:33:18 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		apply_matrix2vector(t_vector *cur, t_vector *src, float **mtx)
{
	cur->x = src->x * mtx[0][0] + src->y * mtx[0][1] + src->z * mtx[0][2];
	cur->y = src->x * mtx[1][0] + src->y * mtx[1][1] + src->z * mtx[1][2];
	cur->z = src->x * mtx[2][0] + src->y * mtx[2][1] + src->z * mtx[2][2];
}

void		isometric(t_fdf *fdf)
{
	free_matrix(&fdf->view->matrix);
	if (!(fdf->view->matrix = matrix_z(0.523599)))
		ft_exit(&fdf, MALLOC_FAILURE);
	change_matrix(fdf, 0.523599, AXIS_X);
	fdf->view->off_x = IMG_WIDTH / 2;
	fdf->view->off_y = IMG_HEIGHT / 2;
	fdf->view->zoom = 1.0;
}

void		flatten(t_fdf *fdf)
{
	free_matrix(&fdf->view->matrix);
	if (!(fdf->view->matrix = matrix_orto()))
		ft_exit(&fdf, MALLOC_FAILURE);
	fdf->view->off_x = IMG_WIDTH / 2;
	fdf->view->off_y = IMG_HEIGHT / 2;
	fdf->view->zoom = 1.0;
}

void		profile(float **matrix)
{
	matrix[0][0] = 1.0;
	matrix[0][1] = 0.0;
	matrix[0][2] = 0.0;
	matrix[1][0] = 0.0;
	matrix[1][1] = 0.0;
	matrix[1][2] = -1.0;
	matrix[2][0] = 0.0;
	matrix[2][1] = 1.0;
	matrix[2][2] = 0.0;
}
