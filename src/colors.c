/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:21:24 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/08 16:29:37 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static unsigned int		color_construct (t_vector a, t_vector b, float coef)
{
	int		red;
	int		green;
	int		blue;

	red = (unsigned char)((1 - coef) * b.c.t_rgb.red + coef * a.c.t_rgb.red);
	green = (unsigned char)((1 - coef) * b.c.t_rgb. green\
		+ coef * a.c.t_rgb.green);
	blue = (unsigned char)((1 - coef) * b.c.t_rgb.blue + coef * a.c.t_rgb.blue);
	//ft_printf("a.red = %d, b.red = %d\n", a.c.t_rgb.red, b.c.t_rgb.red);
	//ft_printf("coef = %f, red = %d, green = %d, blue = %d, color = %d\n", coef, red, green, blue, (red << 16) | (green << 8) | blue);
	return (red << 16 | green << 8 | blue);
}

unsigned int	get_color (t_vector a, t_vector b, int cur, char axis)
{
	unsigned int	color;
	int		len;
	float	coef;

	len = axis == 'x' ? a.x - b.x : a.y - b.y;
	coef = (float)cur / len;
	color = color_construct(a, b, coef);
	//ft_printf("len = %d, cur = %d, coef = %f, color = %lu\n", len, cur, coef, color);
	return(color);
}