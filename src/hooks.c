
#include "fdf.h"


int		key_hook(int key_code, void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf*)param;
	if (key_code == 0)
		rotate_z(fdf, 0.1);
	else if (key_code == 1)
		rotate_z(fdf, -0.1);
	else if (key_code == 123)
		shift_x(fdf, -10);
	else if (key_code == 124)
		shift_x(fdf, 10);
	else if (key_code == 126)
		shift_y(fdf, -10);
	else if (key_code == 125)
		shift_y(fdf, 10);
	draw_image(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	ft_bzero(fdf->img_str, fdf->size_line * WIN_HEIGHT);
	ft_printf("key %d\n", key_code);
	return (42);
}
