/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 21:49:47 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/02 14:17:27 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		free_vector_map(t_vector ***map_to_del, int height, int width)
{
	int			i;
	int			j;
	t_vector	**map;

	i = 0;
	if (*map_to_del)
	{
		map = *map_to_del;
		while (i < height)
		{
			free(map[i]);
			++i;
		}
		*map_to_del = NULL;
	}
}

void		create_vector_map(t_fdf *fdf)
{
	char	**line;
	int		i;
	int		j;

	if (!(fdf->map = (t_vector**)malloc(sizeof(t_vector*) * fdf->height)))
		ft_exit(&fdf, MALLOC_FAILURE);
	i = 0;
	while (i < fdf->height)
	{
		if (!(fdf->map[i] = (t_vector*)malloc(sizeof(t_vector) * fdf->width)))
			ft_exit(&fdf, MALLOC_FAILURE);
		if (!(line = ft_strsplit(fdf->char_map[i], ' ')))
			ft_exit(&fdf, MALLOC_FAILURE);
		j = 0;
		while (j < fdf->width)
		{
			fdf->map[i][j].x = i;
			fdf->map[i][j].y = j;
			point_height_color(i, j, line[j], fdf);
			++j;
		}
		ft_free_arr(line);
		++i;
	}
}

void		ft_print_vector_map(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			ft_printf("[%.f, %.f, %.f, %d] ",\
			fdf->map[i][j].x, fdf->map[i][j].y, fdf->map[i][j].z, fdf->map[i][j].c.color);
			++j;
		}
		ft_printf("\n");
		++i;
	}
}
