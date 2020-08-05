/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 22:56:45 by bshang            #+#    #+#             */
/*   Updated: 2020/08/04 12:09:29 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	int_to_char(int v, t_descriptor *descr)
{
	if (v == 0)
		return (descr->empty);
	else if (v == 1)
		return (descr->obstacle);
	else if (v == 2)
		return (descr->full);
	else
		return ('\0');
}

int		ft_atoi(char *str)
{
	int		negat;
	int		i;
	int		x;

	negat = 1;
	i = 0;
	x = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' && str[i + 1] >= '0' && str[i + 1] <= '9')
		i++;
	if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
	{
		i++;
		negat = -1;
	}
	while (str[i] >= 48 && str[i] <= 57 && str[i] != '\0')
	{
		x = x * 10 + (str[i] - 48);
		i++;
	}
	return (x * negat);
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}
