
#include "fdf.h"


int		key_hook(int key_code, void *param)
{
	t_fdf *fdf;
	float **matrix;

	fdf = (t_fdf*)param;
	if (key_code == MAIN_PAD_A)
	{
		fdf->matrix = change_matrix(fdf->matrix, 0.025, 2);
		rotate(fdf, fdf->matrix);
	}
	else if (key_code == MAIN_PAD_S)
	{
		fdf->matrix = change_matrix(fdf->matrix, -0.025, 2);
		rotate(fdf, fdf->matrix);
	}
	else if (key_code == 2)
	{
		fdf->matrix = change_matrix(fdf->matrix, 0.025, 1);
		rotate(fdf, fdf->matrix);
	}
	else if (key_code == 3)
	{
		fdf->matrix = change_matrix(fdf->matrix, -0.025, 1);
		rotate(fdf, fdf->matrix);
	}
	else if (key_code == 4)
	{
		fdf->matrix = change_matrix(fdf->matrix, 0.025, 0);
		rotate(fdf, fdf->matrix);
	}
	else if (key_code == 5)
	{
		fdf->matrix = change_matrix(fdf->matrix, -0.025, 0);
		rotate(fdf, fdf->matrix);
	}
	else if (key_code == 34)
	{
		isometric(fdf);
	}
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
	draw_image(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	ft_bzero(fdf->img_str, fdf->size_line * WIN_HEIGHT);
	ft_printf("key %d\n", key_code);
	return (42);
}
