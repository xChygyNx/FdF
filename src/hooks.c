
#include "fdf.h"


int		key_hook(int key_code, void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf*)param;
	if (key_code == MAIN_PAD_A)
	{
		rotate_y(fdf, 0.785398);
		rotate_z(fdf, 0.523599);
	}
	else if (key_code == MAIN_PAD_S)
	{
		rotate_y(fdf, -0.785398);
		rotate_z(fdf, -0.523599);
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
	else if (key_code == MAIN_PAD_PLUS || key_code == MAIN_PAD_MINUS)
		zoom (fdf, key_code, 1.1);
	draw_image(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	ft_bzero(fdf->img_str, fdf->size_line * WIN_HEIGHT);
	ft_printf("key %d\n", key_code);
	return (42);
}
