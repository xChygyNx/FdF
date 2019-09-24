/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:51:07 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/24 22:27:06 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libftprintf.h"
# include "mlx.h"
# include <math.h>

# define WIN_HEIGHT 1000
# define WIN_WIDTH 1000

# define USAGE  100

typedef struct	s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	double		d;

}				t_fdf;

void			ft_exit(void *fdf, int err);

#endif
