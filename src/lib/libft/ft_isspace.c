/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:42:36 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/16 16:42:39 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_isspace(int c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	else
		return (0);
}
