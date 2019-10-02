/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:33:57 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/03 00:13:08 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		steep(int *x1, int *y1, int *x2, int *y2)
{
	int		steep;

	steep = abs(*y1 - *y2) > abs(*x1 - *x2);
	if (steep)
	{
		ft_swap(x1, y1);
		ft_swap(x2, y2);
	}
	if (*x1 > *x2)
	{
		ft_swap(x1, x2);
		ft_swap(y1, y2);
	}
	return (steep);
}

void    		draw_line(t_fdf *fdf, int x1, int y1, int x2, int y2)
{
	int dx;
	int dy;
	int flag;
	int error;
	int ystep;

	flag = steep(&x1, &y1, &x2, &y2);
	dx = x2 - x1;
	dy = abs(y2 - y1);
	error = dx / 2;
	ystep = (y1 < y2) ? 1 : -1;
	while(x1 <= x2)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr,\
		flag ? y1 : x1, flag ? x1 : y1, 0xFFFFFF);
		error -= dy;
		if (error < 0)
		{
			y1 += ystep;
			error +=dx;
		}
		++x1;
	}
	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr,\
	flag ? y1 : x1, flag ? x1 : y1, 0xFFFFFF);
}
