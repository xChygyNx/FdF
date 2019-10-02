/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:51:07 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/02 23:17:56 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libftprintf.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>

# define WIN_WIDTH 1280
# define WIN_HEIGHT 1024
# define MARGIN_FROM_FRAME 150

# define USAGE  100
# define LINE_LENGTHS 101
# define INVALID_HEIGHT 102
# define INVALID_COLOR 103

enum				e_bool
{
	FALSE,
	TRUE
};

typedef union		u_color
{
	struct			s_rgb
	{
		unsigned char	blue:8;
		unsigned char	green:8;
		unsigned char	red:8;
	}				t_rgb;
	unsigned int	color;
}					t_color;

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
	union u_color	c;
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

void				free_vector_map(t_vector ***map_to_del, int height,\
					int width);

void				create_vector_map(t_fdf *fdf, char *char_map);

void				point_height_color(t_fdf *fdf, int x, int y, char *point);

void				create_window(t_fdf *fdf);

void    			draw_line(t_fdf *fdf, int x1, int y1, int x2, int y2);

void				ft_print_vector_map(t_fdf *fdf);

#endif
