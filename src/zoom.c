/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 10:55:25 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/07 11:50:31 by pcredibl         ###   ########.fr       */
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
	int				i;
	int				j;

	fdf->view->zoom = keycode == MAIN_PAD_PLUS ?\
		fdf->view->zoom * zoom : fdf->view->zoom / zoom;
	center = find_center(fdf);
	i = 0;
	fdf->view->off_x *= zoom;
	fdf->view->off_y *= zoom;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			fdf->cur_map[i][j].x += (fdf->cur_map[i][j].x - center.x) * fdf->view->zoom;
			fdf->cur_map[i][j].y += (fdf->cur_map[i][j].y - center.y) * fdf->view->zoom;
			fdf->cur_map[i][j].z += (fdf->cur_map[i][j].z - center.z) * fdf->view->zoom;
			j++;
		}
		i++;
	}
}
