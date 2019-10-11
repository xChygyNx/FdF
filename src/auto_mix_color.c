/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_mix_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:28:28 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/11 12:44:09 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned char	mix_red(int i, int j, t_fdf *fdf, char style)
{
	unsigned char	red;
	
	if (style == 0)
		red = fdf->map[i][j].c.t_rgb.red;		
	else if (style == 1)
		red = fdf->map[i][j].c.t_rgb.blue;		
	else if (style == 2)
		red = fdf->map[i][j].c.t_rgb.green;		
	else if (style == 3)
		red = 255 - fdf->map[i][j].c.t_rgb.red;				
	else if (style == 4)
		red = fdf->map[i][j].c.t_rgb.red * 2;
	else if (style == 5)
		red = fdf->map[i][j].c.t_rgb.red / 2;
	return (red);		
}

unsigned char	mix_green(int i, int j, t_fdf *fdf, char style)
{
	unsigned char	green;
	
	if (style == 0)
		green = fdf->map[i][j].c.t_rgb.green;		
	else if (style == 1)
		green = fdf->map[i][j].c.t_rgb.red;		
	else if (style == 2)
		green = fdf->map[i][j].c.t_rgb.blue;		
	else if (style == 3)
		green = 255 - fdf->map[i][j].c.t_rgb.green;			
	else if (style == 4)
		green = fdf->map[i][j].c.t_rgb.green * 2;
	else if (style == 5)
		green = fdf->map[i][j].c.t_rgb.green / 2;
	return (green);		
}

unsigned char	mix_blue(int i, int j, t_fdf *fdf, char style)
{
	unsigned char	blue;
	
	if (style == 0)
		blue = fdf->map[i][j].c.t_rgb.blue;		
	else if (style == 1)
		blue = fdf->map[i][j].c.t_rgb.green;		
	else if (style == 2)
		blue = fdf->map[i][j].c.t_rgb.red;		
	else if (style == 3)
		blue = 255 - fdf->map[i][j].c.t_rgb.blue;				
	else if (style == 4)
		blue = fdf->map[i][j].c.t_rgb.blue * 2;
	else if (style == 5)
		blue = fdf->map[i][j].c.t_rgb.blue * 2;
	return (blue);		
}