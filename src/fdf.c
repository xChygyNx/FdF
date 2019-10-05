/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:50:53 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/05 12:29:26 by astripeb         ###   ########.fr       */
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
	ft_fdf(fdf);
	free_fdf(&fdf);
	free(map);
	close(fd);
	return (0);
}

/*
int		main(int argc, char **argv)
{
	float	**m1;
	float	**m2;

	m1 = matrix_orto();
	m2 = matrix_z(0.523599);
	print_matrix(m1);
	print_matrix(m2);
	m1 = multiplication(m1, m2);
	print_matrix(m1);
	return (0);
}
*/
