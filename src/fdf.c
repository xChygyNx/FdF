/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:50:53 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/04 12:40:12 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*map;
	t_fdf	*fdf;

	argc != 2 ? ft_exit(NULL, USAGE) : 0;
	if ((fd = open(argv[1], O_RDONLY)) < 1)
		ft_exit(NULL, 0);
	fdf = create_fdf();
	if (!(map = read_from_file_to_var(fd)))
		ft_exit(NULL, MALLOC_FAILURE);
	create_vector_map(fdf, map);
	initialize(fdf);
	draw_image(fdf);
	/*sleep(3);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);*/
	free_fdf(&fdf);
	free(map);
	close(fd);
	return (0);
}
