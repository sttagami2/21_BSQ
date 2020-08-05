/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 22:51:44 by bshang            #+#    #+#             */
/*   Updated: 2020/08/04 12:09:19 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		fill_m_from_string(char *str, int *m, t_descriptor *descr)
{
	int		j;

	j = 0;
	while (j < descr->ncols)
	{
		if (str[j] == descr->empty)
			m[j++] = 0;
		else if (str[j] == descr->obstacle)
			m[j++] = 1;
		else
			return (ERR);
	}
	if (j != descr->ncols || str[j] != '\n')
		return (ERR);
	else
		return (j);
}

int		*read_int_matrix(int fd, t_descriptor *descr)
{
	int		i;
	char	*str_buf;
	int		*m;
	int		read_chars;

	i = 0;
	m = 0;
	str_buf = (char *)malloc(sizeof(char) * MAX_STR_LENGTH);
	while (i < descr->nrows && (read_chars = read_line(fd, str_buf)) > 0)
	{
		if (descr->ncols == -1)
		{
			descr->ncols = read_chars - 1;
			m = (int *)malloc(sizeof(int) * descr->nrows * descr->ncols);
		}
		if (read_chars - 1 != descr->ncols || (fill_m_from_string(str_buf,
		m + (descr->ncols) * i, descr) == ERR))
			return (NOLL);
		i++;
	}
	if (descr->ncols < 1 || read_line(fd, str_buf) > 0 || i != descr->nrows)
		return (NOLL);
	free(str_buf);
	return (m);
}
