/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:14:48 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/06 22:19:05 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float		**multiplication(float **cur, float **matrix)
{
	float	**new_matrix;
	int		i;
	int		j;
	int		k;

	if (!(new_matrix = create_matrix()))
		return (NULL);
	k = 0;
	while (k < 3)
	{
		i = 0;
		while (i < 3)
		{
			j = 0;
			while (j < 3)
			{
				new_matrix[k][i] += cur[k][j] * matrix[j][i];
				++j;
			}
			++i;
		}
		++k;
	}
	free_matrix(&cur);
	return (new_matrix);
}

void		print_matrix(float **matrix)
{
	int i;
	int j;

	i = 0;
	while (i < 3)
	{
		ft_printf("[ ");
		j = 0;
		while (j < 3)
		{
			ft_printf("%.3f", matrix[i][j]);
			++j;
			if (j != 3)
				ft_printf(", ");
		}
		ft_printf(" ]\n");
		++i;
	}
	ft_printf("\n");
}

void		change_matrix(t_fdf *fdf, float alpha, char axis)
{
	float	**temp;

	if (axis == AXIS_X)
		temp = matrix_x(alpha);
	else if (axis == AXIS_Y)
		temp = matrix_y(alpha);
	else if (axis == AXIS_Z)
		temp = matrix_z(alpha);
	if (!temp)
		ft_exit(&fdf, MALLOC_FAILURE);
	if (!(fdf->view->matrix = multiplication(fdf->view->matrix, temp)))
	{
		free_matrix(&temp);
		ft_exit(&fdf, MALLOC_FAILURE);
	}
	free_matrix(&temp);
}

void		free_matrix(float ***matrix_to_del)
{
	float	**matrix;
	int		i;

	if (matrix_to_del)
	{
		matrix = *matrix_to_del;
		i = 0;
		while (i < 3)
		{
			free(matrix[i]);
			++i;
		}
		free(matrix);
		*matrix_to_del = NULL;
	}
}