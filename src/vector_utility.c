/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 12:59:55 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/02 20:52:47 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	exist_comma(char *s)
{
	while (*s)
	{
		if (*s == ',')
			return (1);
		s++;
	}
	return (0);
}

static int	point_color(t_fdf *fdf, char *color16)
{
	char	*rgb;
	int		color;
	//char	*temp;

	if (!(rgb = ft_strsub(color16, 2, ft_strlen(color16) - 2)))
		ft_exit(&fdf, MALLOC_FAILURE);
	/*if (!(ft_strcmp(rgb, "FFFFFF")))
	{
		fdf->map[x][y].r = 255;
		fdf->map[x][y].g = 255;
		fdf->map[x][y].b = 255;
		return ;
	}
	i = 0;
	while (i < 3)
	{*/
	//ft_printf("color16 = %s, len = %d\n", color16, ft_strlen(color16));
	//temp = ft_strsub(color16, 2, 6);
	//ft_printf("strsub = %s\n", temp);
	color = ft_atoi_base_fdf(rgb, 16);
	if (color < 0)
		ft_exit(&fdf, INVALID_COLOR);
	//ft_printf("color16 = %s, color = %d     ", color16, color);
	//ft_printf("\n");
	return (color);
}

static int	ft_atoi_fdf(t_fdf *fdf, char *str)
{
	long int		nb;
	int				flag;

	nb = 0;
	flag = 0;
	//ft_printf("str = %s     ", str);
	while ((*str > 8 && *str < 14) || *str == 32)
		++str;
	if (*str == '+')
	{
		str++;
		flag = 1;
	}
	while (*str > 47 && *str < 58)
	{
		flag = 0;
		if ((nb > 214748363 && *str > '7') || nb > 214748364)
			ft_exit(&fdf, INVALID_HEIGHT);
		nb = nb * 10 + (*str++ - '0');
	}
	if (*str || flag)
		ft_exit(&fdf, INVALID_HEIGHT);
	//ft_printf("z = %d\n", nb);
	return (nb);
}

void	point_height_color(int x, int y, char *point, t_fdf *fdf)
{
	char	**hc;

	if (exist_comma(point))
	{
		if (!(hc = ft_strsplit(point, ',')))
			ft_exit(&fdf, MALLOC_FAILURE);
		//ft_printf("hc[1] = %s hc[2] = %s", hc[0], hc[1]);
		fdf->map[x][y].z = ft_atoi_fdf(fdf, hc[0]);
		fdf->map[x][y].c.color = point_color(fdf, hc[1]);		
		ft_printf("x = %d, y = %d, map.z = %.0f, map.red = %d, map.green = %d, map.blue =%d\n",\
			 x, y, fdf->map[x][y].z, fdf->map[x][y].c.t_rgb.red, fdf->map[x][y].c.t_rgb.green, fdf->map[x][y].c.t_rgb.blue);
	}
	else
	{
		fdf->map[x][y].z = ft_atoi_fdf(fdf, point);
		fdf->map[x][y].c.color = 0;
	}
	//ft_printf("height = %s, color = %s,  x = %d, y = %d\n", fdf->map[x][y].z, fdf->map[x][y].color, x, y);
}