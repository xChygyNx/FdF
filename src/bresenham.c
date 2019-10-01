/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:33:57 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/27 18:58:00 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    draw_line(int x1, int y1, int x2, int y2)
{
	int dx;
	int dy;
	int flag;
	int error;
	int ystep;

	flag = abs(y2 - y1) > abs(x2 - x1);
	if (flag)
	{
		swap(&x1, &y1);
		swap(&x2, &y2);
	}
	if (x1 > x2)
	{
		swap(&x1, &x2);
		swap(&y1, &y2);
	}
	dx = x2 - x1;
	dy = abs(y2 - y1);
	error = dx / 2;
	ystep = (y1 < y2) ? 1 : -1;
	while(x1 != x2)
	{
		ft_printf("[%d, %d]\n", flag ? y1 : x1, flag ? x1 : y1);
		error -= dy;
		if (error < 0)
		{
			y1 += ystep;
			error +=dx;
		}
		++x1;
	}
	ft_printf("[%d, %d]\n", flag ? y1 : x1, flag ? x1 : y1);
}
