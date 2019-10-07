/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:41:56 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/07 22:16:27 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	pixel_put_to_str(t_fdf *fdf, int x, int y, t_color color)
{
	int i;

	if ((x >= 0 && x < IMG_WIDTH) && (y >= 0 && y < IMG_HEIGHT))
	{
		i = y * fdf->size_line + x * 4;
		fdf->img_str[i] = color.t_rgb.blue;
		fdf->img_str[++i] = color.t_rgb.green;
		fdf->img_str[++i] = color.t_rgb.red;
	}
}

static void	draw_along_x(t_fdf *fdf, t_vector a, t_delta delta, t_color *colors)
{
	int d;
	int x;
	int y;
	unsigned int	*color;

	x = a.x;
	y = a.y;
	d = -delta.length_x;
	++delta.length;
	while (delta.length--)
	{
		pixel_put_to_str(fdf, x, y, colors[delta.length - 1]);
		x += delta.dx;
		d += 2 * delta.length_y;
		if (d > 0)
		{
			d -= 2 * delta.length_x;
			y += delta.dy;
		}
	}
}

static void	draw_along_y(t_fdf *fdf, t_vector a, t_delta delta, t_color *colors)
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
		pixel_put_to_str(fdf, x, y, colors[delta.length - 1]);
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
	t_color	*colors;

	delta.dx = (b.x - a.x >= 0 ? 1 : -1);
	delta.dy = (b.y - a.y >= 0 ? 1 : -1);
	delta.length_x = abs(b.x - a.x);
	delta.length_y = abs(b.y - a.y);
	delta.length = delta.length_x > delta.length_y ?\
	delta.length_x : delta.length_y;
	colors = gradient(a, b, delta.length);
	if (delta.length == 0)
		pixel_put_to_str(fdf, a.x, a.y, a.c);
	else
	{
		if (delta.length_y <= delta.length_x)
			draw_along_x(fdf, a, delta, colors);
		else
			draw_along_y(fdf, a, delta, colors);
	}
	free(colors);
}
