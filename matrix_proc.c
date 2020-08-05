/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 22:52:09 by bshang            #+#    #+#             */
/*   Updated: 2020/08/04 12:09:16 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*array_to_map(int *m, t_descriptor *descr)
{
	char	*str;
	int		i;
	int		j;
	int		k_str;

	i = 0;
	k_str = 0;
	str = (char*)malloc(sizeof(char) * (descr->nrows * (descr->ncols + 1) + 1));
	while (i < descr->nrows)
	{
		j = 0;
		while (j < descr->ncols)
		{
			str[k_str++] = int_to_char(m[i * descr->ncols + j], descr);
			j++;
		}
		str[k_str++] = '\n';
		i++;
	}
	str[k_str] = '\0';
	return (str);
}

int		idx(int n, int i, int j)
{
	return (i * n + j);
}

void	count_obstacles_up_left(int *m, t_descriptor *desc)
{
	int		i;
	int		j;

	i = 0;
	while (i < desc->nrows)
	{
		j = 0;
		while (j < desc->ncols)
		{
			if (i > 0)
				m[idx(desc->ncols, i, j)] += m[idx(desc->ncols, i - 1, j)];
			if (j > 0)
				m[idx(desc->ncols, i, j)] += m[idx(desc->ncols, i, j - 1)];
			if (i > 0 && j > 0)
				m[idx(desc->ncols, i, j)] -= m[idx(desc->ncols, i - 1, j - 1)];
			j++;
		}
		i++;
	}
}

int		*copy_matrix(int *m, t_descriptor *desc)
{
	int		*r;
	int		i;

	i = 0;
	r = (int*)malloc(sizeof(int) * desc->nrows * desc->ncols + 1);
	while (i < desc->nrows * desc->ncols)
	{
		r[i] = m[i];
		i++;
	}
	return (r);
}

void			fill_max_square(int *m, t_descriptor *descr)
{
	char		*field;
	int			*obs_agg;
	t_square	*max_square;

	obs_agg = copy_matrix(m, descr);
	count_obstacles_up_left(obs_agg, descr);
	max_square = find_max_square(obs_agg, descr);
	if (max_square->sz > 0)
		paint_square(m, max_square);
	free(max_square);
	if (obs_agg != NOLL)
		free(obs_agg);
	field = array_to_map(m, descr);
	ft_putstr(field);
	if (field != NOLL)
		free(field);
}
