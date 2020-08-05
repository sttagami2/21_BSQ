/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_is_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 22:52:29 by bshang            #+#    #+#             */
/*   Updated: 2020/08/04 12:09:26 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		num_obstacles_in_square(int *obs, t_square *sq)
{
	int		res;

	res = obs[idx(sq->descr->ncols, sq->i + sq->sz - 1,
	sq->j + sq->sz - 1)];
	if (sq->i > 0)
		res -= obs[idx(sq->descr->ncols, sq->i - 1, sq->j + sq->sz - 1)];
	if (sq->j > 0)
		res -= obs[idx(sq->descr->ncols, sq->i + sq->sz - 1, sq->j - 1)];
	if (sq->i > 0 && sq->j > 0)
		res += obs[idx(sq->descr->ncols, sq->i - 1, sq->j - 1)];
	return (res);
}

int				ft_is_valid_square(int *obs, t_descriptor *descr,
				t_square *s_cand)
{
	int		res;

	res = 1;
	res = res && num_obstacles_in_square(obs, s_cand) == 0;
	res = res && s_cand->j < descr->ncols - s_cand->sz + 1;
	res = res && s_cand->i < descr->nrows - s_cand->sz + 1;
	return (res);
}
