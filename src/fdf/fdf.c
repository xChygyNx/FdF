/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:50:53 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/26 00:14:55 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*map;
	t_fdf	*fdf;

	if (argc != 2)
		ft_exit(NULL, USAGE);
	if (!(fd = open(argv[1], O_RDONLY)))
		ft_exit(NULL, 0);
	fdf = create_fdf();
	if (!(map = read_from_file_to_var(fd)))
		ft_exit(NULL, MALLOC_FAILURE);
	pre_validation(fdf, map);
	create_vector_map(fdf);
	ft_print_vector_map(fdf);
	free_fdf(&fdf);
	free(map);
	close(fd);
	return (0);
}

/*
int		main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Privet, kak dela?");
	mlx_pixel_put(mlx_ptr, win_ptr, 0, 0, 0xFFFFFF);
	mlx_loop(mlx_ptr);
	win_ptr = NULL;
	return (0);
}
*/
