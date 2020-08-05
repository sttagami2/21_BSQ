/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_find_max.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 22:52:50 by bshang            #+#    #+#             */
/*   Updated: 2020/08/04 12:09:22 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void			paint_square(int *m, t_square *s)
{
	int		i;
	int		j;

	i = 0;
	while (i < s->sz)
	{
		j = 0;
		while (j < s->sz)
		{
			if (m[idx(s->descr->ncols, s->i + i, s->j + j)] != 0)
				write(1, "Too bad, obstacle\n", 19);
			m[idx(s->descr->ncols, s->i + i, s->j + j)] = 2;
			j++;
		}
		i++;
	}
}

void		set_square(t_square *src, t_square *dst)
{
	dst->i = src->i;
	dst->j = src->j;
	dst->sz = src->sz;
}

t_square	*init_square(t_descriptor *descr)
{
	t_square	*s;

	s = (t_square*)malloc(sizeof(t_square));
	s->descr = descr;
	s->i = 0;
	s->j = 0;
	s->sz = 0;
	return (s);
}

void	init_find_max_square(t_descriptor *descr,
		t_square **max_square, t_square **s_cand)
{
	(*max_square) = init_square(descr);
	(*s_cand) = init_square(descr);
	(*s_cand)->sz = 1;
}

t_square		*find_max_square(int *obs, t_descriptor *descr)
{
	t_square		*max_square;
	t_square		*s_cand;

	init_find_max_square(descr, &max_square, &s_cand);
	s_cand->i = 0;
	while (s_cand->i < descr->nrows - s_cand->sz + 1 && max_square->sz !=
	s_cand->sz)
	{
		s_cand->j = 0;
		while (s_cand->j < descr->ncols - s_cand->sz + 1 && max_square->sz
		!= s_cand->sz)
		{
			while (ft_is_valid_square(obs, descr, s_cand))
			{
				set_square(s_cand, max_square);
				s_cand->sz++;
			}
			s_cand->j++;
		}
		s_cand->i++;
	}
	s_cand->sz++;
	free(s_cand);
	return (max_square);
}
