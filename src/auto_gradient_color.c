/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_gradient_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:27:41 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/11 21:08:56 by pcredibl         ###   ########.fr       */
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
	else if (style == 0)
		red = 0xFF;
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
	else if (style == 0)
		green = 0xFF;
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
	else if (style == 0)
		blue = 0xFF;
	return (blue);
}