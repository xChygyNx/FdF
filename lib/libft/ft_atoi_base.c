/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:36:05 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/12 12:34:51 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_base(char *s, int base)
{
	int		res;

	res = 0;
	while ((*s > 8 && *s < 14) || *s == 32)
		++s;
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			res = res * base + (*s - '0');
		else if (*s >= 'a' && *s <= 'f')
			res = res * base + (*s - 'a' + 10);
		else if (*s >= 'A' && *s <= 'F')
			res = res * base + (*s - 'A' + 10);
		else
			return (-1);
		s++;
	}
	return (res);
}
