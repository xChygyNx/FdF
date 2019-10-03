/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_old.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:33:57 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/03 21:50:20 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
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

void    		draw_line(t_fdf *fdf, t_vector a, t_vector b)
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
*/

static void		draw_along_x(t_fdf *fdf, t_vector a, t_delta delta)
{
	int d;
	int x;
	int y;

	x = a.x;
	y = a.y;
	d = -delta.length_x;
	++delta.length;
	while (delta.length--)
	{
		pixel_put_to_str(fdf->mlx_ptr, fdf->win_ptr, x, y, a.c.color);
		x += delta.dx;
		d += 2 * delta.length_y;
		if (d > 0)
		{
			d -= 2 * delta.length_x;
			y += delta.dy;
		}
	}
}

static void		draw_along_y(t_fdf *fdf, t_vector a, t_delta delta)
{
	int d;
	int x;
	int y;

	x = a.x;
	y = a.y;
	d = -delta.length_y;
	++delta.length;
	while (delta.length--)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, a.c.color);
		y += delta.dy;
		d += 2 * delta.length_x;
		if (d > 0)
		{
			d -= 2 * delta.length_y;
			x += delta.dx;
		}
	}
}

void			draw_line(t_fdf *fdf, t_vector a, t_vector b)
{
	t_delta delta;

	delta.dx = (b.x - a.x >= 0 ? 1 : -1);
	delta.dy = (b.y - a.y >= 0 ? 1 : -1);
	delta.length_x = abs(b.x - a.x);
	delta.length_y = abs(b.y - a.y);
	delta.length = delta.length_x > delta.length_y ? delta.length_x : delta.length_y;
	if (delta.length == 0)
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, a.x, a.y, a.c.color);
	else
	{
		if (delta.length_y <= delta.length_x)
			draw_along_x(fdf, a, delta);
		else
			draw_along_y(fdf, a, delta);
	}
}
