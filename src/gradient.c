/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:13:38 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/07 20:58:58 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	null_color(t_color *tab, int len)
{
	int		i;

	i = 0;
	while (i < len)
		{
			tab[i].t_rgb.red = 0;
			tab[i].t_rgb.green = 0;
			tab[i].t_rgb.blue = 0;
			tab[i].color = 0;
			i++;
		}
}

static void	fill_color(t_color *colors, float dr, float dg, float db)
{
	float	red;
	float	green;
	float	blue;
	int		i;

	i = 0;
	while (!colors[i].color)
		i++;
	red = colors[i].t_rgb.red;
	green = colors[i].t_rgb.green;
	blue = colors[i].t_rgb.blue;
	while (i)
	{
		red -= dr;
		green -= dg;
		blue -= db;
		colors[i - 1].t_rgb.red = red;
		colors[i - 1].t_rgb.green = green;
		colors[i - 1].t_rgb.blue = blue;
		i--;
	}
}

t_color	*gradient(t_vector a, t_vector b, int len)
{
	t_color		*colors;
	float		dr;
	float		dg;
	float		db;

	colors = (t_color*)malloc(sizeof(t_color) * len);
	dr = ((float)(a.c.t_rgb.red - b.c.t_rgb.red) / len);
	dg = ((float)(a.c.t_rgb.green - b.c.t_rgb.green) / len);
	db = ((float)(a.c.t_rgb.blue - b.c.t_rgb.blue) / len);
	null_color(colors, len);
	colors[--len] = b.c;
	fill_color(colors, dr, dg, db);
	colors[0] = a.c;
	return (colors);
}
