/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 22:10:22 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/03 20:13:24 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf		*create_fdf(void)
{
	t_fdf	*fdf;

	if (!(fdf = (t_fdf*)malloc(sizeof(t_fdf))))
		ft_exit(NULL, MALLOC_FAILURE);
	//fdf->mlx_ptr = NULL;
	if (!(fdf->mlx_ptr = mlx_init()))
		ft_exit(&fdf, MALLOC_FAILURE);
	fdf->win_ptr = NULL;
	fdf->img_ptr = NULL;
	//fdf->img_arr = NULL;
	fdf->size_line = 0;
	fdf->char_map = NULL;
	fdf->map = NULL;
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
			fdf->win_ptr ? mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr) : 0;
			fdf->img_ptr ? mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr) : 0;
			ft_free_arr(fdf->char_map);
			free_vector_map(&fdf->map, fdf->height, fdf->width);
			free(*fdf_to_del);
		}
		*fdf_to_del = NULL;
	}
}
