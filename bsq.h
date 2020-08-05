/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 10:42:07 by bshang            #+#    #+#             */
/*   Updated: 2020/08/04 12:13:44 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define MAX_DESCR_LENGTH 64
# define MAX_STR_LENGTH 65536
# define ERR -1
# define NOLL 0

typedef struct			s_descriptor
{
	int					ncols;
	int					nrows;
	char				empty;
	char				obstacle;
	char				full;
}						t_descriptor;

typedef struct			s_square
{
	struct s_descriptor	*descr;
	int					i;
	int					j;
	int					sz;
}						t_square;

t_square				*init_square(t_descriptor *descr);
void					set_square(t_square *src, t_square *dst);
void					ft_print_map_error(void);
void					ft_putchar(char c);
void					ft_putstr(char *str);
int						ft_atoi(char *str);
int						open_file(const char *fname);
void					close_file(int fd);
void					clear_line(char *line);
int						read_line(int fd, char *dst);
void					finalize(int fd, t_descriptor *desc, int *m);
int						fill_m_from_string(char *str, int *m,
						t_descriptor *descr);
int						*read_int_matrix(int fd, t_descriptor *descr);
char					int_to_char(int v, t_descriptor *descr);
char					*array_to_map(int *m, t_descriptor *descr);
int						idx(int n, int i, int j);
void					count_obstacles_up_left(int *m, t_descriptor *desc);
int						*copy_matrix(int *m, t_descriptor *desc);
int						num_obstacles_in_square(int *obs, t_square *sq);
void					init_find_max_square(t_descriptor *descr,
						t_square **max_square, t_square **s_cand);
int						ft_is_valid_square(int *obs, t_descriptor *descr,
						t_square *s_cand);
t_square				*find_max_square(int *obs, t_descriptor *descr);
void					paint_square(int *m, t_square *s);
void					fill_max_square(int *m, t_descriptor *descr);
t_descriptor			*read_descriptor(int fd);
void					process_file(char *fname);
int						main(int argc, char *argv[]);

#endif
