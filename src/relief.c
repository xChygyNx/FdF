/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relief.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 14:47:35 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/05 15:50:16 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	max_height(t_fdf *fdf)
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

static int	*create_height_arr(t_fdf *fdf)
{
	int		i;
	int		j;
	int		*height_arr;
	
	height_arr = (int*)malloc(sizeof(int) * max_height(fdf) + 1);
	ft_bzero((void*)height_arr, (size_t)max_height(fdf + 1));
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
	free(height_arr);
	return(height_arr);
}

static int	average_height(t_fdf *fdf)
{
	int		var_heights_count;
	int		*height_arr;
	int		most_frequently_height;
	int		same_heights_count;

	height_arr = create_height_arr(fdf);
	var_heights_count = max_height(fdf) + 2;
	same_heights_count = fdf->map[0][0].z;
	while (var_heights_count--)
	{
		if (height_arr[var_heights_count - 1] > same_heights_count)
		{
			same_heights_count = height_arr[var_heights_count - 1];
			most_frequently_height = var_heights_count - 1;
		}
	}
	return(most_frequently_height);
}

void	change_relief(t_fdf *fdf, int dif)
{
	int			ah;
	static int	k;

	ah = average_height(fdf);


}