/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:41:56 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/08 14:38:44 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	pixel_put_to_str(t_fdf *fdf, int x, int y, unsigned int color)
{
	int i;

	if ((x >= 0 && x < IMG_WIDTH) && (y >= 0 && y < IMG_HEIGHT))
	{
		i = y * fdf->size_line + x * 4;
		fdf->img_str[i] = color & 0xFF;
		fdf->img_str[++i] = color >> 8 & 0xFF;
		fdf->img_str[++i] = color >> 16 & 0xFF;
		//ft_printf("red = %lu, green = %lu, blue = %lu\n", fdf->img_str[i - 2], fdf->img_str[i - 1], fdf->img_str[i]);
	}
}

static void	draw_along_x(t_fdf *fdf, t_vector a, t_vector b, t_delta delta)
{
	int d;
	int x;
	int y;
	unsigned int	color;

	x = a.x;
	y = a.y;
	d = -delta.length_x;
	++delta.length;
	while (delta.length--)
	{
		color = get_color(a, b, delta.length, 'x');
		//ft_printf("color = %lu\n", color);
		pixel_put_to_str(fdf, x, y, color);
		x += delta.dx;
		d += 2 * delta.length_y;
		if (d > 0)
		{
			d -= 2 * delta.length_x;
			y += delta.dy;
		}
	}
}

static void	draw_along_y(t_fdf *fdf, t_vector a, t_vector b, t_delta delta)
{
	int d;
	int x;
	int y;
	unsigned int	color;

	x = a.x;
	y = a.y;
	d = -delta.length_y;
	++delta.length;
	while (delta.length--)
	{
		color = get_color(a, b, delta.length, 'y');
		//ft_printf("color = %lu\n", color);
		pixel_put_to_str(fdf, x, y, color);
		y += delta.dy;
		d += 2 * delta.length_x;
		if (d > 0)
		{
			d -= 2 * delta.length_y;
			x += delta.dx;
		}
	}
}

void		draw_line(t_fdf *fdf, t_vector a, t_vector b)
{
	t_delta delta;
	//t_color	*colors;

	delta.dx = (b.x - a.x >= 0 ? 1 : -1);
	delta.dy = (b.y - a.y >= 0 ? 1 : -1);
	delta.length_x = abs(b.x - a.x);
	delta.length_y = abs(b.y - a.y);
	delta.length = delta.length_x > delta.length_y ?\
	delta.length_x : delta.length_y;
	//colors = gradient(a, b, delta.length);
	if (delta.length == 0)
		pixel_put_to_str(fdf, a.x, a.y, a.c.color);
	else
	{
		if (delta.length_y <= delta.length_x)
			draw_along_x(fdf, a, b, delta);
		else
			draw_along_y(fdf, a, b, delta);
	}
	//free(colors);
}
