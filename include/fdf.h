/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:51:07 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/30 21:48:31 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libftprintf.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>

# define WIN_HEIGHT 1080
# define WIN_WIDTH 1920

# define USAGE  100
# define LINE_LENGTHS 101

enum				e_bool
{
	FALSE,
	TRUE
};

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
	int				color;
}					t_vector;

typedef struct		s_fdf
{
	void			*mlx_ptr;	//идентификатор соединения с X-server
	void			*win_ptr;	//узакатель на созданное окно
	void			*img_ptr;	//указатель на изображение
	char			**char_map;
	int				width;		//ширина карты (нужна для итерации)
	int				height;		//высота карты (нужна для итерации)
	struct s_vector	**map;		//двумерный массив векторов
	double			zoom;		//кратность увеличения/уменьшения
}					t_fdf;


void				ft_exit(t_fdf **fdf, int err);

t_fdf				*create_fdf(void);

void				free_fdf(t_fdf **fdf_to_del);

void				pre_validation(t_fdf *fdf, char *map);

void				free_vector_map(t_vector ***map_to_del, int height,\
					int width);

//t_vector 			*create_one_vector(int x, int y, int z, int color);

void				create_vector_map(t_fdf *fdf);

void				ft_print_vector_map(t_fdf *fdf);

#endif
