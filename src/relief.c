/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relief.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 14:47:35 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/11 15:55:30 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	null_tab(int *tab, int size)
{
	while (size--)
		tab[size] = 0;
}

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

static int	*create_height_arr(t_fdf *fdf)
{
	int		i;
	int		j;
	int		*height_arr;
	height_arr = (int*)malloc(sizeof(int) * max_height(fdf) + 1);
	null_tab(height_arr, max_height(fdf) + 1);
	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			height_arr[fdf->map[i][j].z] += 1;
			j++;
		}
		i++;
	}
	return(height_arr);
}

int			average_height(t_fdf *fdf)
{
	int		var_heights_count;
	int		*height_arr;
	int		most_frequently_height;
	int		same_heights_count;

	height_arr = create_height_arr(fdf);
	var_heights_count = max_height(fdf) + 1;
	same_heights_count = 0;
	while (var_heights_count--)
	{
		if (height_arr[var_heights_count] > same_heights_count)
		{
			same_heights_count = height_arr[var_heights_count];
			most_frequently_height = var_heights_count;
		}
	}
	free(height_arr);
	return(most_frequently_height);
}

void		change_relief(t_fdf *fdf, float dif)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			fdf->cur_map[i][j].z += (fdf->map[i][j].z - fdf->ah) * dif;
			++j;
		}
		++i;
	}
}
