/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:51:07 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/05 10:27:06 by astripeb         ###   ########.fr       */
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

# define WIN_WIDTH 1280
# define WIN_HEIGHT 1024
# define MARGIN_FROM_FRAME 100
# define IDENTATION 100

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
	int				x;
	int				y;
	int				z;
	union u_color	c;
}					t_vector;

typedef struct		s_fdf
{
	void			*mlx_ptr;	//идентификатор соединения с X-server
	void			*win_ptr;	//узакатель на окно
	void			*img_ptr;	//указатель на изображение
	char			*img_str;	//строка-изображение len(size_line * height)
	int				size_line;	//длина строки строки (WIN_WIDTH * bit_per_pixel / 8)
	int				width;		//ширина карты (нужна для итерации)
	int				height;		//высота карты (нужна для итерации)
	struct s_vector	**map;		//двумерный массив векторов
	struct s_vector	**cur_map;
	int				bpp;		//бит на пиксель
	double			zoom;		//кратность увеличения/уменьшения
	int				endian;		//порядок битов
	char			**char_map;
}					t_fdf;

typedef struct 		s_delta
{
	int				dx;
	int				dy;
	int				length_x;
	int				length_y;
	int				length;
}					t_delta;


void				ft_exit(t_fdf **fdf, int err);

t_fdf				*create_fdf(void);

void				free_fdf(t_fdf **fdf_to_del);

void				free_vector_map(t_vector ***map_to_del, int height,\
					int width);

void				create_vector_map(t_fdf *fdf, char *char_map);

void				point_height_color(t_fdf *fdf, int x, int y, char *point);

void				create_window(t_fdf *fdf);

void				create_image(t_fdf *fdf);

void    			draw_line(t_fdf *fdf, t_vector a, t_vector b);

void				initialize(t_fdf *fdf);

void				pixel_put_to_str(t_fdf *fdf, int x, int y, t_color color);

void				draw_image(t_fdf *fdf);

void				rotate_x(t_fdf *fdf, double rad);

void				rotate_z(t_fdf *fdf, double rad);

void				rotate_y(t_fdf *fdf, double rad);

void				ft_fdf(t_fdf *fdf);

void				ft_print_vector_map(t_fdf *fdf);

void				shift_x_y(t_fdf *fdf, int offset_x, int offset_y);

void				shift_z(t_fdf *fdf, int z);

/*
**  HOOOOOOOOOKS
*/

int					key_hook(int key_code, void *param);

#endif
