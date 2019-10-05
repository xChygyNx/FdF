/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:13:56 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/05 13:46:56 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	apply_matrix_to_vector(t_vector *cur, t_vector *src, float **mtx)
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
			apply_matrix_to_vector(&fdf->cur_map[i][j], &fdf->map[i][j], matrix);
			++j;
		}
		++i;
	}
}

void		isometric(t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			fdf->cur_map[i][j].x = (fdf->map[i][j].x - fdf->map[i][j].y) * cos(0.523599);
			fdf->cur_map[i][j].y = (fdf->map[i][j].x + fdf->map[i][j].y) * cos(0.523599) - fdf->map[i][j].z;
			++j;
		}
		++i;
	}
}


/*
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = -z + (previous_x + previous_y) * sin(0.523599);
*/
/*
void		rotate_y(t_fdf *fdf, double rad)
{
	double	a;
	double	b;
	int		i;
	int		j;

	a = cos(rad);
	b = sin(rad);
	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			fdf->cur_map[i][j].x = fdf->map[i][j].x * a + fdf->map[i][j].z * b;
			fdf->cur_map[i][j].z = -fdf->map[i][j].x * b + fdf->map[i][j].z * a;
			++j;
		}
		++i;
	}
}

void		rotate_z(t_fdf *fdf, double rad)
{
	double	a;
	double	b;
	int		i;
	int		j;

	a = cos(rad);
	b = sin(rad);
	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			fdf->cur_map[i][j].x = fdf->map[i][j].x * a - fdf->map[i][j].y * b;
			fdf->cur_map[i][j].y = fdf->map[i][j].x * b + fdf->map[i][j].y * a;
			++j;
		}
		++i;
	}
}
*/
