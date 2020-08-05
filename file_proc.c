/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 22:57:44 by bshang            #+#    #+#             */
/*   Updated: 2020/08/04 12:09:02 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void		ft_print_map_error(void)
{
	write(1, "map error\n", 10);
}

void	clear_line(char *line)
{
	line[0] = '\0';
}

int		read_line(int fd, char *dst)
{
	int		length;
	char	buf;

	buf = -1;
	length = 0;
	clear_line(dst);
	while (buf != '\n' && read(fd, &buf, 1) > 0)
		dst[length++] = buf;
	if (length > 0 && buf != '\n')
		return (ERR);
	dst[length] = '\0';
	return (length);
}

t_descriptor	*read_descriptor(int fd)
{
	t_descriptor	*descr;
	char			*line;
	int				len;
	int				cur;

	line = (char *)malloc(sizeof(char) * MAX_DESCR_LENGTH + 1);
	len = read_line(fd, line);
	cur = len - 2;
	descr = (t_descriptor*)malloc(sizeof(t_descriptor));
	descr->full = line[cur--];
	descr->obstacle = line[cur--];
	descr->empty = line[cur];
	line[cur] = '\0';
	descr->nrows = ft_atoi(line);
	descr->ncols = -1;
	free(line);
	return (descr);
}
