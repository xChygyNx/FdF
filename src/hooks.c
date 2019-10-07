/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 16:59:40 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/07 15:41:30 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int key_code, void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf*)param;
	ft_bzero(fdf->img_str, fdf->size_line * WIN_HEIGHT);
	if (key_code == NUM_PAD_2)
		change_matrix(fdf, -0.1, AXIS_X);
	else if (key_code == NUM_PAD_8)
		change_matrix(fdf, 0.1, AXIS_X);
	else if (key_code == NUM_PAD_4)
		change_matrix(fdf, -0.1, AXIS_Y);
	else if (key_code == NUM_PAD_6)
		change_matrix(fdf, 0.1, AXIS_Y);
	else if (key_code == NUM_PAD_1 || key_code == NUM_PAD_7)
		change_matrix(fdf, -0.1, AXIS_Z);
	else if (key_code == NUM_PAD_3 || key_code == NUM_PAD_9)
		change_matrix(fdf, 0.1, AXIS_Z);
	else if (key_code == MAIN_PAD_I || key_code == NUM_PAD_DIV)
		isometric(fdf);
	else if (key_code == MAIN_PAD_O  || key_code == NUM_PAD_0)
		flatten(fdf);
	else if (key_code == ARROW_LEFT)
		fdf->view->off_x -= 10;
	else if (key_code == ARROW_RIGHT)
		fdf->view->off_x += 10;
	else if (key_code == ARROW_UP)
		fdf->view->off_y -= 10;
	else if (key_code == ARROW_DOWN)
		fdf->view->off_y += 10;
	else if (key_code == MAIN_PAD_PLUS)
		fdf->view->zoom += 0.25;
	else if (key_code == MAIN_PAD_MINUS)
		fdf->view->zoom -= 0.25;
	else if (key_code == NUM_PAD_MINUS)
		change_relief(fdf, -3);
	else if (key_code == NUM_PAD_PLUS)
		change_relief(fdf, 3);
	else if (key_code == MAIN_PAD_ESC)
		exit(0);
	view(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, IDENTATION, 0);
	ft_printf("key %d\n", key_code);
	return (42);
}
