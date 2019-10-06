/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:51:07 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/06 22:34:26 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libftprintf.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include "color.h"
# include "buttons.h"

# ifdef __linux__
	# define WIN_WIDTH 800
	# define WIN_HEIGHT 600
	# define MARGIN_FROM_FRAME 50
	# define IDENTATION 100
# else
	# define WIN_WIDTH 1920
	# define WIN_HEIGHT 1080
	# define MARGIN_FROM_FRAME 100
	# define IDENTATION 100
#endif

# define USAGE  100
# define LINE_LENGTHS 101
# define INVALID_HEIGHT 102
# define INVALID_COLOR 103

# define AXIS_X 7
# define AXIS_Y 8
# define AXIS_Z 9

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
	int				x;
	int				y;
	int				z;
	union u_color	c;
}					t_vector;

typedef struct 		s_delta
{
	int				dx;
	int				dy;
	int				length_x;
	int				length_y;
	int				length;
}					t_delta;

typedef struct		s_view
{
	int				off_x;		//смещение по X
	int				off_y;		//смещение по Y
	float			**matrix;	//матрица поворота
	float			zoom;		//кратность увеличения/уменьшения
}					t_view;

typedef struct		s_fdf
{
	char			**char_map;
	void			*mlx_ptr;	//идентификатор соединения с X-server
	void			*win_ptr;	//узакатель на окно
	void			*img_ptr;	//указатель на изображение
	char			*img_str;	//строка-изображение len(size_line * height)
	int				size_line;	//длина строки строки (WIN_WIDTH * bit_per_pixel / 8)
	int				width;		//ширина карты (нужна для итерации)
	int				height;		//высота карты (нужна для итерации)
	int				bpp;		//бит на пиксель
	int				endian;		//порядок битов
	struct s_vector	**map;		//исходный двумерный массив векторов
	struct s_vector	**cur_map;	//текущая карта
	struct s_view	*view;		//настройки текущего вид на карту
}					t_fdf;

void				ft_exit(t_fdf **fdf, int err);

/*
** CREATE FDF STRUCTURE
*/

t_fdf				*create_fdf(void);

t_view				*create_view(void);

void				free_fdf(t_fdf **fdf_to_del);

void				free_vector_map(t_vector ***map_to_del, int height,\
					int width);

void				create_vector_map(t_fdf *fdf, char *char_map);

void				point_height_color(t_fdf *fdf, int x, int y, char *point);

void				initialize(t_fdf *fdf);

/*
** DRAW FUNCTIONS
*/

void    			draw_line(t_fdf *fdf, t_vector a, t_vector b);

void				view(t_fdf *fdf);

/*
**  HOOOOOOOOOKS
*/

int					key_hook(int key_code, void *param);

void				ft_fdf(t_fdf *fdf);

/*
**  ACTIONS
*/

void				shift_x_y(t_fdf *fdf, int offset_x, int offset_y);

void				shift_z(t_fdf *fdf, int z);

void				zoom(t_fdf *fdf, int keycode, double zoom);

void				rotate(t_fdf *fdf, float **matrix);

void				isometric(t_fdf *fdf);

void				flatten(t_fdf *fdf);

void				apply_matrix2vector(t_vector *cur, t_vector *src,\
					float **mtx);

/*
**  WAKE UP NEO, MATRIX HAS YOU
*/

void				free_matrix(float ***matrix_to_del);

float				**create_matrix(void);

float				**matrix_x(float alpha);

float				**matrix_y(float alpha);

float				**matrix_z(float alpha);

float				**multiplication(float **cur, float **matrix);

float				**matrix_orto(void);

void				change_matrix(t_fdf *fdf, float alpha, char axis);

/*
**  UTILITY
*/

void				print_matrix(float **matrix);

#endif
