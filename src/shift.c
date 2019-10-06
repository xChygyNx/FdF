/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 21:30:21 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/06 18:50:21 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	shift_x_y(t_fdf *fdf, int offset_x, int offset_y)
{
	int		i;
	int		j;

	i = 0;
	fdf->view->offset_x += offset_x;
	fdf->view->offset_y += offset_y;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			fdf->cur_map[i][j].x = fdf->map[i][j].x + fdf->view->offset_x;
			fdf->cur_map[i][j].y = fdf->map[i][j].y + fdf->view->offset_y;
			j++;
		}
		i++;
	}
}
