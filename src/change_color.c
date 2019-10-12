/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:17:21 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/12 11:31:08 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static unsigned int	mix_colors(t_fdf *fdf, t_vector *src)
{
	t_color color;
	
	color.t_rgb.red = mix_red(fdf, src);
	color.t_rgb.green = mix_green(fdf, src);
	color.t_rgb.blue = mix_blue(fdf, src);
	return (color.color);
}

static unsigned int	gradient_colors(t_fdf *fdf, t_vector *src)
{
	t_color color;

	color.t_rgb.red = gradient_red(fdf, src);
	color.t_rgb.green = gradient_green(fdf, src);
	color.t_rgb.blue = gradient_blue(fdf, src);
	return(color.color);
}

unsigned int		change_color(t_fdf *fdf, t_vector *src)
{
	unsigned int	color;
	
	if (fdf->colorful)
		color = mix_colors(fdf, src);
	else
		color = gradient_colors(fdf, src);

	return (color);
}
