/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_gradient_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:27:41 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/11 13:18:23 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned char	gradient_red(int min_h, int max_h, int cur_h, char style)
{
	unsigned char	red;
	float			coef;

	coef = (float)(cur_h - min_h) / (max_h - min_h);
	if (style == 1 || style == 4 || style == 5)
		red = 0xFF;
	else if (style == 2 || style == 3 || style == 6)
		red = (int) 255 * coef;
	else if (style == 7)
		red = (int) 255 * coef;
	//ft_printf (" = %d, 255 * coef = %.0f, coef = %.0f\n", red, 255 * coef, coef);
	//ft_printf ("red = %d ", red);
	return (red);
}

unsigned char	gradient_green(int min_h, int max_h, int cur_h, char style)
{
	unsigned char	green;
	float			coef;

	coef = (float)(cur_h - min_h) / (max_h - min_h);
	if (style == 2 || style == 5 || style == 6)
		green = 0xFF;
	else if (style == 1 || style == 3 || style == 4)
		green = (int) 255 * coef;
	else if (style == 7)
		green = (int) 255 * coef;
	//ft_printf ("green = %d ", green);
	return (green);
}

unsigned char	gradient_blue(int min_h, int max_h, int cur_h, char style)
{
	unsigned char	blue;
	float			coef;

	coef = (float)(cur_h - min_h) / (max_h - min_h);
	if (style == 3 || style == 4 || style == 6)
		blue = 0xFF;
	else if (style == 1 || style == 2 || style == 5)
		blue = (int) 255 * coef;
	else if (style == 7)
		blue = (int) 255 * coef;
	//ft_printf ("blue = %d, 255 * coef = %d, coef = %f\n", blue, 255 * coef, coef);
	return (blue);
}