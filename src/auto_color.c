/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:17:21 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/11 19:33:58 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	mix_colors(t_fdf *fdf)
{
	int		i;
	int		j;
	static char	style;

	style++;
	i = -1;
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
		{
			fdf->cur_map[i][j].c.t_rgb.red = mix_red(i, j, fdf, style % 7);
			fdf->cur_map[i][j].c.t_rgb.green = mix_green(i, j, fdf, style % 7);
			fdf->cur_map[i][j].c.t_rgb.blue = mix_blue(i, j, fdf, style % 7);
		}
	}
}

static void	gradient_colors(int min_h, int max_h, t_fdf *fdf)
{
	int		i;
	int		j;
	static char style;

	style++;
	i = -1;
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
		{
			fdf->cur_map[i][j].c.t_rgb.red = gradient_red(min_h, max_h,\
			fdf->map[i][j].z, style % 7);
			fdf->cur_map[i][j].c.t_rgb.green = gradient_green(min_h, max_h,\
			fdf->map[i][j].z, style % 7);
			fdf->cur_map[i][j].c.t_rgb.blue = gradient_blue(min_h, max_h,\
			fdf->map[i][j].z, style % 7);
		}
	}
}

void	auto_color(t_fdf *fdf)
{
	int		min_h;
	int		max_h;
	//int		dif_h;
	//int		i;
	//int		j;
	//unsigned char	color_h;

	min_h = min_height(fdf);
	max_h = max_height(fdf);
	fdf->view->change_color = 0;
	//ft_printf("In auto color\n");
	//dif_h = max_height(fdf) - min_height(fdf);
	if (fdf->auto_color)
		gradient_colors(min_h, max_h, fdf);
	else
		mix_colors(fdf);

}
