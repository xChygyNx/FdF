/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 22:47:57 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/26 00:14:14 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pre_validation(t_fdf *fdf, char *map)
{
	int		i;
	char	**line;

	if (!(fdf->char_map = ft_strsplit(map, '\n')))
		ft_exit(&fdf, MALLOC_FAILURE);
	fdf->height = ft_len_arr(fdf->char_map);
	if (!(line = ft_strsplit(fdf->char_map[0], ' ')))
		ft_exit(&fdf, MALLOC_FAILURE);
	fdf->width = ft_len_arr(line);
	ft_free_arr(line);
}
