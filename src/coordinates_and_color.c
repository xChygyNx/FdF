/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates_and_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 12:59:55 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/03 13:01:16 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	point_color(t_fdf *fdf, char *color16)
{
	int		color;

	if (!ft_strncmp(color16, "0x", 2) || !ft_strncmp(color16, "0X", 2))
	{
		color = ft_atoi_base(&color16[2], 16);
		if (color < 0)
			ft_exit(&fdf, INVALID_COLOR);
	}
	else
		ft_exit(&fdf, INVALID_COLOR);
	return (color);
}

static int	ft_atoi_fdf(t_fdf *fdf, char *str)
{
	long int		nb;
	int				flag;

	nb = 0;
	flag = 0;
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
	return (nb);
}

void	point_height_color(t_fdf *fdf, int i, int j, char *point)
{
	char	**hex_color;

	if (ft_strchr(point, ','))
	{
		if (!(hex_color = ft_strsplit(point, ',')))
			ft_exit(&fdf, MALLOC_FAILURE);
		fdf->map[i][j].z = ft_atoi_fdf(fdf, hex_color[0]);
		fdf->map[i][j].c.color = point_color(fdf, hex_color[1]);
		ft_free_arr(hex_color);
	}
	else
	{
		fdf->map[i][j].z = ft_atoi_fdf(fdf, point);
		fdf->map[i][j].c.color = 0xFFFFFF;
	}
	//Перенес в point_color, потому что fdf->map.c.color unsigned
	//оно всегда не отрицательное
	//if (fdf->map[i][j].c.color < 0)
	//	ft_exit(&fdf, INVALID_COLOR);
	fdf->map[i][j].x = j;
	fdf->map[i][j].y = i;
}
