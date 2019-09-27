/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 18:39:28 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/27 19:47:37 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_exit(t_fdf **fdf, int err)
{
	free_fdf(fdf);
	if (err == USAGE)
		ft_fprintf(2, "USAGE: ./fdf [valid_map]\n");
	else if (err == MALLOC_FAILURE)
		ft_fprintf(2, "Error: malloc failure\n");
	else if (err == LINE_LENGTHS)
		ft_fprintf(2, "Error: different line lengths\n");
	else
		perror("Error: ");
	exit(err);
}
