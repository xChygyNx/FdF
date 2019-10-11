/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zbuffer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:35:46 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/11 19:13:00 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		free_zbuffer(short ***zbuffer)
{
	int		i;
	short	**temp;

	if (zbuffer && *zbuffer)
	{
		i = 0;
		temp = *zbuffer;
		while (i < IMG_HEIGHT)
		{
			free(temp[i]);
			++i;
		}
		free(*zbuffer);
		*zbuffer = NULL;
	}
}

short		**create_zbuffer(void)
{
	int		i;
	int		j;
	short	**zbuffer;

	i = 0;
	if (!(zbuffer = (short**)malloc(sizeof(short*) * IMG_HEIGHT)))
		return (NULL);
	while (i < IMG_HEIGHT)
	{
		j = 0;
		while (j < IMG_WIDTH)
		{
			if (!(zbuffer[i] = (short*)malloc(sizeof(short) * IMG_WIDTH)))
			{
				free_zbuffer(&zbuffer);
				return (NULL);
			}
			++j;
		}
		++i;
	}
	return (zbuffer);
}

void		drop_zbuffer(short **zbuffer)
{
	int		i;
	int		j;

	i = 0;
	while (i < IMG_HEIGHT)
	{
		j = 0;
		while (j < IMG_WIDTH)
		{
			zbuffer[i][j] = SHORT_MIN;
			++j;
		}
		++i;
	}
}

void		print_z(short **zbuffer)
{
	int i;
	int j;

	i = 0;
	while (i < IMG_HEIGHT)
	{
		j = 0;
		while (j < IMG_WIDTH)
		{
			if (zbuffer[i][j] == SHORT_MIN || zbuffer[i][j] == 0)
				ft_printf("0 ");
			else
				ft_printf("{red}%d{eoc} ", zbuffer[i][j]);
			++j;
		}
		ft_printf("\n");
		++i;
	}
}
