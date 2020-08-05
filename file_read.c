/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 22:57:44 by bshang            #+#    #+#             */
/*   Updated: 2020/08/04 12:09:09 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		open_file(const char *fname)
{
	int		fd;

	fd = 0;
	if (fname != NOLL)
		fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (ERR);
	return (fd);
}

void	close_file(int fd)
{
	if (fd != -1)
		close(fd);
}

void	finalize(int fd, t_descriptor *desc, int *m)
{
	close_file(fd);
	free(desc);
	if (m != NOLL)
		free(m);
}

void	process_file(char *fname)
{
	int				fd;
	int				*m;
	t_descriptor	*descr;

	fd = open_file(fname);
	if (fd == ERR)
	{
		ft_print_map_error();
		return ;
	}
	descr = read_descriptor(fd);
	if (descr->nrows == -1)
	{
		ft_print_map_error();
		return ;
	}
	m = read_int_matrix(fd, descr);
	if (m == NOLL)
	{
		ft_print_map_error();
		finalize(fd, descr, m);
		return ;
	}
	fill_max_square(m, descr);
	finalize(fd, descr, m);
}

int		main(int argc, char *argv[])
{
	int		i;

	i = 1;
	if (argc == 1)
		process_file(NOLL);
	else
	{
		while (argv[i] != 0)
		{
			process_file(argv[i]);
			if (i != argc - 1)
				ft_putstr("\n");
			i++;
		}
	}
	return (0);
}
