/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates_and_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 12:59:55 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/12 11:53:16 by astripeb         ###   ########.fr       */
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
	int		nbr;
	char	*nbr_s;

	nbr = ft_atoi(str);
	if (!(nbr_s = ft_itoa(nbr)))
		ft_exit(&fdf, MALLOC_FAILURE);
	if (ft_strlen(nbr_s) != ft_strlen(str))
		ft_exit(&fdf, INVALID_INT);
	free(nbr_s);
	return (nbr);
}

void		point_height_color(t_fdf *fdf, int i, int j, char *point)
{
	char	**hex_color;

	if (ft_strchr(point, ','))
	{
		if (!(hex_color = ft_strsplit(point, ',')))
			ft_exit(&fdf, MALLOC_FAILURE);
		fdf->map[i][j].z = ft_atoi_fdf(fdf, hex_color[0]);
		fdf->map[i][j].c.color = point_color(fdf, hex_color[1]);
		fdf->colorful = 1;
		ft_free_arr(hex_color);
	}
	else
	{
		fdf->map[i][j].z = ft_atoi_fdf(fdf, point);
		fdf->map[i][j].c.color = 0xFFFFFF;
	}
	fdf->map[i][j].x = j - fdf->width / 2;
	fdf->map[i][j].y = i - fdf->height / 2;
}
