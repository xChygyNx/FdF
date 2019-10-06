/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 16:59:40 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/06 19:08:56 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int key_code, void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf*)param;
	ft_bzero(fdf->img_str, fdf->size_line * WIN_HEIGHT);
	if (key_code == MAIN_PAD_A)
	{
		fdf->view->matrix = change_matrix(fdf->view->matrix, 0.1, AXIS_X);
		rotate(fdf, fdf->view->matrix);
	}
	else if (key_code == MAIN_PAD_S)
	{
		fdf->view->matrix = change_matrix(fdf->view->matrix, -0.1, AXIS_X);
		rotate(fdf, fdf->view->matrix);
	}
	else if (key_code == MAIN_PAD_D)
	{
		fdf->view->matrix = change_matrix(fdf->view->matrix, 0.1, AXIS_Y);
		rotate(fdf, fdf->view->matrix);
	}
	else if (key_code == MAIN_PAD_F)
	{
		fdf->view->matrix = change_matrix(fdf->view->matrix, -0.1, AXIS_Y);
		rotate(fdf, fdf->view->matrix);
	}
	else if (key_code == MAIN_PAD_G)
	{
		fdf->view->matrix = change_matrix(fdf->view->matrix, 0.1, AXIS_Z);
		rotate(fdf, fdf->view->matrix);
	}
	else if (key_code == MAIN_PAD_H)
	{
		fdf->view->matrix = change_matrix(fdf->view->matrix, -0.1, AXIS_Z);
		rotate(fdf, fdf->view->matrix);
	}
	else if (key_code == MAIN_PAD_I)
		isometric(fdf);
	else if (key_code == MAIN_PAD_O)
		flatten(fdf);
	else if (key_code == ARROW_LEFT)
		fdf->view->off_x -= 10;
	else if (key_code == ARROW_RIGHT)
		fdf->view->off_x += 10;
	else if (key_code == ARROW_UP)
		fdf->view->off_y -= 10;
	else if (key_code == ARROW_DOWN)
		fdf->view->off_y += 10;
	else if (key_code == MAIN_PAD_ESC)
		exit(0);
	else if (key_code == MAIN_PAD_PLUS || key_code == MAIN_PAD_MINUS)
		zoom (fdf, key_code, 1.1);
	draw_image(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	ft_printf("key %d\n", key_code);
	return (42);
}
