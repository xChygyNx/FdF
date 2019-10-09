/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 16:59:40 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/09 14:23:02 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	define_area(int x, int y)
{
	if (x < 950 && y < 500)
		return (7);
	if (x > 949 && x < 1900 && y < 500)
		return (8);
	if (x > 1899 && y < 500)
		return (9);
	if (x < 950 && y > 499 && y < 1000)
		return (4);
	if (x > 949 && x < 1900 && y > 499 && y < 1000)
		return (5);
	if (x > 1899 && y > 499 && y < 1000)
		return (6);
	if (x < 950 && y > 999)
		return (1);
	if (x > 949 && x < 1900 && y > 999)
		return (2);
	if (x > 1899 && y > 999)
		return (3);
	else
		exit(ft_fprintf(2, "Click it is not clear where"));
	
}	

static int	close_window(void *param)
{
	(void)param;
	exit(ft_fprintf(2, "You click on 'X'\n"));
}

int		mouse_hook(int button, int x, int y, void *param)
{
	int		area;
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	//mlx_hook(fdf->win_ptr, 17, 0, (int (*)())exit, (void*) fdf);
	ft_bzero(fdf->img_str, fdf->size_line * IMG_HEIGHT);
	area = define_area(x, y);
	button == MOUSE_SCROLL_UP ? fdf->view->zoom += 0.25 : 0;
	button == MOUSE_SCROLL_DOWN ? fdf->view->zoom -= 0.25 : 0;
	button == MOUSE_LEFT_BUTTON && area == 1 ? change_matrix(fdf, -0.1, AXIS_Z) : 0;
	button == MOUSE_LEFT_BUTTON && area == 2 ? change_matrix(fdf, -0.1, AXIS_X) : 0;
	button == MOUSE_LEFT_BUTTON && area == 3 ? change_matrix(fdf, 0.1, AXIS_Z) : 0;
	button == MOUSE_LEFT_BUTTON && area == 4 ? change_matrix(fdf, -0.1, AXIS_Y) : 0;
	button == MOUSE_LEFT_BUTTON && area == 6 ? change_matrix(fdf, 0.1, AXIS_Y) : 0;
	button == MOUSE_LEFT_BUTTON && area == 7 ? change_matrix(fdf, -0.1, AXIS_Z) : 0;
	button == MOUSE_LEFT_BUTTON && area == 8 ? change_matrix(fdf, 0.1, AXIS_Z) : 0;
	button == MOUSE_LEFT_BUTTON && area == 9 ? change_matrix(fdf, 0.1, AXIS_Z) : 0;
	view(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, INDENT, 0);
	ft_printf("button = %d, x = %d, y = %d, area = %d\n", button, x, y, area);
	return (21);
}

int		key_hook(int key_code, void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf*)param;
	ft_bzero(fdf->img_str, fdf->size_line * IMG_HEIGHT);
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
		fdf->view->relief -= 0.25;
	else if (key_code == NUM_PAD_PLUS)
		fdf->view->relief += 0.25;
	else if (key_code == MAIN_PAD_ESC)
		exit(0);
	view(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, INDENT, 0);
	ft_printf("key %d\n", key_code);
	return (42);
}
