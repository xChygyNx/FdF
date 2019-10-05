/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 10:55:25 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/05 15:29:13 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector	find_center(t_fdf *fdf)
{
	int		i;
	int		j;

	i = fdf->width / 2;
	j = fdf->height / 2;
	return (fdf->map[i][j]);
}

void		zoom(t_fdf *fdf, int keycode, double zoom)
{
	t_vector		center;
	static double	cur_zoom = 1.0;
	int				i;
	int				j;

	cur_zoom = keycode == MAIN_PAD_PLUS ? cur_zoom * zoom : cur_zoom / zoom;
	center = find_center(fdf);
	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			fdf->cur_map[i][j].x = fdf->map[i][j].x * cur_zoom;
			fdf->cur_map[i][j].y = fdf->map[i][j].y * cur_zoom;
			fdf->cur_map[i][j].z = fdf->map[i][j].z * cur_zoom;
			j++;
		}
		i++;
	}
}
