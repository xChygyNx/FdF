/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:41:56 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/09 19:50:16 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_color	get_color(t_vector a, t_vector b, int cur, int len)
{
	float	coef;
	t_color	c;

	coef = (float)cur / len;
	c.t_rgb.red = (char)((1 - coef) * b.c.t_rgb.red + coef *\
	a.c.t_rgb.red);
	c.t_rgb.green = (char)((1 - coef) * b.c.t_rgb.green + coef *\
	a.c.t_rgb.green);
	c.t_rgb.blue = (char)((1 - coef) * b.c.t_rgb.blue + coef *\
	a.c.t_rgb.blue);
	return (c);
}

static void		pixel_put_to_str(t_fdf *fdf, int x, int y, t_color color)
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

static void		draw_along_x(t_fdf *fdf, t_vector a, t_vector b, t_delta delta)
{
	int		d;
	int		x;
	int		y;
	t_color	color;

	x = a.x;
	y = a.y;
	d = -delta.length_x;
	++delta.length;
	while (delta.length--)
	{
		color = get_color(a, b, delta.length, ft_abs(a.x - b.x));
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

static void		draw_along_y(t_fdf *fdf, t_vector a, t_vector b, t_delta delta)
{
	int		d;
	int		x;
	int		y;
	t_color	color;

	x = a.x;
	y = a.y;
	d = -delta.length_y;
	++delta.length;
	while (delta.length--)
	{
		color = get_color(a, b, delta.length, ft_abs(a.y - b.y));
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

void			draw_line(t_fdf *fdf, t_vector a, t_vector b)
{
	t_delta delta;

	delta.dx = (b.x - a.x >= 0 ? 1 : -1);
	delta.dy = (b.y - a.y >= 0 ? 1 : -1);
	delta.length_x = abs(b.x - a.x);
	delta.length_y = abs(b.y - a.y);
	delta.length = delta.length_x > delta.length_y ?\
	delta.length_x : delta.length_y;
	if (delta.length == 0)
		pixel_put_to_str(fdf, a.x, a.y, a.c);
	else
	{
		if (delta.length_y <= delta.length_x)
			draw_along_x(fdf, a, b, delta);
		else
			draw_along_y(fdf, a, b, delta);
	}
}
