/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:13:56 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/04 20:23:03 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rotate_x(t_fdf *fdf, float rad)
{
	float	a;
	float	b;
	int		i;
	int		j;

	a = cos(rad);
	b = -sin(rad);
	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			fdf->map[i][j].y = (fdf->map[i][j].y * a + fdf->map[i][j].z * b) + 1;
			fdf->map[i][j].z = (fdf->map[i][j].y * -b + fdf->map[i][j].z * a) + 1;
			++j;
		}
		++i;
	}
}

void		rotate_y(t_fdf *fdf, float rad)
{
	float	a;
	float	b;
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
			fdf->map[i][j].x = fdf->map[i][j].x * a + fdf->map[i][j].z * b;
			fdf->map[i][j].z = fdf->map[i][j].x * -b + fdf->map[i][j].z * a;
			++j;
		}
		++i;
	}
}

void		rotate_z(t_fdf *fdf, float rad)
{
	float	a;
	float	b;
	int		i;
	int		j;

	a = cos(rad);
	b = -sin(rad);
	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			fdf->map[i][j].x = fdf->map[i][j].x * a + fdf->map[i][j].y * b + 1;
			fdf->map[i][j].y = fdf->map[i][j].x * -b + fdf->map[i][j].y * a + 1;
			++j;
		}
		++i;
	}
}
