/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:17:21 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/10 20:26:21 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	auto_color(t_fdf *fdf)
{
	int		min_h;
	int		max_h;
	int		i;
	int		j;
	unsigned char	color_h;
	
	min_h = min_height(fdf);
	max_h = max_height(fdf);
	i = -1;
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
		{
			color_h = 63 + 192 * (float)(fdf->map[i][j].z - min_h) / (max_h - min_h);
			fdf->map[i][j].c.t_rgb.red = color_h;
			fdf->map[i][j].c.t_rgb.green = color_h;
			fdf->map[i][j].c.t_rgb.blue = 0xFF;
		}
	}
}
