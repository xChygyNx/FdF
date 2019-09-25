/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 21:49:47 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/26 00:24:45 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
t_vector 	*create_one_vector(int x, int y, int z, int color)
{
	t_vector *vector;

	if (!(vector = (t_vector*)malloc(sizeof(vector))))
		return (NULL);
	vector->x = x * 1.0;
	vector->y = y * 1.0;
	vector->z = z * 1.0;
	vector->color = color;
	return (vector);
}
*/

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
			fdf->map[i][j].z = ft_atoi(line[j]);
			fdf->map[i][j].color = 0;
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
			fdf->map[i][j].x, fdf->map[i][j].y, fdf->map[i][j].z, fdf->map[i][j].color);
			++j;
		}
		ft_printf("\n");
		++i;
	}
}
