/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 22:10:22 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/04 21:40:44 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf		*create_fdf(void)
{
	t_fdf	*fdf;

	if (!(fdf = (t_fdf*)malloc(sizeof(t_fdf))))
		ft_exit(NULL, MALLOC_FAILURE);
	fdf->mlx_ptr = NULL;
	fdf->win_ptr = NULL;
	fdf->img_ptr = NULL;
	fdf->size_line = 0;
	fdf->char_map = NULL;
	fdf->map = NULL;
	fdf->cur_map = NULL;
	fdf->width = 0;
	fdf->height = 0;
	fdf->zoom = 0.0;
	fdf->bpp = 0;
	fdf->endian = 0;
	return (fdf);
}

void		free_fdf(t_fdf **fdf_to_del)
{
	t_fdf	*fdf;

	if (fdf_to_del)
	{
		fdf = *fdf_to_del;
		if (fdf)
		{
			fdf->img_ptr ? mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr) : 0;
			fdf->win_ptr ? mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr) : 0;
			fdf->mlx_ptr ? free(fdf->mlx_ptr) : 0;
			ft_free_arr(fdf->char_map);
			free_vector_map(&fdf->map, fdf->height, fdf->width);
			free_vector_map(&fdf->cur_map, fdf->height, fdf->width);
			free(*fdf_to_del);
		}
		*fdf_to_del = NULL;
	}
}
