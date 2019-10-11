/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relief.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 14:47:35 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/11 21:36:25 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			max_height(t_fdf *fdf)
{
	int		i;
	int		j;
	int		max_height;

	max_height = -2147483648;
	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			if (fdf->map[i][j].z > max_height)
				max_height = fdf->map[i][j].z;
			j++;
		}
		i++;
	}
	return (max_height);
}

int			min_height(t_fdf *fdf)
{
	int		i;
	int		j;
	int		min_height;

	min_height = 2147483647;
	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			if (fdf->map[i][j].z < min_height)
				min_height = fdf->map[i][j].z;
			j++;
		}
		i++;
	}
	return (min_height);
}
