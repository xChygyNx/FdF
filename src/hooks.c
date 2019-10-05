
#include "fdf.h"


int		key_hook(int key_code, void *param)
{
	t_fdf *fdf;
	float **matrix;

	fdf = (t_fdf*)param;
	if (key_code == MAIN_PAD_A)
	{
		fdf->view->matrix = change_matrix(fdf->view->matrix, 0.025, AXIS_X);
		rotate(fdf, fdf->view->matrix);
	}
	else if (key_code == MAIN_PAD_S)
	{
		fdf->view->matrix = change_matrix(fdf->view->matrix, -0.025, AXIS_X);
		rotate(fdf, fdf->view->matrix);
	}
	else if (key_code == 2)
	{
		fdf->view->matrix = change_matrix(fdf->view->matrix, 0.025, AXIS_Y);
		rotate(fdf, fdf->view->matrix);
	}
	else if (key_code == 3)
	{
		fdf->view->matrix = change_matrix(fdf->view->matrix, -0.025, AXIS_Y);
		rotate(fdf, fdf->view->matrix);
	}
	else if (key_code == 4)
	{
		fdf->view->matrix = change_matrix(fdf->view->matrix, 0.025, AXIS_Z);
		rotate(fdf, fdf->view->matrix);
	}
	else if (key_code == 5)
	{
		fdf->view->matrix = change_matrix(fdf->view->matrix, -0.025, AXIS_Z);
		rotate(fdf, fdf->view->matrix);
	}
	else if (key_code == 34)
		isometric(fdf);
	else if (key_code == 31)
		flatten(fdf);
	else if (key_code == ARROW_LEFT)
		shift_x_y(fdf, -10, 0);
	else if (key_code == ARROW_RIGHT)
		shift_x_y(fdf, 10, 0);
	else if (key_code == ARROW_UP)
		shift_x_y(fdf, 0, -10);
	else if (key_code == ARROW_DOWN)
		shift_x_y(fdf, 0, 10);
	else if (key_code == NUM_PAD_PLUS)
		shift_z(fdf, 555);
	else if (key_code == NUM_PAD_MINUS)
		shift_z(fdf, -555);
	else if (key_code == MAIN_PAD_ESC)
		exit(0);
	else if (key_code == MAIN_PAD_PLUS || key_code == MAIN_PAD_MINUS)
		zoom (fdf, key_code, 1.1);
	draw_image(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	ft_bzero(fdf->img_str, fdf->size_line * WIN_HEIGHT);
	ft_printf("key %d\n", key_code);
	return (42);
}
