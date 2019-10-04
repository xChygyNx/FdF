/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:13:56 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/04 21:41:54 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rotate_x(t_fdf *fdf, double rad)
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
			fdf->cur_map[i][j].y = fdf->map[i][j].y * a - fdf->map[i][j].z * b;
			fdf->cur_map[i][j].z = fdf->map[i][j].y * b + fdf->map[i][j].z * a;
			++j;
		}
		++i;
	}
}

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
